#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(60, 120, 200);
    boardX = 50;
    boardY = 50;
    gridSize = 100;
    board = new GameBoard(boardX, boardY, 50, 10);
    gameSetup = true;
    lastUpdate = ofGetElapsedTimeMillis();
    updateTime = 800;
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetColor(200, 0, 200);
    if (!gameSetup){
        if ( ofGetElapsedTimeMillis() - lastUpdate > updateTime )
            board->update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(160,160,200);
    string instructions = "Click on squares to set the initial conditions for the game";
    string instr2 = "KeyCodes\n\tg --\tStart game\n\tr --\tReset Game";
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    ofDrawBitmapString(instructions, 20, 20 + board->height() );
    ofDrawBitmapString(instr2, 20, 40 + board->height() );
    board->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch(key) {
        case 'g':
            // start game
            gameSetup = false;
            break;
        case 'r':
            //reset game
            gameSetup = true;
            board->reset();
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
    board->mousePress(x,y);
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