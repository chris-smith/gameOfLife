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
#include <math.h>       /* log */
#include <iostream>

// Should make base class for gui so I don't need to draw each Slider separately
//  gui.add(Slider);
//  gui.draw(); <-- draws all sliders, other gui elements
// Maybe slider should be a template so it can deal with int, double, etc

//template <class a_type> class a_class {...};

template <class Tp>
class Slider {
public:
    Slider();
    Slider(int, int, int, int, Tp, Tp);   // x, y, width, height, min, max
    
    void draw();
    
    // setters
    void setPosition(int,int);
    void setPosition(ofPoint);
    void offset(int,int);
    void setSize(int,int);
    void setRange(Tp,Tp);
    void setBackgroundColor(ofColor);
    void setFillColor(ofColor);
    void setTextColor(ofColor);
    void setTitle(string);
    
    // getters
    ofPoint getPosition() const;
    int getHeight() const;
    int getWidth() const;
    Tp getMin() const;
    Tp getMax() const;
    string getTitle() const;
    ofColor getBackgroundColor() const;
    ofColor getFillColor() const;
    ofColor getTextColor() const;
    
    // operators
    operator Tp(); // cast operator
    Slider& operator=(const Tp&);
    Slider& operator=(const Slider&);
    
    // get logarithmic, exponential scale
    Tp log() const;
    Tp exp() const;
    
    Tp val;
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
    Tp _min;
    Tp _max;
    int _sliderPosition;    // tracked for drawing
    string _title;
    
    bool _settingVal;       // tracks whether to set values for slider
};

#endif /* defined(__gameOfLife__slider__) */
