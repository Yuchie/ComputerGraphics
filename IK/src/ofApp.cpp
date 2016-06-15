#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(80);
    ofBackground(255, 255, 255);
    
    length = 50;
    
    origin.x = ofGetWidth()/2;
    origin.y = ofGetHeight()/2;
    
    for(int i=0; i<POINT_NUM; i++){
        j_angle[i] = 0;
        pos[i].x = length;
        pos[i].y = 0;
        position[i].x = ofGetWidth()/2 + i*length;
        position[i].y = ofGetHeight()/2;
    }
    
    flag = 0;
    
    target.x = ofGetWidth()/2 + (POINT_NUM-1) * length;
    target.y = ofGetHeight()/2;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=POINT_NUM-1; i > 0; i--){
        calculateIK(i-1);
        for(int k=i; k<POINT_NUM; k++){
            pos[k] = pos[k-1];
            pos[k].rotate(j_angle[k]);
            position[k] = position[k-1]+pos[k];
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetLineWidth(LINE_WIDTH);
    
    //draw points and lines
    ofSetColor(255, 200, 0);
    for(int i=0; i<POINT_NUM; i++){
        if(i>0){
            ofLine(position[i-1].x, position[i-1].y, position[i].x, position[i].y);
        }
    }
    
    ofSetColor(200, 100, 150);
    for(int i=0; i<POINT_NUM; i++){
        ofCircle(position[i].x, position[i].y, POINT_RADIUS);
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
    
    if(flag != 0){
        target.x = x;
        target.y = y;
    }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    if(ofDist(x, y, position[POINT_NUM-1].x, position[POINT_NUM-1].y) <= POINT_RADIUS){
        flag = POINT_NUM-1;
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    flag = 0;

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

void ofApp::calculateIK(int n){

    ofVec2f endPos = position[POINT_NUM-1];
    ofVec2f jointPos = position[n];
    
    ofVec2f joint_target = target - jointPos;
    ofVec2f joint_end = endPos - jointPos;
    
    float angle = joint_end.angle(joint_target);
    
    printf("%d %lf\n", n, angle);
    
    j_angle[n+1] = j_angle[n+1] + angle;
}
