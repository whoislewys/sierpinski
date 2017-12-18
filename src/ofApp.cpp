#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	x1 = 200;	y1 = 0;
	x2 = 0;		y2 = -200;
	x3 = -200;	y3 = 0;
	NUM_RECURSIONS = 5;
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofTranslate(ofGetWidth() / 2 - 50, 400, 0);
	ofSetColor(0);
	ofSetColor(255);
	Sierpinski(x1, y1, x2, y2, x3, y3, NUM_RECURSIONS);
}

//--------------------------------------------------------------
void ofApp::Sierpinski(double x1, double y1, double x2, double y2, double x3, double y3, int n) {
	if (n != 0) {
		ofSetColor(255 - 7*n);
		// draw three identical triangles, each with half width & height
		ofDrawTriangle(x1, y1, x2, y2, x3, y3);
		// finding midpoints of triangle
		double new_x1 = (x1 + x2) / 2;		double new_y1 = (y1 + y2) / 2;
		double new_x2 = (x1 + x3) / 2;		double new_y2 = (y1 + y3) / 2;
		double new_x3 = (x2 + x3) / 2;		double new_y3 = (y2 + y3) / 2;
		// three recursive calls, one for each new triangle (shrinking & duplication)
		Sierpinski(x1, y1, new_x1, new_y1, new_x2, new_y2, n-1);
		Sierpinski(new_x1, new_y1, new_x2, y2, new_x3, new_y3, n-1);
		Sierpinski(new_x2, new_y2, new_x3, new_y3, x3, y3, n-1);
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
