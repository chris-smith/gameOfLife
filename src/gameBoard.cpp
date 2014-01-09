//
//  gameBoard.cpp
//  gameOfLife
//
//  Created by Christopher Smith on 1/8/14.
//
//

#include "gameBoard.h"

GameBoard::GameBoard(int x,int y,int gridSize, int cellSize) {
    this->_xPos = x;
    this->_yPos = y;
    this->_gridSize = gridSize;
    this->_cellSize = cellSize;
    std::cout<<x<<" "<<y<<" "<<gridSize<<"\n";
    std::vector< Cell > temp;
    temp.clear();
    _cells.clear();
    for (int i = 0; i < gridSize; i++) {
        _cells.push_back(temp);
        for (int j = 0; j < gridSize; j++) {
            //std::cout<< "push back at "<<i<<" "<<j<<"\n";
            Cell newCell(i,j,cellSize);
            _cells[i].push_back( newCell );
        }
    }
    std::cout<<"gameboard initialized";
}

GameBoard::~GameBoard() {
    
}
void GameBoard::set(int i, int j, bool state) {
    _cells[i][j].living = state;
}


GameBoard::GameBoard() {
    
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
    int x = this->_xPos;
    int y = this->_yPos;
    int size = this->_gridSize*this->_cellSize;
    if (mouseX < x || mouseY < y)
        return;
    else if (mouseX > x + size || mouseY > y + size)
        return;
    else {
        int i = (mouseX - x)/this->_cellSize;
        int j = (mouseY - y)/this->_cellSize;
        _cells[i][j].living = !_cells[i][j].living;
    }
}

void GameBoard::reset() {
    for (int i =0; i < this->_gridSize; i++) {
        for (int j = 0; j < this->_gridSize; j++) {
            _cells[i][j].living = false;
        }
    }
}

int GameBoard::_getCellNeighbors(int i, int j) {
    int num = 0;
    int x,y;
    for (int i = 0; i < 3; i++) {
        for (int j =0; j < 3; j++) {
            if (i == 2 && j == 2)
                ;//skip this
            else {
                num += _value(i,j);
            }
        }
    }
}
        
int GameBoard::_value(int i, int j) {
    // return 1 if cell is living
    if (i <= 0)
        return 0;
    else if (i >= this->_gridSize)
        return 0;
    else if (j <= 0 )
        return 0;
    else if (j >= this->_gridSize)
        return 0;
    else
        return ( this->_cells[i][j].living ? 1: 0 );
}

int GameBoard::height() {
    return this->_yPos+this->_gridSize*this->_cellSize;
}

/*std::vector< std::vector< Cell > > _cells;
int _xPos;
int _yPos;
int _gridSize;*/