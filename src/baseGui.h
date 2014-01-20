//
//  base_gui.h
//  gameOfLife
//
//  Created by Christopher Smith on 1/19/14.
//
//
//      This is a base class for custom gui elements
//


#ifndef __gameOfLife__base_gui__
#define __gameOfLife__base_gui__

#include "ofMain.h"
#include <iostream>

class BaseGui {
public:
    BaseGui(int,int,int,int);
    BaseGui();
    ~BaseGui();
    
    virtual void draw() const;
    
    // setters
    virtual void setPosition(int,int);
    virtual void setPosition(ofPoint);
    virtual void offset(int,int);
    virtual void setSize(int,int);
    virtual void setTitle(string);
    virtual void setTitlePosition(int,int);
    virtual void setTitlePosition(ofPoint);
    virtual void setBackgroundColor(ofColor);
    virtual void setFillColor(ofColor);
    virtual void setTextColor(ofColor);
    
    
    // getters
    virtual ofPoint getPosition() const;
    virtual int getHeight() const;
    virtual int getWidth() const;
    virtual string getTitle() const;
    virtual ofPoint getTitlePosition() const;
    virtual ofColor getBackgroundColor() const;
    virtual ofColor getFillColor() const;
    virtual ofColor getTextColor() const;
    
    // operator
    BaseGui& operator=(const BaseGui&);
    
protected:
    // events
    virtual void _mousePressed(ofMouseEventArgs&);
    virtual void _mouseDragged(ofMouseEventArgs&);
    virtual void _mouseReleased(ofMouseEventArgs&);
    
    virtual bool _isOnGui(int,int);
    
    ofColor _bgColor;
    ofColor _fillColor;
    ofColor _textColor;
    int _xPos;
    int _yPos;
    int _xTitle;    // relative offset of title in x
    int _yTitle;    // relative offset of title in y
    int _width;
    int _height;
    int _offset;
    string _title;
private:
    void _setup();
};


#endif /* defined(__gameOfLife__base_gui__) */
