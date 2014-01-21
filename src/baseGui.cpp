//
//  base_gui.cpp
//  gameOfLife
//
//  Created by Christopher Smith on 1/19/14.
//
//

#include "baseGui.h"

BaseGui::BaseGui(int x, int y, int width, int height){
    this->_xPos = x;
    this->_yPos = y;
    this->_width = width;
    this->_height= height;
    this->_setup();
}

BaseGui::BaseGui(){
    this->_xPos = 10;
    this->_yPos = 10;
    this->_width = 100;
    this->_height= 15;
    this->_setup();
}

BaseGui::~BaseGui(){
    // does nothing probably
}

void BaseGui::_setup(){
    // setup common to both constructors
    this->_bgColor = ofColor(50,50,50);
    this->_fillColor = ofColor(150,150,150);
    this->_textColor = ofColor(255,255,255);
    this->_title = "";
    this->_xTitle = 0;
    this->_yTitle = -2;
    
    // listen to mouse events
    ofAddListener(ofEvents().mousePressed, this, &BaseGui::_mousePressed);
    ofAddListener(ofEvents().mouseDragged, this, &BaseGui::_mouseDragged);
    ofAddListener(ofEvents().mouseReleased, this, &BaseGui::_mouseReleased);
}

void BaseGui::_mousePressed( ofMouseEventArgs& e){
    // mouse pressed event
    if ( !this->_isOnGui(e.x, e.y) )
        return;
}

void BaseGui::_mouseDragged(ofMouseEventArgs& e ){
    // mouse dragged event
    if ( !this->_isOnGui(e.x, e.y) ) {
        //this->_settingVal = false; if mouse moves off slider, stop updating value
        return;
    }
}

void BaseGui::_mouseReleased(ofMouseEventArgs& e){
    // mouse released event
    
}

bool BaseGui::_isOnGui(int x, int y) {
    // checks if mouse is on this object
    //  used with mouse events
    if ( (x >= this->_xPos) && (x <= this->_xPos + this->_width) ) {
        if ( (y >= this->_yPos) && (y <= this->_yPos + this->_height) )
            return true;
    }
    return false;
}

BaseGui& BaseGui::operator=(const BaseGui& rhs) {
    // assignment operator
    if (this != &rhs) {
        this->setPosition( rhs.getPosition() );
        this->setSize( rhs.getWidth(), rhs.getHeight() );
        this->setTitle( rhs.getTitle() );
        this->setBackgroundColor( rhs.getBackgroundColor() );
        this->setFillColor( rhs.getFillColor() );
        this->setTextColor( rhs.getTextColor() );
    }
    return *this;  // Return a reference to myself.
}

void BaseGui::setPosition(int x, int y) {
    this->_xPos = x;
    this->_yPos = y;
}

void BaseGui::setPosition(ofPoint pt) {
    this->setPosition(pt.x, pt.y);
}

void BaseGui::offset(int x, int y) {
    this->_xPos += x;
    this->_yPos += y;
}

void BaseGui::setSize(int width, int height) {
    this->_width = width;
    this->_height = height;
}

void BaseGui::setBackgroundColor(ofColor color) {
    this->_bgColor = color;
}

void BaseGui::setFillColor(ofColor color) {
    this->_fillColor = color;
}

void BaseGui::setTextColor(ofColor color) {
    this->_textColor = color;
}

void BaseGui::setTitle(string title) {
    this->_title = title;
}

void BaseGui::setTitlePosition(int x, int y) {
    this->_xTitle = x;
    this->_yTitle = y;
}

void BaseGui::setTitlePosition(ofPoint pt) {
    this->setTitlePosition(pt.x, pt.y);
}

ofPoint BaseGui::getPosition() const{
    return ofPoint(this->_xPos, this->_yPos);
}

int BaseGui::getHeight() const{
    return this->_height;
}

int BaseGui::getWidth() const{
    return this->_width;
}

string BaseGui::getTitle() const{
    return this->_title;
}

ofPoint BaseGui::getTitlePosition() const{
    return ofPoint(this->_xTitle, this->_yTitle);
}

ofColor BaseGui::getBackgroundColor() const{
    return this->_bgColor;
}

ofColor BaseGui::getFillColor() const{
    return this->_fillColor;
}

ofColor BaseGui::getTextColor() const{
    return this->_textColor;
}

void BaseGui::draw() const{
    ofSetColor(this->_bgColor);
    ofRect( this->_xPos, this->_yPos, this->_width, this->_height);
    if (this->_title != "") {
        ofSetColor( this->_textColor );
        int x = this->_xPos + this->_xTitle;
        int y = this->_yPos + this->_yPos;
        ofDrawBitmapString( this->_title, x, y );
    }
}
