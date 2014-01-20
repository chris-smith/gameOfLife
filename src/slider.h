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
#include "baseGui.h"

// Should make base class for gui so I don't need to draw each Slider separately
//  gui.add(Slider);
//  gui.draw(); <-- draws all sliders, other gui elements
// Maybe slider should be a template so it can deal with int, double, etc

//template <class a_type> class a_class {...};

template <class Tp>
class Slider : public BaseGui{
public:
    Slider();
    Slider(int, int, int, int, Tp, Tp);   // x, y, width, height, min, max
    
    virtual void draw() const;
    
    // setters
    void setRange(Tp,Tp);
    
    // getters
    Tp getMin() const;
    Tp getMax() const;
    
    // operators
    operator Tp() const;        // cast operator
    Slider& operator=(const Tp&);
    Slider& operator=(const Slider&);
    
    // get logarithmic, exponential scale
    Tp log() const;
    Tp exp() const;
    
    // Current slider value
    Tp val;
private:
    // events
    virtual void _mousePressed(ofMouseEventArgs&);
    virtual void _mouseDragged(ofMouseEventArgs&);
    virtual void _mouseReleased(ofMouseEventArgs&);
    
    bool _isOnSlider(int,int);      // I think this is unnecessary -- _isOnGui() should work
    
    void _setup();
    
    // Slider specific member data
    Tp _min;
    Tp _max;
    int _sliderPosition;            // tracked for drawing
    bool _settingVal;               // tracks whether to set values for slider
};

#endif /* defined(__gameOfLife__slider__) */
