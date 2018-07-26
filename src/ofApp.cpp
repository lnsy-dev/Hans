#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	windowWidth = ofGetWindowWidth();
	windowHeight = ofGetWindowHeight();
	warper.setup(0, 0, windowWidth, windowHeight); //initializates ofxGLWarper
	warper.activate();

	perspectiveGrid.setup(windowWidth, windowHeight);
	guideGrid.setup(windowWidth, windowHeight, 10, 10);
	ofBackground(0, 0, 0);

	loadImage("images/noimage.png");

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
			perspectiveGrid.draw();
			break;
		case grid:
			guideGrid.draw();
			break;
		case img:
			displayImage.draw(0,0);
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
	case 'h':
		SHOWHELP = !SHOWHELP;
		break;
	case 'o':
			{
			ofFileDialogResult openFileResult=ofSystemLoadDialog("Select a jpg or png");
			if (openFileResult.bSuccess){
				ofFile file (openFileResult.getPath());
				if (file.exists()){
					string fileExtension = ofToUpper(file.getExtension());
					if (fileExtension == "JPG" || fileExtension == "PNG") {
						loadImage(openFileResult.getPath());
						mode = img;
					}
				}
			}
			break;
		}
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


void ofApp::loadImage(string filePath){
	displayImage.load(filePath);

	displayImage.resize(windowWidth, windowHeight);
}

// Each mode should handle Arrow Keys differently
// @todo each mode needs to be abstracted out to its own class.
// Once that is done the switch statement mess won't be necessary.
void ofApp::handleArrowKeys(int key){
	ofLog(OF_LOG_NOTICE, ofToString(key));
	ofPoint translationVector;

}