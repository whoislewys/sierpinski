#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	X_MAX = 800;
	Y_MAX = 800;
	x1 = X_MAX;	y1 = 0;
	x2 = 0;		y2 = -1*Y_MAX;
	x3 = -1*X_MAX;	y3 = 0;
	NUM_RECURSIONS = 6;

	// get a random point within vertices
	srand(time(0)); 
	r = rand() % (int)X_MAX + 1;
	y = rand() % (int)Y_MAX + 1;
	ofPoint p = ofPoint(r, y);

	// intialize vertices, add them to the points vector
	ofPoint p1 = ofPoint(x1, y1);
	points.push_back(p1);
	ofPoint p2 = ofPoint(x2, y2);
	points.push_back(p2);
	ofPoint p3 = ofPoint(x3, y3);
	points.push_back(p3);
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(40, 40, 40);
	ofTranslate(ofGetWidth() / 2, 900, 0);
	//ofSetColor(255);
	// Recursive triangle-in-triangle method
	// Sierpinski(x1, y1, x2, y2, x3, y3, NUM_RECURSIONS);
	/*
	1 start at any point. call it p
	2 pick one of the three vertices at random
	3 find the point halfway between p and that vertex
	4 call that point p and draw it
	5 goto 2
	*/
	
	// chaos game method
	// pick one of the vertices at random
	int r = rand() % 100;
	ofSetColor(255, 0, 0);
	cout << r << endl;
	if (r <= 33) {
		// vertex 1 is chosen
		int new_x = (x1 + p.x) / 2;
		int new_y = (y1 + p.y) / 2;
		p = ofPoint(new_x, new_y);
	}
	else if (r > 33 && r < 66) {
		int new_x = (x2 + p.x) / 2;
		int new_y = (y2 + p.y) / 2;
		p = ofPoint(new_x, new_y);
	}
	else if (r > 66) {
		int new_x = (x3 + p.x) / 2;
		int new_y = (y3 + p.y) / 2;
		p = ofPoint(new_x, new_y);
		
	}

	points.push_back(p);
	vector<ofPoint>::iterator it = points.begin();
	while (it != points.end()) {
		ofDrawCircle(*it, 10);
		it++;
	}
}

//--------------------------------------------------------------
void ofApp::Sierpinski(double x1, double y1, double x2, double y2, double x3, double y3, int n) {
	// recursive
	if (n != 0) {
		ofSetColor(255 - (12 * n), 0, 0);
		// draw three identical triangles, each with half width & height
		ofDrawTriangle(x1, y1, x2, y2, x3, y3);
		// finding midpoints of triangle
		double new_x1 = (x1 + x2) / 2;		double new_y1 = (y1 + y2) / 2;
		double new_x2 = (x1 + x3) / 2;		double new_y2 = (y1 + y3) / 2;
		double new_x3 = (x2 + x3) / 2;		double new_y3 = (y2 + y3) / 2;
		// three recursive calls, one for each new triangle (shrinking & duplication)		
		ofSleepMillis(10);
		Sierpinski(x1, y1, new_x1, new_y1, new_x2, new_y2, n - 1);
		Sierpinski(new_x1, new_y1, new_x2, y2, new_x3, new_y3, n - 1);
		Sierpinski(new_x2, new_y2, new_x3, new_y3, x3, y3, n - 1);
		ofSleepMillis(20);
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
