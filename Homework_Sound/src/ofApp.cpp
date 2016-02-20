#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetCircleResolution(64);
    ofBackground(0);
    
    fft.setup(pow(2.0, 8.0));
    
    nBandsToGet = 1024;
    
    mySound.loadSound("u.s.o3.mp3");
    mySound.setLoop(true);
    mySound.play();
    
    fftSmoothed = new float[8192];
    for(int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    
    int bufferSize =256;
    
       

}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update();
    
    ofSoundUpdate();
    Fft = ofSoundGetSpectrum(nBandsToGet);
    volume = ofSoundGetSpectrum(nBandsToGet);
    
    for(int i = 0; i < nBandsToGet; i++){
        fftSmoothed[i] *= 0.96;
        if(fftSmoothed[i] < volume[i]){
            fftSmoothed[i] = volume[i];
            avgSound += fftSmoothed[i];
        }
    }
    
    avgSound /= nBandsToGet;

}

//--------------------------------------------------------------
void ofApp::draw(){
    vector<float>buffer;

    float width = (float)(800) / nBandsToGet;
    
    ofSetLineWidth(ofGetWidth() / float(buffer.size()) / 2.0 - 0.5);
    
    for(int i = 0; i < nBandsToGet; i++) {
        float hue = ofMap(i, 0, nBandsToGet, 0, 160);
        ofColor col;
        col.setHsb(hue, 255, 255);
        ofSetColor(col);
        
        ofRect(0 + i*width, ofGetHeight(), width,-(fftSmoothed[i] *400));
        
    }
    
    for(int i = 0; i<nBandsToGet; i++){
        int b = float(255) /float(nBandsToGet)*i;
        
        ofSetColor(ofRandom(0,150),ofRandom(150,255) , b);
                
        ofCircle(ofGetWidth()/2 + width * i,
                 ofGetHeight()/2,Fft[i]*50);
        
        ofCircle(ofGetWidth()/2 - width * i,
                 ofGetHeight()/2, Fft[i]*50);
    }
    
    ofColor col;
    
    for (int i = 0; i < CIRCLE_NUM; i++) {
        col.r = ofRandom(255);
        col.g = ofRandom(255);
        col.b = ofRandom(255);
        circles[i].setColor(col);
        circles[i].setPos(ofPoint(ofRandom(0, ofGetWidth()) ,ofRandom(0, ofGetHeight())));
        circles[i].setRadius(Fft[i]*10);
    }
    
    for(int i =0; i <CIRCLE_NUM; i++){
        circles[i].draw();
    }
                             

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
