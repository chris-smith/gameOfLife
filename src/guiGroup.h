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
    void draw() const;
    
    // setters
    void setPosition(int,int);
    void setPosition(ofPoint);
    void setTitle(string);
    void setTitlePosition(int,int);
    void setTitlePosition(ofPoint);
    void setOffset(int);
    void setBackgroundColor(ofColor);
    void setBackgroundColorElements(ofColor);
    void setFillColor(ofColor);
    void setFillColorElements(ofColor);
    void setTextColor(ofColor);
    void setTextColorElements(ofColor);
    
    
    // getters
    ofPoint getPosition() const;
    int getHeight() const;
    int getWidth() const;
    string getTitle() const;
    ofPoint getTitlePosition() const;
    ofColor getBackgroundColor() const;
    ofColor getFillColor() const;
    ofColor getTextColor() const;
    int getNumElements() const;
    
private:
    void _setup();
    
    vector<BaseGui*> _elements;
    
    ofColor _bgColor;
    ofColor _fillColor;
    ofColor _textColor;
    int _xPos;
    int _yPos;
    int _xTitle;
    int _yTitle;
    int _width;
    int _height;
    int _offset;
    string _title;
};

#endif /* defined(__gameOfLife__guiGroup__) */
