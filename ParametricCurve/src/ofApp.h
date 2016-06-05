#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define POINT_NUM 10 //the maximum number of point
#define POINT_RADIUS 4
#define LINE_WIDTH 2

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        float factorial(int n);
        float power(float x, int n);
		
        int point_n; //the number of point
        ofVec2f position[POINT_NUM];
    
        // parameter of GUI
        ofxPanel gui;
        ofxIntSlider NUM_STEPS;
        ofxToggle Sampling;
};
