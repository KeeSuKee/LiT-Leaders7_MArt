#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetCircleResolution(100);
    cx = ofGetWidth();
    cy = ofGetHeight();
    
 }

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int x = 35;
    int y = 35;
    for(int i=0; i<cx/35; i=i+1){
        ofSetLineWidth(1);
        ofSetColor(128,128,128);
        ofLine(x, 0, x, cy);
        ofLine(0, y, cx, y);
        x = x + 35;
        y = y + 35;
   }
    
    
        
    
    float triX = mouseX - cx/2;
    float triY = mouseY - cy/2;
    float mouseAngle = double (atan2(double (-triY), double (triX)));
    float mouseAngle2 = double (atan2(double (triY), double (-triX)));
    float angle =(mouseAngle * 180)/PI;
    float angle2 =((mouseAngle2 * 180)/PI)+180;
    float degrees = angle * 254/360;
    float degrees2 = angle2 * 254/360;

    
    ofColor color;
    color.setHsb(degrees,255,255);
    color.setHsb(degrees2,255,255);
    ofSetColor(color);

    
    
    ofSetLineWidth(3);
    ofNoFill();
    ofCircle(cx/2,cy/2,ofDist(cx/2, cy/2, mouseX, mouseY)) ;
    ofFill();
    ofCircle(cx/2,cy/2,(ofDist(cx/2, cy/2, mouseX, mouseY))/4) ;
    ofLine(cx/2,cy/2, mouseX, mouseY);
    
    
    
    
    ofSetLineWidth(1);
    ofSetColor(0,0,0);
    ofLine(mouseX,0,mouseX,cy);
    ofLine(0,mouseY,cx,mouseY);
   
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
   
    
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