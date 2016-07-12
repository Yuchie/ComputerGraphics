#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
    
        ofImage myImage;
        ofImage Smoothed;
        ofImage Detailed;
    
        ofxPanel gui;
        ofxIntSlider Sigma_s;
        ofxIntSlider Sigma_r;
    
        int margin;
        int w;
        int h;
    
        unsigned char *pixels;
        unsigned char *S_pixels;
        unsigned char *D_pixels;
    
        int flag; //0: nothing, 1: calculate start
		
};
