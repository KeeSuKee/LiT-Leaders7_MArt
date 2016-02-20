//
//  MyCircle.cpp
//  SoundAddon
//
//  Created by 野原惠祐 on 2016/02/20.
//
//

#include "MyCircle.hpp"

void MyCircle::draw(){
    
    ofSetColor(color.r, color.g, color.b);
    
    ofCircle(pos.x, pos.y, radius);
}

void MyCircle::setColor(ofColor _color){
    color = _color;
}

void MyCircle::setPos(ofPoint _pos){
    pos = _pos;
}

void MyCircle::setRadius(float _radius){
    radius = _radius;
}