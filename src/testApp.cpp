#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(60, 120, 200);
    boardX = 50;
    boardY = 50;
    gridSize = 40;
    cellSize = 15;
    board = new GameBoard(boardX, boardY, gridSize, cellSize);
    gameSetup = true;
    lastUpdate = ofGetElapsedTimeMillis();
    updateTime = 800;
    mouseX = 0;
    mouseY = 0;
    play = false;
    highlight_bg = ofColor(80, 140, 220);
    highlight_fg = ofColor(220, 220, 240);
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetColor(200, 0, 200);
    if (!gameSetup){
        if ( ofGetElapsedTimeMillis() - lastUpdate > updateTime ) {
            lastUpdate = ofGetElapsedTimeMillis();
            if (play)
                board->update();
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(180,180,220);
    string instructions = "Click on squares to set the initial conditions for the game";
    string instr2 = "KeyCodes\n\tp --\tToggle Play/Pause\n\tr --\tReset Game";
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    ofDrawBitmapString(instructions, boardX, 20 + board->height() );
    ofDrawBitmapString(instr2, boardX, 40 + board->height() );
    string setup_string = "Game Setup";
    string running_string = "Game Running";
    if (gameSetup){
        ofDrawBitmapStringHighlight(setup_string, 10 + board->width(), boardY + 50, highlight_bg, highlight_fg);
        ofDrawBitmapString(running_string, 10 + board->width(), boardY + 70);
    }
    else{
        ofDrawBitmapString(setup_string, 10 + board->width(), boardY + 50);
        ofDrawBitmapStringHighlight(running_string, 10 + board->width(), boardY + 70, highlight_bg, highlight_fg);
    }
    board->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch(key) {
        case 'r':
            // reset game
            gameSetup = true;
            play = false;
            board->reset();
            lastUpdate = ofGetElapsedTimeMillis();
            break;
        case 'p':
            // toggle play/pause
            gameSetup = false;
            play = !play;
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
    if (gameSetup)
        board->mousePress(x,y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if (gameSetup)
        board->mousePress(x,y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if (gameSetup)
        board->mousePress(-1,-1);
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