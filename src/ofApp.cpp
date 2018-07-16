#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	warper.setup(0, 0, ofGetWidth(), ofGetHeight()); //initializates ofxGLWarper
	warper.activate();
	ofBackground(0, 0, 0);

	perspectivalGrid = generatePerspectivalGrid();
	guideGrid = generateGuideGrid();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	warper.begin();
	warper.draw();
	switch (mode) {
		case perspective:
			perspectivalGrid.draw();
			break;
		case grid:
			guideGrid.draw();
		case img:
			displayImage.draw(0,0);
		default:
			break;
	}
		// put drawing code here
	warper.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
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
	case 'o':
			{
			ofFileDialogResult openFileResult=ofSystemLoadDialog("Select a jpg or png");
			if (openFileResult.bSuccess){
				processOpenFileSelection(openFileResult);
			}
			break;
		}
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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

ofPolyline ofApp::generatePerspectivalGrid() {
	ofPolyline grid;

	ofPoint center;
	float horizontalPos = ofGetWidth() / 2;
	float verticalPos = ofGetHeight() / 2;

	center.set(horizontalPos, verticalPos);
	float i = 0;
	float r = ofGetWidth();

	if (ofGetHeight() > ofGetWidth()) {
		r = ofGetHeight();
	}


	while (i < TWO_PI) {
		float x = horizontalPos + cos(i) * r;
		float y = verticalPos + sin(i) * r;
		ofPoint point;
		point.set(x, y);
		grid.addVertex(center);
		grid.addVertex(point);
		i += HALF_PI * 0.2;
	}

	grid.close();
	return grid;
}

ofPolyline ofApp::generateGuideGrid() {
	ofPolyline grid;
	int width = ofGetWidth();
	int height = ofGetHeight();
	int horizontalCount = 20;
	int horizontalSize = width / horizontalCount;

	int verticalCount = 10;
	int verticalSize = height / verticalCount;

	ofPoint leftTopCorner;
	ofPoint rightTopCorner;
	ofPoint rightBottomCorner;
	ofPoint leftBottomCorner;

	leftTopCorner.set(0,0);
	rightTopCorner.set(width, 0);
	rightBottomCorner.set(width, height);
	leftBottomCorner.set(0, height);

	grid.addVertex(leftTopCorner);
	grid.addVertex(rightTopCorner);
	grid.addVertex(rightBottomCorner);
	grid.addVertex(leftBottomCorner);

	int i = 0;
	while (i < horizontalCount) {
		float x = horizontalSize * i;
		float y1 = 0;
		float y2 = height;
		ofPoint point1;
		ofPoint point2;
		point1.set(x, y1);
		point2.set(x, y2);

		if (i % 2 == 0) {
			grid.addVertex(point1);
			grid.addVertex(point2);
		}
		else {
			grid.addVertex(point2);
			grid.addVertex(point1);
		}
		i++;
	}

	i = 0;
	while (i < verticalCount) {
		float y = verticalSize * i;
		float x1 = 0;
		float x2 = width;
		ofPoint point1;
		ofPoint point2;
		point1.set(x1, y);
		point2.set(x2, y);

		if (i % 2 == 0) {
			grid.addVertex(point1);
			grid.addVertex(point2);
		}
		else {
			grid.addVertex(point2);
			grid.addVertex(point1);
		}
		i++;
	}

	grid.close();
	return grid;

}


void ofApp::processOpenFileSelection(ofFileDialogResult openFileResult){
	ofFile file (openFileResult.getPath());
	if (file.exists()){

		string fileExtension = ofToUpper(file.getExtension());
		if (fileExtension == "JPG" || fileExtension == "PNG") {
			displayImage.load(openFileResult.getPath());
			displayImage.resize(500,500);

			// int w = displayImage.getWidth();
			// int h = displayImage.getHeight();
			// int newRatio;
			// int newHeight;
			// int newWidth;

			// if(w > ofGetWidth()){
			// 	newRatio = ofGetWidth() / w;
			// 	newHeight = h * newRatio;
			// 	newWidth = ofGetWidth();
			// 	displayImage.resize(newWidth, newHeight);
			// }

			// if(h > ofGetHeight()){
			// 	newRatio = ofGetHeight() / h;
			// 	newHeight = ofGetHeight();
			// 	newWidth = w * newRatio;
			// 	displayImage.resize(newWidth, newHeight);
			// }
		}
	}
}