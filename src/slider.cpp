//
//  slider.cpp
//  gameOfLife
//
//  Created by Christopher Smith on 1/9/14.
//
//

#include "slider.h"

Slider::Slider(int x, int y, int width, int height, int min, int max){
    // constructor
    this->_xPos = x;
    this->_yPos = y;
    this->_width = width;
    this->_height= height;
    this->_min = min;
    this->_max = max;
    this->val = (min + max) / 2;
    this->_setup();
}

Slider::Slider(){
    // Default constructor
    this->_xPos = 10;
    this->_yPos = 10;
    this->_width = 100;
    this->_height= 15;
    this->_min = 0;
    this->_max = 100;
    this->val = 50;
    this->_setup();
}

void Slider::_setup(){
    // setup common to both constructors
    this->_bgColor = ofColor(50,50,50);
    this->_fillColor = ofColor(150,150,150);
    this->_textColor = ofColor(255,255,255);
    this->_settingVal = false;
    this->_title = "";
    
    // listen to mouse events
    ofAddListener(ofEvents().mousePressed, this, &Slider::_mousePressed);
    ofAddListener(ofEvents().mouseDragged, this, &Slider::_mouseDragged);
    ofAddListener(ofEvents().mouseReleased, this, &Slider::_mouseReleased);
}

void Slider::_mousePressed( ofMouseEventArgs& e){
    // mouse pressed event
    if ( !this->_isOnSlider(e.x, e.y) )
        return;
    this->_settingVal = true;
    this->_sliderPosition = e.x - this->_xPos;
    this->val = this->_sliderPosition * (this->_max - this->_min) / this->_width + this->_min;
}

void Slider::_mouseDragged(ofMouseEventArgs& e ){
    // mouse dragged event
    if ( !this->_isOnSlider(e.x, e.y) ) {
        this->_settingVal = false;
        return;
    }
    if (this->_settingVal) {
        this->_sliderPosition = e.x - this->_xPos;
        this->val = this->_sliderPosition * (this->_max - this->_min) / this->_width + this->_min;
    }
}

void Slider::_mouseReleased(ofMouseEventArgs& e){
    // mouse released event
    //  This is unnecessary?
    this->_settingVal = false;
}

bool Slider::_isOnSlider(int x, int y) {
    // checks if mouse is on this slider object
    //  used with mouse events
    if ( (x >= this->_xPos) && (x <= this->_xPos + this->_width) ) {
        if ( (y >= this->_yPos) && (y <= this->_yPos + this->_height) )
            return true;
    }
    return false;
}

Slider::operator int() {
    // integer cast returns value
    return this->val;
}

Slider& Slider::operator=(const Slider &rhs) {
    // assignment operator
    if (this != &rhs) {
        this->setPosition( rhs.getPosition() );
        this->setSize( rhs.getWidth(), rhs.getHeight() );
        this->setRange( rhs.getMin(), rhs.getMax() );
        this->setTitle( rhs.getTitle() );
        this->setBackgroundColor( rhs.getBackgroundColor() );
        this->setFillColor( rhs.getFillColor() );
        this->setTextColor( rhs.getTextColor() );
        this->val = rhs.val;
    }
    return *this;  // Return a reference to myself.
}

void Slider::setPosition(int x, int y) {
    this->_xPos = x;
    this->_yPos = y;
}

void Slider::setPosition(ofPoint pt) {
    this->setPosition(pt.x, pt.y);
}

void Slider::setSize(int width, int height) {
    this->_width = width;
    this->_height = height;
}

void Slider::setRange(int min, int max) {
    this->_min = min;
    this->_max = max;
    this->val = (min + max) / 2;
    this->_sliderPosition = ( this->val - this->_min ) * this->_width / (this->_max - this->_min );
}
void Slider::setBackgroundColor(ofColor color) {
    this->_bgColor = color;
}

void Slider::setFillColor(ofColor color) {
    this->_fillColor = color;
}

void Slider::setTextColor(ofColor color) {
    this->_textColor = color;
}

void Slider::setTitle(string title) {
    this->_title = title;
}

ofPoint Slider::getPosition() const{
    return ofPoint(this->_xPos, this->_yPos);
}

int Slider::getHeight() const{
    return this->_height;
}

int Slider::getWidth() const{
    return this->_width;
}

int Slider::getMin() const{
    return this->_min;
}

int Slider::getMax() const{
    return this->_max;
}

string Slider::getTitle() const{
    return this->_title;
}

ofColor Slider::getBackgroundColor() const{
    return this->_bgColor;
}

ofColor Slider::getFillColor() const{
    return this->_fillColor;
}

ofColor Slider::getTextColor() const{
    return this->_textColor;
}

void Slider::draw() {
    ofSetColor(this->_bgColor);
    ofRect( this->_xPos, this->_yPos, this->_width, this->_height);
    ofSetColor(this->_fillColor);
    ofRect( this->_xPos, this->_yPos, this->_sliderPosition, this->_height);
    ofSetColor( this->_textColor );
    if (this->_title != "")
        ofDrawBitmapString( this->_title, this->_xPos, this->_yPos-1 );
    //ofDrawBitmapString(ofToString(this->val), this->_xPos, this->_yPos + this->_height);
}