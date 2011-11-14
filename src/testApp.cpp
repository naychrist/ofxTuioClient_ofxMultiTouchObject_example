#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(200, 200, 200);
	ofSetVerticalSync(true);
	
	//Connect to Port
	myTuio.connect(3333);
	
	//init buttons
	button.setSize(100, 100);
	button.registerForMultitouchEvents();
	buttonTwo.setPos(400, 300);
	buttonTwo.setSize(100, 100);
	buttonTwo.registerForMultitouchEvents();
	markerButton.setPos(600,500);
	markerButton.setSize(60,60);
	markerButton.registerForMarkerEvents();
	
	//add button event listener for global callback function in testApp
	ofAddListener(buttonTwo.eMultiTouchUp,this,&testApp::buttonTwoCallback);
	
	//Assign Global TUIO Callback Functions
	ofAddListener(myTuio.objectAdded,this,&testApp::tuioObjectAdded);
	ofAddListener(myTuio.objectRemoved,this,&testApp::tuioObjectRemoved);
	ofAddListener(myTuio.objectUpdated,this,&testApp::tuioObjectUpdated);
	ofAddListener(myTuio.cursorAdded,this,&testApp::tuioCursorAdded);
	ofAddListener(myTuio.cursorRemoved,this,&testApp::tuioCursorRemoved);
	ofAddListener(myTuio.cursorUpdated,this,&testApp::tuioCursorUpdated);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	//render the three example buttons
    button.render();
	buttonTwo.render();
	markerButton.render();
	
	//render TUIO Cursors and Objects
	myTuio.drawCursors();
	myTuio.drawObjects();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

void testApp::tuioObjectAdded(TuioObject & tobj){
/*	cout << " object added: " + ofToString(tobj.getSymbolID())+
	" X: "+ofToString(tobj.getX())+
	" Y: "+ofToString(tobj.getY())+
	" angle: "+ofToString(tobj.getAngleDegrees())
	<< endl;*/
	
	//forward the marker events to ofxMarker for the InteractiveObjects
	ofxMarker.markerDown(tobj.getSymbolID(), tobj.getX(), tobj.getY(), tobj.getAngleDegrees());
}

void testApp::tuioObjectRemoved(TuioObject & tobj){
/*	cout << " object removed: " + ofToString(tobj.getSymbolID())+
	" X: "+ofToString(tobj.getX())+
	" Y: "+ofToString(tobj.getY())+
	" angle: "+ofToString(tobj.getAngleDegrees())
	<< endl;*/
	
	//forward the marker events to ofxMarker for the InteractiveObjects
	ofxMarker.markerUp(tobj.getSymbolID(), tobj.getX(), tobj.getY(), tobj.getAngleDegrees());
}

void testApp::tuioObjectUpdated(TuioObject & tobj){
	/*cout << " object updated: " + ofToString(tobj.getSymbolID())+
	" X: "+ofToString(tobj.getX())+
	" Y: "+ofToString(tobj.getY())+
	" angle: "+ofToString(tobj.getAngleDegrees())
	<< endl;*/
	
	//forward the marker events to ofxMarker for the InteractiveObjects
	ofxMarker.markerMoved(tobj.getSymbolID(), tobj.getX(), tobj.getY(), tobj.getAngleDegrees());
}

void testApp::tuioCursorAdded(TuioCursor & tcur){
	/*cout << " cursor added: " + ofToString(tcur.getCursorID())+
	" X: "+ofToString(tcur.getX())+
	" Y: "+ofToString(tcur.getY())
	<< endl;*/
	
	//forward the touch events to ofxMultiTouch for the InteractiveObjects
	ofxMultiTouch.touchDown(tcur.getX(), tcur.getY(), tcur.getCursorID(), NULL);
}

void testApp::tuioCursorRemoved(TuioCursor & tcur){
	/*cout << " cursor removed: " + ofToString(tcur.getCursorID())+
	 " X: "+ofToString(tcur.getX())+
	 " Y: "+ofToString(tcur.getY())
	 << endl;*/
	
	//forward the touch events to ofxMultiTouch for the InteractiveObjects
	ofxMultiTouch.touchUp(tcur.getX(), tcur.getY(), tcur.getCursorID(), NULL);
}

void testApp::tuioCursorUpdated(TuioCursor & tcur){
	/*cout << " cursor updated: " + ofToString(tcur.getCursorID())+
	 " X: "+ofToString(tcur.getXSpeed())+
	 " Y: "+ofToString(tcur.getYSpeed())
	 << endl;*/
	
	//forward the touch events to ofxMultiTouch for the InteractiveObjects
	ofxMultiTouch.touchMoved(tcur.getX(), tcur.getY(), tcur.getCursorID(), NULL);
}

//button Two Callback
void testApp::buttonTwoCallback(ofEventArgs & voidArgs){
	ofBackground(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
}

