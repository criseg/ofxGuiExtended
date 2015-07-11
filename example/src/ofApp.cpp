#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    panel1.setup("extended gui");

    panel1.add(new ofxMinimalToggle(toggle_param.set("toggle group header", true), 0, 30));
    toggle_param.addListener(this, &ofApp::toggleGroupHeader);
    panel1.add(new ofxMinimalButton("button", 0, 30));

    rotary.setup("rotary");
    rotary.setBorderColor(ofColor::blanchedAlmond);
    rotary.add(new ofxFloatRotarySlider(slider_param.set("slider", 0.5, 0, 1), 66,66));
    rotary.getControl("slider")->setFillColor(ofColor::white);
    rotary.getControl("slider")->setBackgroundColor(ofColor::blanchedAlmond - ofColor(130));

    matrix.setup("matrix");
    matrix.setBorderColor(ofColor::aquamarine);
    matrix.setColNum(3);
    matrix.setElementHeight(26);
    matrix.allowMultipleActiveToggles(false);
    matrix_params.push_back(ofParameter<bool>("only",false));
    matrix_params.push_back(ofParameter<bool>("one",false));
    matrix_params.push_back(ofParameter<bool>("toggle",false));
    matrix_params.push_back(ofParameter<bool>("can",false));
    matrix_params.push_back(ofParameter<bool>("be",false));
    matrix_params.push_back(ofParameter<bool>("active",false));
    for(uint i = 0; i < matrix_params.size(); i++) {
        matrix.add(new ofxMinimalToggle(matrix_params.at(i)));
    }

    panel1.add(&rotary);
    panel1.add(&matrix);

    panel2.setup("horizontal", "", 260, 10);
    panel2.setAlignHorizontal();
    panel2.setBackgroundColor(ofColor::black);
    panel2.add(new ofxToggle(toggle1_param.set("toggle1", false), 100, 30));
    panel2.add(new ofxMinimalToggle(toggle2_param.set("toggle2", false), 0, 30));
    panel2.add(new ofxMinimalToggle(toggle3_param.set("toggle3", false), 0, 30));
    panel2.add(new ofxMinimalToggle(toggle4_param.set("toggle4", false), 0, 30));

}

//--------------------------------------------------------------
void ofApp::exit() {
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw(){

    if(toggle1_param.get()) {
        ofSetColor(ofColor::royalBlue);
    }
    else {
        if(toggle2_param.get()) {
            ofSetColor(ofColor::azure);
        }
        else {
            ofSetColor(ofColor::black);
        }
    }

    ofDrawRectangle(ofGetWindowRect());

    ofSetColor(255);

    panel1.draw();
    panel2.draw();

}

void ofApp::toggleGroupHeader(bool &val) {
    rotary.showHeader(val);
    matrix.showHeader(val);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key) {
    case 'f': {
        ofToggleFullscreen();
        break;
    }
    case 't': {
        cout << panel1.getHeight() << endl;
    }
    default: break;
    }
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(ofMouseEventArgs &args){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(ofMouseEventArgs &args){
}

//--------------------------------------------------------------
void ofApp::mousePressed(ofMouseEventArgs &args){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(ofMouseEventArgs &args){
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	
}