//
//  gameBoard.h
//  gameOfLife
//
//  Created by Christopher Smith on 1/8/14.
//
//

#ifndef __gameOfLife__gameBoard__
#define __gameOfLife__gameBoard__

#include "cell.h"
#include <iostream>

class GameBoard {
public:
    GameBoard(int,int,int,int);             // x,y position, grid size
    ~GameBoard();
    void set(int, int, bool);           // sets cell at position to state
    void update();                      // tell each cell to update
    void draw();                        // tell each cell to draw itself
    void mousePress(int, int);          // sets cell value if mouse press within gameboard
    void reset();
    
    int height();                       // get height of game board
    int width();                        // get width of game board
    
private:
    GameBoard();
    int _getCellNeighbors(int, int);    // get living neighbors of the cell
    int _value(int, int);
    
    std::vector< std::vector< Cell > > _cells;
    int _xPos;
    int _yPos;
    int _cellX;                         //  tracks last cell updated during setup
    int _cellY;                         //  tracks last cell updated during setup
    int _gridSize;
    int _cellSize;
};

#endif /* defined(__gameOfLife__gameBoard__) */
