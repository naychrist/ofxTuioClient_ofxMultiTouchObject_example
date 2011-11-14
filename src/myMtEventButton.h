#ifndef _MYMTEVENTBUTTON
#define _MYMTEVENTBUTTON

#include "ofMain.h"
#include "ofxMtObjectEvents.h"

class myMtEventButton : public ofxMtObjectEvents{
	
public:
	myMtEventButton(){
		col.r = 0;
		col.g = 0;
		col.b = 0;
	}
	void onMultiTouchDown(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL){
		col.r = ofRandom(0,1);
		col.g = ofRandom(0,1);
	    col.b = ofRandom(0,1);
	};
	void onMultiTouchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL){};
	void onMultiTouchUp(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL){
		col.r = 0;
		col.g = 0;
	    col.b = 0;
		ofNotifyEvent(eMultiTouchUp, voidEventArgs, this);
	};
	virtual void onMultiTouchRollOut(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL){
		col.r = 0;
		col.g = 0;
	    col.b = 0;
	};
	virtual void onMultiTouchRollOver(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL){
		col.r = ofRandom(0,1);
		col.g = ofRandom(0,1);
		col.b = ofRandom(0,1);
	};
	void render(){
		glColor3f(col.r, col.g, col.b);
		ofRect(x, y, width, height);
		glColor3f(1,1,1);
		ofDrawBitmapString("I am a Multitouchbutton with a global callback", x, y+height+15);
	};
	
protected:
	ofColor col;
};

#endif
