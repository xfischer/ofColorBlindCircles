#include "ofApp.h"


int numCircles= 0;
int maxDiameter = 22;
int minDiameter = 8;
int lastX = -1, lastY = -1;
ofImage motive;

class ofxPoint
{
	float x,y;

	ofxPoint(float x, float y) {
		this->x = x;
		this->y = y;
	} 
};


class Circle
{
	float x, y, radius;
	vector<int> xs, ys;
	ofColor bg, fg;

	Circle() {
		radius = ofRandom(minDiameter, maxDiameter) / 2.0;
		float a = ofRandom(PI*2);
		float r = ofRandom(0, ofGetWidth()*.48-radius);
		x = lastX < 0 ? ofGetWidth()*.5+cos(a)*r : lastX;
		y = lastY < 0 ? ofGetHeight()*.5+ sin(a)*r : lastY;
		init();
	}

	Circle(int x, int y, float rad) {
		this->radius = rad;
		this->x = x;
		this->y = y; 
		init();
	}

	void init() {
		bg  = ofColor(255,255,255);
		fg = -1;
		int x = int(this->x), y = int(this->y), r = int(radius); 

		xs.push_back(x);
		xs.push_back(x);
		xs.push_back(x);
		xs.push_back(x-r);
		xs.push_back(x+r);
		xs.push_back(x-r*.93);
		xs.push_back(x-r*.93);
		xs.push_back(x+r*.93);
		xs.push_back(x+r*.93);

		ys.push_back(y);
		ys.push_back(y-r);
		ys.push_back(y+r);
		ys.push_back(y);
		ys.push_back(y);
		ys.push_back(y+r*.93);
		ys.push_back(y-r*.93);
		ys.push_back(y+r*.93);
		ys.push_back(y-r*.93);
	}

	bool overlapsMotive() {
		for (int i=0;i<xs.size();i++) {
			ofColor col = motive.getColor(xs[i],ys[i]);
			if (col != bg) {
				return true; 
			}
		}
		return false;    
	}

	bool overlapsAny() {    
		for (int i=0;i<xs.size();i++) {
			ofColor col =  fbo.getTextureReference().texData (xs[i],ys[i]);
			if (col != bg) {
				return true; 
			}
		}
		if (radius > minDiameter) {
			radius = minDiameter;
			init();
			return overlapsAny();
		}
		return false;
	}

	bool intersects(Circle c) {
		int dx = int(c.x)-int(x), dy  = int(c.y) - int(y);
		return dx * dx + dy * dy < (c.radius + radius)*(c.radius + radius);
	}

	bool inside(Circle c) {
		int dx = int(c.x)-int(x), dy  = int(c.y) - int(y);
		return dx * dx + dy * dy < (c.radius - radius)*(c.radius - radius);
	} 

	void draw() {
		if (fg < 0) fg = overlapsMotive() ? on[int(ofRandom(0,on.size()))] : off[int(ofRandom(0,off.size()))];

		ofSetColor(fg);
		ofEllipse(x, y, radius*2, radius*2);
	}

};



ofFbo fbo;
vector<Circle> circles;

string motiv = "dog";


int lastAdded = 0;
int lastAddedTimeout = 100;
int lastX = -1, lastY = -1;

ofImage motive;

vector<ofColor> off, on;

//--------------------------------------------------------------
void ofApp::setup(){
	fbo.allocate(ofGetWidth(), ofGetHeight());
	ofBackground(255);
	ofNoFill();
	motive.loadImage(motiv+".png");


	// style 1
	off.push_back(ofColor::fromHex(0x9CA594));
	off.push_back(ofColor::fromHex(0xACB4A5));
	off.push_back(ofColor::fromHex(0xBBB964));
	off.push_back(ofColor::fromHex(0xD7DAAA));
	off.push_back(ofColor::fromHex(0xE5D57D));
	off.push_back(ofColor::fromHex(0xD1D6AF));
	// style 2
	/*     color(#F49427), color(#C9785D), color(#E88C6A), color(#F1B081), 
	color(#F49427), color(#C9785D), color(#E88C6A), color(#F1B081), 
	color(#F49427), color(#C9785D), color(#E88C6A), color(#F1B081), color(#FFCE00)*/


	on.push_back(ofColor::fromHex(0xF9BB82));
	on.push_back(ofColor::fromHex(0xEBA170));
	on.push_back(ofColor::fromHex(0xFCCD84));
	/*    color(#89B270), color(#7AA45E),  color(#B6C674),  color(#7AA45E),  color(#B6C674),  
	color(#89B270), color(#7AA45E),  color(#B6C674),  color(#7AA45E),  color(#B6C674), 
	color(#89B270), color(#7AA45E),  color(#B6C674),  color(#7AA45E),  color(#B6C674), color(#FECB05)*/



}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	fbo.begin();

	if (numCircles < circles.size()) {
		circles[numCircles] = Circle();
		if (circles[numCircles].overlapsAny()) {
			circles[numCircles] = null;
		}

		if (circles[numCircles] != null) {
			circles[numCircles].draw();

			if (numCircles > 1) {
				float nearest = 100000;
				float current = 0;
				int nearestIndex = -1;
				for (int i=0; i<numCircles; i++) {
					
					current = ofVec2f(circles[i].x, circles[i].y).distance(circles[numCircles].x, circles[numCircles].y);
					if (current < nearest) {
						nearest = current;
						nearestIndex = i;
					}
				}

			}

			numCircles++;
			lastAdded = 0;
		} else {
			if (lastAdded > lastAddedTimeout && maxDiameter > minDiameter) {
				maxDiameter--;
				// minDiameter--;
				lastAdded = 0;
			}
			lastAdded++;
		}
	}
	lastX = lastY = -1;

	fbo.end();
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
	if (ofVec2f(mouseX, mouseY).distance( ofVec2f(ofGetWidth()*0.5, ofGetHeight()*0.5)) < ofGetWidth() * 0.48) {
		lastX = mouseX;
		lastY = mouseY;
	}
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



