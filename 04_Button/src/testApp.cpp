#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	ofBackground(255);

	ard.connect("/dev/tty.usbmodemfd121", 57600);
	//ard.connect("/dev/ttyUSB0", 57600);
	
	// listen for EInitialized notification. this indicates that
	// the arduino is ready to receive commands and it is safe to
	// call setupArduino()
	ofAddListener(ard.EInitialized, this, &testApp::setupArduino);


	bSetupArduino	= false;	// flag so we setup arduino when its ready, you don't need to touch this :)
}

//--------------------------------------------------------------
void testApp::update(){

	updateArduino();
    

}

//--------------------------------------------------------------
void testApp::setupArduino(const int & version) {
	
	// remove listener because we don't need it anymore
	ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
	ard.sendDigitalPinMode(02, ARD_INPUT);	
	bSetupArduino = true;
}

//--------------------------------------------------------------
void testApp::updateArduino(){

	// update the arduino, get any data or messages.
	ard.update();

    
    cout << ard.getDigital(2) << endl;
        
    

}


//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

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
	ard.sendDigital(13, ARD_HIGH);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	ard.sendDigital(13, ARD_LOW);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}