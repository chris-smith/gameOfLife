//
//  slider.cpp
//  gameOfLife
//
//  Created by Christopher Smith on 1/9/14.
//
//

#include "slider.h"

#ifndef __gameOfLife__slider__cpp
#define __gameOfLife__slider__cpp

template <class Tp>
Slider<Tp>::Slider(int x, int y, int width, int height, Tp min, Tp max){
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

template <class Tp>
Slider<Tp>::Slider(){
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

template <class Tp>
void Slider<Tp>::_setup(){
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

template <class Tp>
void Slider<Tp>::_mousePressed( ofMouseEventArgs& e){
    // mouse pressed event
    if ( !this->_isOnSlider(e.x, e.y) )
        return;
    this->_settingVal = true;
    this->_sliderPosition = e.x - this->_xPos;
    this->val = this->_sliderPosition * (this->_max - this->_min) / this->_width + this->_min;
}

template <class Tp>
void Slider<Tp>::_mouseDragged(ofMouseEventArgs& e ){
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

template <class Tp>
void Slider<Tp>::_mouseReleased(ofMouseEventArgs& e){
    // mouse released event
    //  This is unnecessary?
    this->_settingVal = false;
}

template <class Tp>
bool Slider<Tp>::_isOnSlider(int x, int y) {
    // checks if mouse is on this slider object
    //  used with mouse events
    if ( (x >= this->_xPos) && (x <= this->_xPos + this->_width) ) {
        if ( (y >= this->_yPos) && (y <= this->_yPos + this->_height) )
            return true;
    }
    return false;
}

template <class Tp>
Slider<Tp>::operator Tp() {
    // Tp cast returns value
    return this->val;
}

template <class Tp>
Slider<Tp>& Slider<Tp>::operator=(const Tp &rhs) {
    this->val = rhs;
    return *this;
}

template <class Tp>
Slider<Tp>& Slider<Tp>::operator=(const Slider &rhs) {
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

template <class Tp>
void Slider<Tp>::setPosition(int x, int y) {
    this->_xPos = x;
    this->_yPos = y;
}

template <class Tp>
void Slider<Tp>::setPosition(ofPoint pt) {
    this->setPosition(pt.x, pt.y);
}

template <class Tp>
void Slider<Tp>::offset(int x, int y) {
    this->_xPos += x;
    this->_yPos += y;
}

template <class Tp>
void Slider<Tp>::setSize(int width, int height) {
    this->_width = width;
    this->_height = height;
}

template <class Tp>
void Slider<Tp>::setRange(Tp min, Tp max) {
    this->_min = min;
    this->_max = max;
    this->val = (min + max) / 2;
    this->_sliderPosition = ( this->val - this->_min ) * this->_width / (this->_max - this->_min );
}

template <class Tp>
void Slider<Tp>::setBackgroundColor(ofColor color) {
    this->_bgColor = color;
}

template <class Tp>
void Slider<Tp>::setFillColor(ofColor color) {
    this->_fillColor = color;
}

template <class Tp>
void Slider<Tp>::setTextColor(ofColor color) {
    this->_textColor = color;
}

template <class Tp>
void Slider<Tp>::setTitle(string title) {
    this->_title = title;
}

template <class Tp>
ofPoint Slider<Tp>::getPosition() const{
    return ofPoint(this->_xPos, this->_yPos);
}

template <class Tp>
int Slider<Tp>::getHeight() const{
    return this->_height;
}

template <class Tp>
int Slider<Tp>::getWidth() const{
    return this->_width;
}

template <class Tp>
Tp Slider<Tp>::getMin() const{
    return this->_min;
}

template <class Tp>
Tp Slider<Tp>::getMax() const{
    return this->_max;
}

template <class Tp>
string Slider<Tp>::getTitle() const{
    return this->_title;
}

template <class Tp>
ofColor Slider<Tp>::getBackgroundColor() const{
    return this->_bgColor;
}

template <class Tp>
ofColor Slider<Tp>::getFillColor() const{
    return this->_fillColor;
}

template <class Tp>
ofColor Slider<Tp>::getTextColor() const{
    return this->_textColor;
}

template <class Tp>
Tp Slider<Tp>::log() const{
    // returns exp scaled value
    double minp = this->_min;
    double maxp = this->_max;
    
    // The result should be between min and max
    double minv = log2(minp);
    double maxv = log2(maxp);
    
    // calculate adjustment factor
    double scale = (maxv-minv) / (maxp-minp);
    
    return ((( log2(this->val) - minv ) / scale ) + minp);
}

template <class Tp>
Tp Slider<Tp>::exp() const{
    // returns log scaled value
    double minp = this->_min;
    double maxp = this->_max;
    
    // The result should be between min and max
    double minv = log2(minp);
    double maxv = log2(maxp);
    
    // calculate adjustment factor
    double scale = (maxv-minv) / (maxp-minp);
    
    return exp2( minv + scale * ( double(this->val) - minp ) );
}

template <class Tp>
void Slider<Tp>::draw() {
    ofSetColor(this->_bgColor);
    ofRect( this->_xPos, this->_yPos, this->_width, this->_height);
    ofSetColor(this->_fillColor);
    ofRect( this->_xPos, this->_yPos, this->_sliderPosition, this->_height);
    ofSetColor( this->_textColor );
    if (this->_title != "")
        ofDrawBitmapString( this->_title, this->_xPos, this->_yPos-1 );
    //ofDrawBitmapString(ofToString(this->val), this->_xPos, this->_yPos + this->_height);
}

// Explicitly instantiate allowed template instances
template class Slider<int>;
template class Slider<long>;
template class Slider<double>;
template class Slider<float>;
template class Slider<unsigned int>;
template class Slider<unsigned long>;

#endif