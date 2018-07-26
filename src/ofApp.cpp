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

	ofBackground(0, 0, 0);


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if(SHOWHELP){
		stringstream ss;
		ss << "(p): Perspective Mode"<<endl;
		ss << "(g): Grid Mode"<<endl;
		ss << "(i): Image Mode"<<endl;
		ss << "(o): Open an Image" <<endl;
		ss << "(w): Toggle Warp Corners" << endl;
		ss << "(h): Toggle this dialog"<<endl;
		ofDrawBitmapStringHighlight(ss.str().c_str(), 20, 20);
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
	case OF_KEY_LEFT:
	case OF_KEY_RIGHT:
	case OF_KEY_DOWN:
	case OF_KEY_UP:
		handleArrowKeys(key);
		break;
	case 'w':
		if (warper.isActive()) {
			warper.deactivate();
		}
		else {
			warper.activate();
		}

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
	case 'r':
		{
			perspectivalGrid.setup(windowWidth, windowHeight);
			guideGrid.setup(windowWidth, windowHeight, 10, 10);
			guideImage.resizeImage(windowWidth, windowHeight);
			break;
		}
	case 'h':
		SHOWHELP = !SHOWHELP;
		break;
	case 'o':
		guideImage.loadImage();
		break;
	default:
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
void ofApp::handleArrowKeys(int key){
	ofLog(OF_LOG_NOTICE, ofToString(key));
	ofPoint translationVector;

}