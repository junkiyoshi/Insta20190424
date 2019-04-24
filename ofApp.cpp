#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 15, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int x = 0; x < ofGetWidth(); x += 15) {

		for (int y = 15; y <= ofGetHeight(); y += 15) {

			char noise_value = ofMap(ofNoise(x * 0.008, y * 0.008, ofGetFrameNum() * 0.003), 0, 1, 45, 110);
			if (noise_value >= 'A' && noise_value <= 'Z') {
			
				this->font.drawString({ noise_value }, x, y);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}