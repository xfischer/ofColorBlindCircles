//#include "Utils.h"
//
//int maxDiameter = 22;
//int minDiameter = 8;
//int lastX = -1, lastY = -1;
//
////----------------------------------------------------------
//ofxPoint::ofxPoint(float x, float y) {
//	this->x = x;
//	this->y = y;
//}
//
////----------------------------------------------------------
//ofxCircle::ofxCircle(){
//	radius = ofRandom(minDiameter, maxDiameter) / 2.0;
//    float a = ofRandom(PI*2);
//	float r = ofRandom(0, ofGetWidth()*.48-radius);
//    x = lastX < 0 ? ofGetWidth()*.5+cos(a)*r : lastX;
//    y = lastY < 0 ? ofGetHeight()*.5+ sin(a)*r : lastY;
//    setup();
//}
//
////----------------------------------------------------------
//ofxCircle::ofxCircle(int x, int y, float rad){
//	radius = rad;
//    this->x = x;
//    this->y = y; 
//    setup();
//}
//
////----------------------------------------------------------
//void ofxCircle::setup(){
//	bg = ofColor::white;
//	fg = -1;
//	int x = int(this->x), y = int(this->y), r = int(radius); 
//	xs.push_back(x);
//	xs.push_back(x);
//	xs.push_back(x);
//	xs.push_back(x-r);
//	xs.push_back(x+r);
//	xs.push_back(x-r*.93);
//	xs.push_back(x-r*.93);
//	xs.push_back(x+r*.93);
//	xs.push_back(x+r*.93);
//
//    ys.push_back(y);
//	ys.push_back(y-r);
//	ys.push_back(y+r);
//	ys.push_back(y);
//	ys.push_back(y);
//	ys.push_back(y+r*.93);
//	ys.push_back(y-r*.93);
//	ys.push_back(y+r*.93);
//	ys.push_back(y-r*.93);
//    
//}
//
////----------------------------------------------------------
//bool ofxCircle::overlapsMotive(){
//	  for (int i=0;i<xs.size();i++) {
//      int col = motive.get(xs[i],ys[i]);
//      if (col != bg) {
//        return true; 
//      }
//    }
//    return false;    
//}
//
////----------------------------------------------------------
//bool ofxCircle::overlapsAny(){
//	return true;
//}
//
////----------------------------------------------------------
//bool ofxCircle::intersects(ofxCircle c){
//	return true;
//}
//
////----------------------------------------------------------
//bool ofxCircle::inside(ofxCircle c){
//	return true;
//}
//
////----------------------------------------------------------
//void ofxCircle::draw(){
//}
