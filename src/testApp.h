#pragma once

#include "gameBoard.h"
//#include "ofMain.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        int mouseX, mouseY;
        GameBoard* board;
        int boardX;
        int boardY;
        int gridSize;
        int cellSize;
        bool gameSetup;     // true if game is being setup, not actively running
        unsigned long long lastUpdate;
        int updateTime;         // millis to update
        bool moved;     // tracks mouse movement for game setup
};
