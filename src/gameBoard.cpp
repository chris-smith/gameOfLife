//
//  gameBoard.cpp
//  gameOfLife
//
//  Created by Christopher Smith on 1/8/14.
//
//

#include "gameBoard.h"

GameBoard::GameBoard(int x,int y,int gridSize, int cellSize) {
    // Constructor
    this->_xPos = x;
    this->_yPos = y;
    this->_gridSize = gridSize;
    this->_cellSize = cellSize;
    std::vector< Cell > temp;
    temp.clear();
    _cells.clear();
    for (int i = 0; i < gridSize; i++) {
        _cells.push_back(temp);
        for (int j = 0; j < gridSize; j++) {
            Cell newCell(i,j,cellSize);
            _cells[i].push_back( newCell );
        }
    }
}

GameBoard::~GameBoard() {
    // Doesn't need to do anything currently
}

void GameBoard::set(int i, int j, bool state) {
    _cells[i][j].living = state;
}


GameBoard::GameBoard() {
    // Should never be called
}

void GameBoard::update() {
    for (int i =0; i < this->_gridSize; i++) {
        for (int j = 0; j < this->_gridSize; j++) {
            _cells[i][j].update( this->_getCellNeighbors(i,j) );
        }
    }
}

void GameBoard::draw() {
    for (int i =0; i < this->_gridSize; i++) {
        for (int j = 0; j < this->_gridSize; j++) {
            _cells[i][j].draw(this->_xPos, this->_yPos);
        }
    }
}

void GameBoard::mousePress(int mouseX, int mouseY) {
    // toggle cell on/off during game setup
    int x = this->_xPos;
    int y = this->_yPos;
    int size = this->_gridSize*this->_cellSize;
    if (mouseX < 0) {
        // reset mouse up
        this->_cellX = -1;
        this->_cellY = -1;
    }
    // don't do anything if mouse is outside of gameboard
    if (mouseX < x || mouseY < y)
        return;
    else if (mouseX > x + size || mouseY > y + size)
        return;
    else {
        // get cell indices
        int i = (mouseX - x)/this->_cellSize;
        int j = (mouseY - y)/this->_cellSize;
        // check if on new cell in case of dragging
        if ( (i != this->_cellX) || (j != this->_cellY) ) {
            _cells[i][j].living = !_cells[i][j].living;
            this->_cellX = i;
            this->_cellY = j;
        }
    }
}

void GameBoard::reset() {
    // Reset gameboard - set all cell.living to false
    for (int i =0; i < this->_gridSize; i++) {
        for (int j = 0; j < this->_gridSize; j++) {
            _cells[i][j].living = false;
        }
    }
}

int GameBoard::_getCellNeighbors(int x, int y) {
    // Get Number of neighbors for cell at x,y in grid
    int num = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j=-1; j <= 1; j++) {
            if (i == 0 && j == 0)
                ;//skip -- this is the cell whose neighbor's we're looking at
            else {
                num += _value(x+i,y+j);
            }
        }
    }
    return num;
}
        
int GameBoard::_value(int i, int j) {
    // Robust method to check living state of cell at indices i,j
    // Returns 1 if cell exists && is living
    if (i < 0)
        return 0;
    else if (i >= this->_gridSize)
        return 0;
    else if (j < 0 )
        return 0;
    else if (j >= this->_gridSize)
        return 0;
    else
        return ( this->_cells[i][j].living ? 1: 0 );
}

int GameBoard::height() {
    // returns max Y position of gameboard
    return this->_yPos+this->_gridSize*this->_cellSize;
}

int GameBoard::width() {
    // returns max X position of gameboard
    return this->_xPos+this->_gridSize*this->_cellSize;
}