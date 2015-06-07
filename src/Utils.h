//#pragma once
//
//#include "ofMain.h"
//
//class ofxPoint{
//public:
//	float x,y;
//
//	ofxPoint(float x, float y);
//};
//
//class ofxCircle{
//public:
//	float x, y, radius;
//	vector<int> xs, ys;
//	ofColor bg,fg;
//
//	ofxCircle();
//
//	ofxCircle(int x, int y, float rad);
//
//	void setup();
//
//	bool overlapsMotive();
//
//	bool overlapsAny();
//
//	bool intersects(ofxCircle c);
//
//	bool inside(ofxCircle c);
//
//	void draw();
//
//};
//
//
//
//
////
////
////Circle[] circles = new Circle[5000];
////
////String motiv = "dog";
////
////int count = 0;
////int maxDiameter = 22;
////int minDiameter = 8;
////int lastAdded = 0;
////int lastAddedTimeout = 100;
////
////PImage motive;
////
////color[] off, on;
////
////void setup() {
////  size(600, 600);
////  smooth();
////  background(255);
////  colorMode(RGB);
////  noFill();
////  motive = loadImage(motiv+".png");
////  
////  color[] _off = {
////// style 1
////   color(#9CA594), color(#ACB4A5), color(#BBB964), color(#D7DAAA), color(#E5D57D), color(#D1D6AF)
////// style 2
/////*     color(#F49427), color(#C9785D), color(#E88C6A), color(#F1B081), 
////     color(#F49427), color(#C9785D), color(#E88C6A), color(#F1B081), 
////     color(#F49427), color(#C9785D), color(#E88C6A), color(#F1B081), color(#FFCE00)*/
////  };
////  
////  color[] _on = {
////    color(#F9BB82), color(#EBA170), color(#FCCD84)
/////*    color(#89B270), color(#7AA45E),  color(#B6C674),  color(#7AA45E),  color(#B6C674),  
////    color(#89B270), color(#7AA45E),  color(#B6C674),  color(#7AA45E),  color(#B6C674), 
////     color(#89B270), color(#7AA45E),  color(#B6C674),  color(#7AA45E),  color(#B6C674), color(#FECB05)*/
////  };
////
////  on = _on;
////  off = _off;
////  
//// 
////}
////
////void draw() {
////  if (count < circles.length) {
////    circles[count] = new Circle();
////    if (circles[count].overlapsAny()) {
////      circles[count] = null;
////    }
////    
////    if (circles[count] != null) {
////      circles[count].draw();
////      
////      if (count > 1) {
////        float nearest = 100000;
////        float current = 0;
////        int nearestIndex = -1;
////        for (int i=0; i<count; i++) {
////          current = dist(circles[i].x, circles[i].y, circles[count].x, circles[count].y);
////          if (current < nearest) {
////            nearest = current;
////            nearestIndex = i;
////          }
////        }
////      
////      }
////      
////      count++;
////      lastAdded = 0;
////    } else {
////      if (lastAdded > lastAddedTimeout && maxDiameter > minDiameter) {
////         maxDiameter--;
////         // minDiameter--;
////         lastAdded = 0;
////       }
////      lastAdded++;
////     }
////  }
////  lastX = lastY = -1;
////}
////
////class Point
////{
////   float x,y;
////   
////   Point(float x, float y) {
////     this.x = x;
////     this.y = y;
////   } 
////}
////
////class Circle
////{
////  float x, y, radius;
////  int[] xs, ys;
////  color bg = color(255,255,255), fg = -1;
////  
////  Circle() {
////    radius = random(minDiameter, maxDiameter) / 2.0;
////    float a = random(PI*2);
////    float r = random(0, width*.48-radius);
////    x = lastX < 0 ? width*.5+cos(a)*r : lastX;
////    y = lastY < 0 ? height*.5+ sin(a)*r : lastY;
////    init();
////  }
////  
////  Circle(int x, int y, float rad) {
////    this.radius = rad;
////    this.x = x;
////    this.y = y; 
////    init();
////  }
////  
////  void init() {
////    int x = int(this.x), y = int(this.y), r = int(radius); 
////    int[] xs = {x,x ,x  ,x-r,x+r,int(x-r*.93),int(x-r*.93),int(x+r*.93),int(x+r*.93)}; 
////    int[] ys = {y,y-r,y+r,y,y,int(y+r*.93),int(y-r*.93),int(y+r*.93),int(y-r*.93)};
////    this.xs = xs;
////    this.ys = ys;
////  }
////  
////  boolean overlapsMotive() {
////    for (int i=0;i<xs.length;i++) {
////      int col = motive.get(xs[i],ys[i]);
////      if (col != bg) {
////        return true; 
////      }
////    }
////    return false;    
////  }
////  
////  boolean overlapsAny() {    
////    for (int i=0;i<xs.length;i++) {
////      int col = get(xs[i],ys[i]);
////      if (col != bg) {
////        return true; 
////      }
////    }
////    if (radius > minDiameter) {
////       radius = minDiameter;
////       init();
////       return overlapsAny();
////    }
////    return false;
////  }
////  
////  boolean intersects(Circle c) {
////    int dx = int(c.x)-int(x), dy  = int(c.y) - int(y);
////    return dx * dx + dy * dy < (c.radius + radius)*(c.radius + radius);
////  }
////  
////  boolean inside(Circle c) {
////    int dx = int(c.x)-int(x), dy  = int(c.y) - int(y);
////    return dx * dx + dy * dy < (c.radius - radius)*(c.radius - radius);
////  } 
////  
////  void draw() {
////    if (fg < 0) fg = overlapsMotive() ? on[int(random(0,on.length))] : off[int(random(0,off.length))];
////   
////    fill(fg);
////    noStroke();
////    ellipse(x, y, radius*2, radius*2);
////  }
////  
////}
////
////void keyPressed() {
////  if (key == 's') {
////    save("out/"+motiv+".png");
////  } 
////}
////
////int lastX = -1, lastY = -1;
////
////void mouseClicked() {
////  if (dist(mouseX, mouseY, width*0.5, height*0.5) < width * 0.48) {
////    lastX = mouseX;
////    lastY = mouseY;
////  }
////}
