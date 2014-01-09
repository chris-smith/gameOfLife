//
//  cell.cpp
//  gameOfLife
//
//  Created by Christopher Smith on 1/8/14.
//
//

#include "cell.h"

Cell::Cell(int _x, int _y, int _size) {
    this->_xPos = _x;
    this->_yPos = _y;
    this->_cellSize = _size;
    this->living = false;
    this->_futureState = false;
    //std::cout<<"new cell\n";
}

Cell::Cell(){
    this->_xPos = 0;
    this->_yPos = 0;
    this->_cellSize = 0;
    this->living = false;
    this->_futureState = false;
}

Cell::~Cell() {
    int x = 0;
}

void Cell::set(bool state) {
    // used when setting up gameboard
    this->living = state;
}

void Cell::update(int neighbors) {
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
}

void Cell::draw(int board_x, int board_y) {
    int x = board_x + this->_xPos*this->_cellSize;
    int y = board_y + this->_yPos*this->_cellSize;
    // draw border
    ofSetColor(200,200,240);
    ofRect( x, y, this->_cellSize, this->_cellSize);
    if ( this->living )
        ofSetColor(40,40,200);
    else
        ofSetColor(255,255,255);
    ofRect( x+1, y+1, this->_cellSize-1, this->_cellSize-1);
}