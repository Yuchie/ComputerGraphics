#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    myImage.loadImage("okame.jpg");
    Smoothed = myImage;
    Detailed = myImage;
    w = myImage.getWidth();
    h = myImage.getHeight();
    margin = 20;

    gui.setup();
    gui.add(Sigma_s.setup("Sigma_space", 10, 0, 100));
    gui.add(Sigma_r.setup("Sigma_range", 32, 0, 512));
    
    pixels = myImage.getPixels();
    S_pixels = Smoothed.getPixels();
    D_pixels = Detailed.getPixels();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //only if the keypressed, start to calculate
    if(flag==1){
        
        for (int x=0; x<w; x++){
            for (int y=0; y<h; y++){
                
                int r = pixels[y*3*w + x*3];
                int g = pixels[y*3*w + x*3 + 1];
                int b = pixels[y*3*w + x*3 + 2];
                
                float r_num = 0;
                float r_den = 0;
                float g_num = 0;
                float g_den = 0;
                float b_num = 0;
                float b_den = 0;
                
                int R;
                if(Sigma_s < Sigma_r){
                    R = Sigma_s;
                }else{
                    R = Sigma_r;
                }
                int minW = x-R;
                int maxW = x+R;
                int minH = y-R;
                int maxH = y+R;
                
                if(minW < 0){
                    minW = 0;
                }
                if(maxW > w){
                    maxW = w;
                }
                if(minH < 0){
                    minH = 0;
                }
                if(maxH > h){
                    maxH = h;
                }
                
                for (int i=minW; i<maxW; i++){
                    for (int j=minH; j<maxH; j++){
                        
                        int r_q = pixels[j*3*w + i*3];
                        int g_q = pixels[j*3*w + i*3 + 1];
                        int b_q = pixels[j*3*w + i*3 + 2];
                        
                        int d = (x-i)*(x-i)+(y-j)*(y-j);
                        r_num += exp(-d/(2*Sigma_s*Sigma_s))*exp(-(r-r_q)*(r-r_q)/(2*Sigma_r*Sigma_r))*r_q;
                        g_num += exp(-d/(2*Sigma_s*Sigma_s))*exp(-(g-g_q)*(g-g_q)/(2*Sigma_r*Sigma_r))*g_q;
                        b_num += exp(-d/(2*Sigma_s*Sigma_s))*exp(-(b-b_q)*(b-b_q)/(2*Sigma_r*Sigma_r))*b_q;
                        
                        r_den += exp(-d/(2*Sigma_s*Sigma_s))*exp(-(r-r_q)*(r-r_q)/(2*Sigma_r*Sigma_r));
                        g_den += exp(-d/(2*Sigma_s*Sigma_s))*exp(-(g-g_q)*(g-g_q)/(2*Sigma_r*Sigma_r));
                        b_den += exp(-d/(2*Sigma_s*Sigma_s))*exp(-(b-b_q)*(b-b_q)/(2*Sigma_r*Sigma_r));
                        
                    }
                }
                
                S_pixels[y*3*w + x*3] = r_num/r_den;
                S_pixels[y*3*w + x*3 + 1] = g_num/g_den;
                S_pixels[y*3*w + x*3 + 2] = b_num/b_den;
                
                D_pixels[y*3*w + x*3] = r-r_num/r_den;
                D_pixels[y*3*w + x*3 + 1] = g-g_num/g_den;
                D_pixels[y*3*w + x*3 + 2] = b-b_num/b_den;
                //printf("%d %d finish\n", x, y);
                
            }
        }
        Smoothed.update();
        Detailed.update();
        flag = 0;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 255, 255);
    myImage.draw(margin, 100);
    Smoothed.draw(margin*2+w, 100);
    Detailed.draw(margin*3+w*2, 100);
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'x'){
        flag = 1;
    }
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
