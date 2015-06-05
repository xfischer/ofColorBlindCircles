#include "Utils.h"

//----------------------------------------------------------
ofxPoint::ofxPoint(float x, float y) {
	this->x = x;
	this->y = y;
}

//----------------------------------------------------------
ofxCircle::ofxCircle(){
}

//----------------------------------------------------------
ofxCircle::ofxCircle(int x, int y, float rad){
}

//----------------------------------------------------------
void ofxCircle::setup(){
}
  
//----------------------------------------------------------
bool ofxCircle::overlapsMotive(){
	return true;
}
  
//----------------------------------------------------------
bool ofxCircle::overlapsAny(){
	return true;
}
  
//----------------------------------------------------------
bool ofxCircle::intersects(ofxCircle c){
	return true;
}
  
//----------------------------------------------------------
bool ofxCircle::inside(ofxCircle c){
	return true;
}
  
//----------------------------------------------------------
void ofxCircle::draw(){
}
