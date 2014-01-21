//
//  guiGroup.cpp
//  gameOfLife
//
//  Created by Christopher Smith on 1/19/14.
//
//

#include "guiGroup.h"


GuiGroup::GuiGroup(){
    this->_xPos = 10;
    this->_yPos = 10;
    this->_setup();
}

GuiGroup::GuiGroup(int x, int y){
    this->_xPos = x;
    this->_yPos = y;
    this->_setup();
}

GuiGroup::~GuiGroup(){
    
}

void GuiGroup::_setup(){
    this->_bgColor = ofGetBackground();
    this->_textColor = ofColor(0,0,0);    // black default color
    this->_offset = 0;                    // vertical offset between elements in group
    this->_title = "";
    this->_xTitle = 0;
    this->_yTitle = -2;
}

// add gui elements to group
void GuiGroup::add(BaseGui* newGuiElement){
    // add element to list
    this->_elements.push_back(newGuiElement);
    this->setPosition(this->_xPos, this->_yPos);
}

void GuiGroup::setPosition(int x,int y){
    this->_xPos = x;
    this->_yPos = y;
    int height = 0;
    for(int i = 0; i < _elements.size(); i++) {
        _elements[i]->setPosition( x, y+height+this->_offset );
        height += _elements[i]->getHeight();
        if ( _elements[i]->getTitle() != "" )
            height += 15;
    }
}

void GuiGroup::setPosition(ofPoint pt){
    this->setPosition(pt.x, pt.y);
}

void GuiGroup::setOffset(int offset){
    this->_offset = offset;
}

void GuiGroup::setTitle(string title){
    this->_title = title;
}

void GuiGroup::setTitlePosition(int x, int y){
    this->_xTitle = x;
    this->_yTitle = y;
}

void GuiGroup::setTitlePosition(ofPoint pt){
    this->setTitlePosition(pt.x, pt.y);
}

void GuiGroup::setBackgroundColor(ofColor color){
    this->_bgColor = color;
}

void GuiGroup::setBackgroundColorElements(ofColor color){
    for(int i = 0; i < _elements.size(); i++)
        _elements[i]->setBackgroundColor(color);
}

void GuiGroup::setFillColor(ofColor color){
    this->_fillColor = color;
}
    
void GuiGroup::setFillColorElements(ofColor color){
    for(int i = 0; i < _elements.size(); i++)
        _elements[i]->setFillColor(color);
}

void GuiGroup::setTextColor(ofColor color){
    this->_textColor = color;
}
    
void GuiGroup::setTextColorElements(ofColor color){
    for(int i = 0; i < _elements.size(); i++)
        _elements[i]->setTextColor(color);
}

ofPoint GuiGroup::getPosition() const{
    return ofPoint(this->_xPos, this->_yPos);
}

int GuiGroup::getHeight() const{
    int height = 0;
    for(int i = 0; i < _elements.size(); i++) {
        height += _elements[i]->getHeight() + this->_offset;
    }
    return height;

}

int GuiGroup::getWidth() const{
    int width = 0;
    int maxWidth = 0;
    for(int i = 0; i < _elements.size(); i++) {
        width = _elements[i]->getWidth();
        if ( width > maxWidth )
            maxWidth = width;
    }
    return maxWidth;
}

string GuiGroup::getTitle() const{
    return this->_title;
}

ofPoint GuiGroup::getTitlePosition() const{
    return ofPoint(this->_xTitle, this->_yTitle);
}

ofColor GuiGroup::getBackgroundColor() const{
    return this->_bgColor;
}

ofColor GuiGroup::getFillColor() const{
    return this->_fillColor;
}

ofColor GuiGroup::getTextColor() const{
    return this->_textColor;
}

int GuiGroup::getNumElements() const{
    return this->_elements.size();
}

void GuiGroup::draw() const{
    for(int i = 0; i < _elements.size(); i++)
        _elements[i]->draw();
    if (this->_title != "") {
        ofSetColor( this->_textColor );
        int x = this->_xPos + this->_xTitle;
        int y = this->_yPos + this->_yPos;
        ofDrawBitmapString( this->_title, x, y );
    }
}

