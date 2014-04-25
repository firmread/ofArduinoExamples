#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofEnableAlphaBlending(); 

	ofBackground(0);

	ard.connect("/dev/tty.usbmodemfd121", 57600);
	//ard.connect("/dev/ttyUSB0", 57600);
	
	// listen for EInitialized notification. this indicates that
	// the arduino is ready to receive commands and it is safe to
	// call setupArduino()
	ofAddListener(ard.EInitialized, this, &testApp::setupArduino);


	bSetupArduino	= false;	// flag so we setup arduino when its ready, you don't need to touch this :)
    
    mouse_pressed = false; 
    gravity = 0.1; 
    friction = 0.999;
    
    
    for(int i = 0; i < NUM; i++){
        loc_x[i] = ofGetWidth() / 2; 
        loc_y[i] = ofGetHeight() / 2; 
        speed_x[i] = ofRandom(-10, 10); 
        speed_y[i] = ofRandom(-10, 10); 
        radius[i] = ofRandom(1, 10); 
        red[i] = ofRandom(0, 255);
        green[i] = ofRandom(0, 255); 
        blue[i] = ofRandom(0, 255); 
    }
    
    ardButtonPressed = false;


}

//--------------------------------------------------------------
void testApp::update(){

	updateArduino();
    
    for(int i = 0; i < NUM; i++){
        
        if(mouse_pressed){
            speed_x[i] = (ofGetWidth()/2- loc_x[i]) / 8.0;
            speed_y[i] = (ofGetHeight()/2 - loc_y[i]) / 8.0;
        }
        
        speed_x[i] = speed_x[i] * friction;
        speed_y[i] = speed_y[i] * friction;
        speed_y[i] = speed_y[i] + gravity;
        
        loc_x[i] = loc_x[i] + speed_x[i]; 
        loc_y[i] = loc_y[i] + speed_y[i]; 
        
        if(loc_x[i] < 0){
            loc_x[i] = 0;
            speed_x[i] = speed_x[i] * -1.0;
        }
        if(loc_x[i] > ofGetWidth()){
            loc_x[i] = ofGetWidth();
            speed_x[i] = speed_x[i] * -1.0;
        }
        if(loc_y[i] < 0){
            loc_y[i] = 0;
            speed_y[i] = speed_y[i] * -1.0;
        }
        if(loc_y[i] > ofGetHeight()){
            loc_y[i] = ofGetHeight();
            speed_y[i] = speed_y[i] * -1.0;
        }
    }
    
    int buttonState = ard.getDigital(2);
    if(buttonState == true){
        mouse_pressed    = true; 

    } else     if(buttonState == false){
        mouse_pressed = false; 
       
    }
        

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

}


//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0, 23);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    for(int i = 0; i < NUM; i++){
        ofSetColor(red[i], green[i], blue[i], 127); 
        ofCircle(loc_x[i], loc_y[i], radius[i]); 
    }
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
    mouse_pressed = true; 
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    mouse_pressed = false; 
    
    for(int i = 0; i < NUM; i++){
        speed_x[i] = ofRandom(-10, 10); 
        speed_y[i] = ofRandom(-10, 10); 
    }
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