//
//  cell.cpp
//  gameOfLife
//
//  Created by Christopher Smith on 1/8/14.
//
//

#include "cell.h"

Cell::Cell(int _x, int _y, int _size) {
    // Cell Constructor
    this->_xPos = _x;
    this->_yPos = _y;
    this->_cellSize = _size;
    this->living = false;
    this->_futureState = false;
    this->_needUpdate = false;
}

Cell::Cell(){
    // Cell Constructor -- Probably unnecessary
    this->_xPos = 0;
    this->_yPos = 0;
    this->_cellSize = 0;
    this->living = false;
    this->_futureState = false;
    this->_needUpdate = false;
}

Cell::~Cell() {
    // Doesn't need to do anything currently
}

void Cell::update(int neighbors) {
    // Updates cell's future state based on neighbors
    this->_futureState = false;
    if ( this->living ) {
        // currently living
        if ( (neighbors == 2) || (neighbors == 3) )
            this->_futureState = true;
    }
    else {
        //currently dead
        if ( neighbors == 3 )
            this->_futureState = true;
    }
    // Tells draw to update on next call
    // All cells update simultaneously
    this->_needUpdate = true;
}

void Cell::draw(int board_x, int board_y) {
    // Draws cell
    
    // Updates cell's state
    if (this->_needUpdate) {
        this->living = this->_futureState;
        this->_needUpdate = false;
    }
    int x = board_x + this->_xPos*this->_cellSize;
    int y = board_y + this->_yPos*this->_cellSize;
    
    // Draws border
    ofSetColor(200,200,240);
    ofRect( x, y, this->_cellSize, this->_cellSize);
    
    // Draws Cell
    if ( this->living )
        ofSetColor(40,40,200);
    else
        ofSetColor(255,255,255);
    ofRect( x+1, y+1, this->_cellSize-1, this->_cellSize-1);
}