#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(80);
    ofBackground(255, 255, 255);
    
    point_n = 0;
    
    int initNUM_STEPS = 20;
    int minNUM_STEPS = 100;
    int maxNUM_STEPS = 3;
    bool s_mode=0; //0:一定間隔 1:適応的
    
    //set up GUI
    gui.setup();
    gui.add(NUM_STEPS.setup("NUM_STEPS", initNUM_STEPS, minNUM_STEPS, maxNUM_STEPS));
    gui.add(Sampling.setup("Sampling", s_mode, 100, 20));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //display GUI
    gui.draw();

    ofSetColor(255, 200, 0);
    
    //draw points and lines
    for(int i=0; i<point_n; i++){
        ofCircle(position[i].x, position[i].y, POINT_RADIUS);
        if(i > 0){
            ofLine(position[i-1].x, position[i-1].y, position[i].x, position[i].y);
        }
    }
    
    //draw parametric line
    ofSetLineWidth(LINE_WIDTH);
    ofSetColor(0, 100, 255);
    if(point_n > 1){
        ofVec2f p[2];
        p[0] = position[0];
        p[1] = position[0];
        for(int i=0; i<(NUM_STEPS+1); i++){
            float t = (float)i/(float)NUM_STEPS;
            p[0] = p[1];
            p[1].x = 0;
            p[1].y = 0;
            if(Sampling==0){
                for(int j=0; j<point_n; j++){
                    p[1] += (factorial(point_n-1)/(factorial(point_n-1-j)*factorial(j)))*power(t, j)*power(1-t, point_n-1-j)*position[j];
                }
            }else{
                ofVec2f _p[POINT_NUM];
                for(int j=point_n; j>0; j--){
                    for(int k=0; k<j; k++){
                        if(j==point_n){
                            _p[k] = position[k];
                        }else{
                            _p[k] = (1-t)*_p[k] + t*_p[k+1];
                        }
                    }
                }
                p[1] = _p[0];
            }
            ofLine(p[0].x, p[0].y, p[1].x, p[1].y);
            //printf("%d %f %f %f\n", i, t, p[0].x, p[0].y);
        }
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
    
    int d=0;
    for(int i=0; i<point_n; i++){
        if(ofDist(x, y, position[i].x, position[i].y) <= POINT_RADIUS){
            d=1;
            point_n--;
            for(int j=i; j<point_n; j++){
                position[j] = position[j+1];
            }
            break;
        }
    }
    if(d==0 && point_n < POINT_NUM){
        point_n++;
        position[point_n-1].x = x;
        position[point_n-1].y = y;
    }else if(point_n >= POINT_NUM){
        printf("please delete some of the points to add new point\n");
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

float ofApp::factorial(int n){
    
    int a = 1;
    
    for(int i=0; i<n; i++){
        a = a*(i+1);
    }
    
    return a;
    
}

float ofApp::power(float x, int n){
    
    float a = 1;
    
    
    for(int i=0; i<n; i++){
        a = a*x;
    }
    
    return a;
    
}
