//
//  cell.h
//  gameOfLife
//
//  Created by Christopher Smith on 1/8/14.
//
//

#ifndef __gameOfLife__cell__
#define __gameOfLife__cell__
#include "ofMain.h"

class Cell{
public:
    Cell(int, int, int);                // x,y placement in grid, cell size
    Cell();
    ~Cell();
    
    void set(bool);                     // sets cell to state
    
    bool living;                        // whether the cell is on or off at this iteration
    void update(int);                   // sets futureState from num Neighbors
    void draw(int, int);                // draws cell offset from origin

private:
    bool _futureState;
    int _xPos;
    int _yPos;
    int _cellSize;
};

#endif /* defined(__gameOfLife__cell__) */
