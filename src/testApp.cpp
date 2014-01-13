#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(60, 120, 200, 200);
    boardX = 50;
    boardY = 50;
    gridSize = 50;
    cellSize = 10;
    lastUpdate = ofGetElapsedTimeMillis();
    mouseX = 0;
    mouseY = 0;
    play = false;
    highlight_bg = ofColor(80, 140, 220);
    highlight_fg = ofColor(220, 220, 240);
    
    // create Game Board
    board = new GameBoard(boardX, boardY, gridSize, cellSize);
    
    // Setup for slider
    updateTime.setBackgroundColor( ofColor(100,160, 210) );
    updateTime.setFillColor( ofColor(130,190,240) );
    updateTime.setPosition( 7 + board->width(), boardY + 120 );
    updateTime.setSize( ofGetWidth() - (16 + board->width()), 15 );
    updateTime.setRange( 20, 800 );
    updateTime.setTitle("Update Rate");
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetColor(200, 0, 200);
    if ( board->running() ){
        // if game is live
        if ( ofGetElapsedTimeMillis() - lastUpdate > updateTime ) {
            // if we need to update the board
            lastUpdate = ofGetElapsedTimeMillis();
            
            // check if playing, or paused
            if (play)
                board->update();
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(180,180,220);
    string instructions = "Click on squares to set the initial conditions for the game";
    string instr2 = "KeyCodes\n\tp --\tToggle Play/Pause\n\tr --\tReset Game\n\tc --\tClear Game";
    // ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    ofDrawBitmapString(instructions, boardX, 20 + board->height() );
    ofDrawBitmapString(instr2, boardX, 40 + board->height() );
    string setup_string = "Game Setup";
    string running_string = "Game Running";
    if ( !board->running() ){
        ofDrawBitmapStringHighlight(setup_string, 10 + board->width(), boardY + 50, highlight_bg, highlight_fg);
        ofDrawBitmapString(running_string, 10 + board->width(), boardY + 70);
    }
    else{
        ofDrawBitmapString(setup_string, 10 + board->width(), boardY + 50);
        ofDrawBitmapStringHighlight(running_string, 10 + board->width(), boardY + 70, highlight_bg, highlight_fg);
    }
    board->draw();
    updateTime.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch(key) {
        case 'r':
            // reset game
            board->running(false);
            play = false;
            board->reset();
            lastUpdate = ofGetElapsedTimeMillis();
            break;
        case 'p':
            // toggle play/pause, save temporary save
            board->running(true);
            board->saveTemp();
            play = !play;
            break;
        case 'c':
            // clear game
            board->running(false);
            play = false;
            board->clear();
            lastUpdate = ofGetElapsedTimeMillis();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}