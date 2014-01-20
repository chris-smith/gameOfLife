//
//  guiGroup.cpp
//  gameOfLife
//
//  Created by Christopher Smith on 1/19/14.
//
//

#include "guiGroup.h"


GuiGroup::GuiGroup(){
    _xPos = 10;
    _yPos = 10;
    _setup();
}

GuiGroup::GuiGroup(int x, int y){
    _xPos = x;
    _yPos = y;
    _setup();
}

GuiGroup::~GuiGroup(){
    
}

void GuiGroup::_setup(){
    _bgColor = ofGetBackground();
    _textColor = ofColor(0,0,0);    // black default color
    _offset = 3;                    // 3pixel vertical offset between elements in group
}

// add gui elements to group
void GuiGroup::add(BaseGui* newGuiElement){
    // add element to list
    _elements.push_back(newGuiElement);
    
    _height = getHeight();
    _width = getWidth();
}