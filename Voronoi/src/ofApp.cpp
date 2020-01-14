#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
//    gui.add(button.setup("button"));
    
    width = ofGetWindowWidth();
    height = ofGetWindowHeight();

    for(int i = 0; i < pointCount; i++) {
        points[i].pos = ofVec2f(ofRandom(width), ofRandom(height));
    }
      
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
   
    for(int i = 0; i < pointCount; i++) {
        ofDrawCircle(points[i].pos.x, points[i].pos.y, 1);
    }

    
    for(int i = 0; i < width; i += 2) {
        for(int j = 0; j < height; j += 2) {

            
            for(int k = 0; k < pointCount; k += 1) {
                points[k].distanceToCursor = (int)points[k].pos.distance(ofVec2f(i,j));
            }

            int currentNearestDist = 50000;

            for(int k = 0; k < pointCount; k += 1) {
                if(points[k].distanceToCursor < currentNearestDist) {
                    currentNearestDist = points[k].distanceToCursor;
                }
            }
            
            for(int k = 0; k < pointCount; k += 1) {
                for(int l = k + 1; l < pointCount; l += 1) {
                    if(points[k].distanceToCursor == points[l].distanceToCursor &&  points[k].distanceToCursor == currentNearestDist) {
                        ofDrawCircle(i, j, 1);
                    }
                }
            }
                
                
        }
    }

    
    //    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    points[0].pos = ofVec2f(x, y);
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
