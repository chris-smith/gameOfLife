//
//  guiGroup.h
//  gameOfLife
//
//  Created by Christopher Smith on 1/19/14.
//
//      This class will let you set behavior/appearance
//      for groups of gui elements

#ifndef __gameOfLife__guiGroup__
#define __gameOfLife__guiGroup__

#include <iostream>
#include "ofMain.h"
#include "baseGui.h"


class GuiGroup{
public:
    GuiGroup();
    GuiGroup(int,int);
    ~GuiGroup();
    
    // add gui elements to group
    void add(BaseGui*);
    
    // setters
    void setPosition(int,int);
    void setPosition(ofPoint);
    void setTitle(string);
    void setTitlePosition(int,int);
    void setTitlePosition(ofPoint);
    void setBackgroundColor(ofColor);
    void setTextColor(ofColor);
    
    
    // getters
    ofPoint getPosition() const;
    int getHeight() const;
    int getWidth() const;
    string getTitle() const;
    void getTitlePosition(int,int);
    void getTitlePosition(ofPoint);
    ofColor getBackgroundColor() const;
    ofColor getTextColor() const;
    int getNumElements() const;
    
private:
    void _setup();
    
    vector<BaseGui*> _elements;
    
    ofColor _bgColor;
    ofColor _textColor;
    int _xPos;
    int _yPos;
    int _width;
    int _height;
    int _offset;
    string _title;
};

#endif /* defined(__gameOfLife__guiGroup__) */
