#pragma once

#define CIRCLE_NUM 100

#include "ofMain.h"
#include "ofxEasyFft.h"
#include "MyCircle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxEasyFft fft;
    
    ofSoundPlayer mySound;
    float *volume;
    float *fftSmoothed;
    float avgSound;
    
    float * Fft;
    
    int nBandsToGet;
    
    MyCircle circles[CIRCLE_NUM];
    
};
