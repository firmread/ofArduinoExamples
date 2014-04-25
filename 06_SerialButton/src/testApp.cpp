#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	 

	ofSetVerticalSync(true);
	ofBackground(255,255,255);	
	ofSetLogLevel(OF_LOG_NOTICE);

	//----------------------------------- 
			
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	//----------------------------------- note:
	
		
	serial.setup(5, 57600); //open the first device

	posX = 100;
	posY = 100;
	
}

//--------------------------------------------------------------
void testApp::update(){

	
	if (serial.available()){

		while( (serial.readBytes( bytesReturned, 1)) > 0){
					
			if ( bytesReturned[0] == 1) {
				cout << "one"  << endl;
				serial.writeByte('a');
				 posX+= 3;
			}
		
		}
		
	}

	if(posX >= ofGetWidth()+30) posX = -30;
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofFill();
	ofSetColor(255, 0, 0);
	ofCircle(posX, posY, 30);


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
	bSendSerialMessage = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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

