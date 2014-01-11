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
    this->_running = false;
    this->_settingVals = false;
    std::vector< Cell > temp;
    temp.clear();
    _cells.clear();
    _initialCells.clear();
    for (int i = 0; i < gridSize; i++) {
        _cells.push_back(temp);
        _initialCells.push_back(temp);
        for (int j = 0; j < gridSize; j++) {
            Cell newCell(i,j,cellSize);
            _cells[i].push_back( newCell );
            _initialCells[i].push_back( newCell );
        }
    }
    // listen to mouse events
    ofAddListener(ofEvents().mousePressed, this, &GameBoard::_mousePressed);
    ofAddListener(ofEvents().mouseDragged, this, &GameBoard::_mouseDragged);
    ofAddListener(ofEvents().mouseReleased, this, &GameBoard::_mouseReleased);
}

GameBoard::GameBoard() {
    // Should never be called
}

GameBoard::~GameBoard() {
    // Doesn't need to do anything currently
}

void GameBoard::_mousePressed(ofMouseEventArgs& e) {
    // mouse pressed event
    if ( !this->_isOnGameBoard(e.x, e.y) )
        return;
    this->_settingVals = true;
    this->_setCells(e);
}

void GameBoard::_mouseDragged(ofMouseEventArgs& e) {
    // mouse dragged event
    if ( !this->_isOnGameBoard(e.x, e.y) ) {
        this->_settingVals = false;
        return;
    }
    if (this->_settingVals) {
        this->_setCells(e);
    }
}

void GameBoard::_mouseReleased(ofMouseEventArgs& e) {
    // mouse released event
    this->_settingVals = false;
    this->_cellX = -1;
    this->_cellY = -1;
}

void GameBoard::_setCells(ofMouseEventArgs& e) {
    // if game is in setup stage
    if (! this->_running) {
        // get cell indices
        int x = this->_xPos;
        int y = this->_yPos;
        int i = (e.x - x)/this->_cellSize;
        int j = (e.y - y)/this->_cellSize;
        // check if on new cell in case of dragging
        if ( (i != this->_cellX) || (j != this->_cellY) ) {
            _constrain(i,j);
            _initialCells[i][j].living = !_initialCells[i][j].living;
            _cells[i][j].living = !_cells[i][j].living;
            this->_cellX = i;
            this->_cellY = j;
        }
    }
}

bool GameBoard::_isOnGameBoard(int mouseX, int mouseY) {
    int x = this->_xPos;
    int y = this->_yPos;
    int size = this->_gridSize*this->_cellSize;
    if (mouseX < x || mouseY < y)
        return false;
    else if (mouseX > x + size || mouseY > y + size)
        return false;
    return true;
}

void GameBoard::set(int i, int j, bool state) {
    _cells[i][j].living = state;
}

void GameBoard::update() {
    // updates the gameboard to the next state
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

void GameBoard::reset() {
    // GameBoard should save temporary file with cell data
    //  reset should load from that
    _cells = _initialCells;
    this->_running = false;
}

void GameBoard::clear() {
    // Clear gameboard - set all cell.living to false
    for (int i =0; i < this->_gridSize; i++) {
        for (int j = 0; j < this->_gridSize; j++) {
            _cells[i][j].living = false;
            _initialCells[i][j].living = false;
        }
    }
    this->_running = false;
}

void GameBoard::running(bool state) {
    this->_running = state;
}

bool GameBoard::running() {
    return this->_running;
}

void GameBoard::_constrain(int & i) {
    // constrain integer between 0 and gridSize
    i = (i < 0 ? 0 : i);
    i = (i >= this->_gridSize ? this->_gridSize-1 : i);
}

void GameBoard::_constrain(int& i, int& j) {
    // constrain indices to within gridSize
    this->_constrain(i);
    this->_constrain(j);
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