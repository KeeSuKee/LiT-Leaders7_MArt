//
//  MyCircle.hpp
//  SoundAddon
//
//  Created by 野原惠祐 on 2016/02/20.
//
//

#ifndef MyCircle_hpp
#define MyCircle_hpp

#include "ofMain.h"

class MyCircle {
    
public:
    void draw();
    void setColor(ofColor color);
    void setPos(ofPoint pos);
    void setRadius(float radius);

private:
    ofColor color;
    ofPoint pos;
    float radius;
};

#endif /* MyCircle_hpp */
