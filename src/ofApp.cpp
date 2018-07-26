#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	windowWidth = ofGetWindowWidth();
	windowHeight = ofGetWindowHeight();
	warper.setup(0, 0, windowWidth, windowHeight); //initializates ofxGLWarper
	warper.activate();

	perspectivalGrid.setup(windowWidth, windowHeight);
	guideGrid.setup(windowWidth, windowHeight, 10, 10);
	guideImage.setup(windowWidth, windowHeight, "images/no-image.png");
	hud.setup();

	ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	if(SHOWHELP){
		hud.draw();
	}

	warper.begin();
	warper.draw();
	switch (mode) {
		case perspective:
			perspectivalGrid.draw();
			break;
		case grid:
			guideGrid.draw();
			break;
		case img:
			guideImage.draw();
			break;
		default:
			break;
	}
		// put drawing code here
	warper.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	// ofLog(OF_LOG_NOTICE, ofToString(key));

	switch (key) {
	case 1:
		SHIFTKEYPRESSED = true;
		break;
	case 2:
		CTRLKEYPRESSED = true;
		break;
	case 'w':
		warper.toggleActive();
		break;
	case 'p':
		mode = perspective;
		break;
	case 'g':
		mode = grid;
		break;
	case 'i':
		mode = img;
		break;
	case 'h':
		SHOWHELP = !SHOWHELP;
		break;
	default:
		handleModuleKeys(key);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if(key == 3680 || key == 3681 ||key == 1){
		SHIFTKEYPRESSED = false;
	}

	if(key == 3683 || key == 3682 || key == 2){
		CTRLKEYPRESSED = false;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

// Each mode should handle Arrow Keys differently
// @todo each mode needs to be abstracted out to its own class.
// Once that is done the switch statement mess won't be necessary.
void ofApp::handleModuleKeys(int key){
	switch (mode) {
		case perspective:
			// perspectivalGrid.handleKeyPress(key);
			break;
		case grid:
			// guideGrid.handleKeyPress(key);
			break;
		case img:
			guideImage.handleKeyPress(key);
			break;
		default:
			break;
	}


}