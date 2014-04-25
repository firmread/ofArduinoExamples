#pragma once
#define NUM 1000

#include "ofMain.h"
#include "ofEvents.h"


class testApp : public ofSimpleApp{

public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
		
	void setupArduino(const int & version);
	void updateArduino();

	ofArduino	ard;
	bool		bSetupArduino;			// flag variable for setting up arduino once

    float loc_x[NUM]; 
    float loc_y[NUM]; 
    float speed_x[NUM]; 
    float speed_y[NUM]; 
    float radius[NUM]; 
    int red[NUM]; 
    int green[NUM];
    int blue[NUM]; 
    bool mouse_pressed; 
    float gravity;
    float friction;
    
    bool ardButtonPressed;
    bool explosion;
    
};

