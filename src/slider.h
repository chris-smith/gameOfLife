//
//  slider.h
//  gameOfLife
//
//  Created by Christopher Smith on 1/9/14.
//
//

#ifndef __gameOfLife__slider__
#define __gameOfLife__slider__

#include "ofMain.h"
#include <iostream>

class Slider {
public:
    Slider();
    Slider(int, int, int, int, int, int);   // x, y, width, height, min, max
    
    void draw();
    
    // setters
    void setPosition(int,int);
    void setPosition(ofPoint);
    void setSize(int,int);
    void setRange(int,int);
    void setBackgroundColor(ofColor);
    void setFillColor(ofColor);
    void setTextColor(ofColor);
    void setTitle(string);
    
    // getters
    ofPoint getPosition() const;
    int getHeight() const;
    int getWidth() const;
    int getMin() const;
    int getMax() const;
    string getTitle() const;
    ofColor getBackgroundColor() const;
    ofColor getFillColor() const;
    ofColor getTextColor() const;
    
    // operators
    operator int(); // cast operator
    Slider& operator=(const Slider&);
    
    int val;
private:
    // events
    void _mousePressed(ofMouseEventArgs&);
    void _mouseDragged(ofMouseEventArgs&);
    void _mouseReleased(ofMouseEventArgs&);
    

    void _setup();
    bool _isOnSlider(int,int);

    ofColor _bgColor;
    ofColor _fillColor;
    ofColor _textColor;
    int _xPos;
    int _yPos;
    int _width;
    int _height;
    int _min;
    int _max;
    int _sliderPosition;    // tracked for drawing
    string _title;
    
    bool _settingVal;       // tracks whether to set values for slider
};

#endif /* defined(__gameOfLife__slider__) */
