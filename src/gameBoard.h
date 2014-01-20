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
    GameBoard(int,int,int,int);             // x,y position, grid size, cell size
    ~GameBoard();
    
    void update();                          // tell each cell to update
    void draw();                            // tell each cell to draw itself
    void reset();                           // reset to initial configuration
    void clear();                           // clear game
    void resize(int, int);                  // resize gameboard -- takes grid size, cell size
    void savePattern(string);               // save minimum bounding rect around board pattern
    void save(string);                      // save game under name
    void saveTemp();                        // save current board for reset
    void load(string);                      // load specified game
    void running(bool);                     // sets board to setup, playing
    bool running();
    void set(int, int, bool);               // sets cell at position to state
    
    int height();                           // get height of game board
    int width();                            // get width of game board
    
private:
    GameBoard();
    int _getCellNeighbors(int, int);        // get living neighbors of the cell
    int _value(int, int);
    void _constrain(int&);
    void _constrain(int&, int&);            // constrain indices to within gridSize
    bool _isOnGameBoard(int,int);
    void _setCells(ofMouseEventArgs&);
    string _boardToText();                  // convert gameboard to data
    void _setBoardFromString(string);       // convert data to GameBoard
    
    // events
    void _mousePressed(ofMouseEventArgs&);
    void _mouseDragged(ofMouseEventArgs&);
    void _mouseReleased(ofMouseEventArgs&);
    
    std::vector< std::vector< Cell > > _cells;
    string _tempLoc;                        //  location to save temp data -- board for reset
    int _xPos;
    int _yPos;
    int _cellX;                             //  tracks last cell updated during setup
    int _cellY;                             //  tracks last cell updated during setup
    int _gridSize;
    int _cellSize;
    bool _running;
    bool _settingVals;
};

#endif /* defined(__gameOfLife__gameBoard__) */
