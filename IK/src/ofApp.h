#pragma once

#include "ofMain.h"

#define POINT_NUM 5 //the maximum number of point
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
    
        void calculateIK(int n);
    
        ofVec2f origin;
        ofVec2f pos[POINT_NUM]; //posture of link
        ofVec2f position[POINT_NUM]; //position of link
        int j_angle[POINT_NUM];
        int flag; //0:nothing n:point [n] is selected
        ofVec2f target;
    
        int length; //the length of joint
		
};
