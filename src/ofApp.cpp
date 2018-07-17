#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	warper.setup(0, 0, ofGetWidth(), ofGetHeight()); //initializates ofxGLWarper
	warper.activate();
	ofBackground(0, 0, 0);

	loadImage("images/noimage.png");

	perspectivalGrid = generatePerspectivalGrid();
	guideGrid = generateGuideGrid(10,10);
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

void ofApp::translatePerspectivalGrid(ofPoint vctr) {
	perspectivalGrid.translate(vctr);
}

ofPolyline ofApp::generateGuideGrid(int horizontalCount, int verticalCount) {
	ofPolyline grid;
	int width = ofGetWidth();
	int height = ofGetHeight();

	// save the values for translations
	// for later user
	// @todo: refactor all modes into thier own classes
	guideGridHCount = horizontalCount;
	guideGridVCount = verticalCount;

	int horizontalSize = width / horizontalCount;
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

void ofApp::loadImage(string filePath){
	displayImage.load(filePath);

	displayImage.resize(ofGetWidth(), ofGetHeight());
}

// Each mode should handle Arrow Keys differently
// @todo each mode needs to be abstracted out to its own class.
// Once that is done the switch statement mess won't be necessary.
void ofApp::handleArrowKeys(int key){
	ofLog(OF_LOG_NOTICE, ofToString(key));
	ofPoint translationVector;
	switch (mode) {
		case perspective:
			{
				switch (key) {
					case OF_KEY_UP:
						{
							translationVector.set(0,-5);
							translatePerspectivalGrid(translationVector);
							break;
						}
					case OF_KEY_DOWN:
						{
							translationVector.set(0,5);
							translatePerspectivalGrid(translationVector);
							break;
						}
					case OF_KEY_LEFT:
						{
							translationVector.set(-5,0);
							translatePerspectivalGrid(translationVector);
							break;
						}
					case OF_KEY_RIGHT:
						{
							translationVector.set(5,0);
							translatePerspectivalGrid(translationVector);
							break;
						}
				}
			}
		case grid:
			{
				switch (key) {
					case OF_KEY_UP:
						{
							guideGridVCount++;
							guideGrid = generateGuideGrid(guideGridHCount, guideGridVCount);
							break;
						}
					case OF_KEY_DOWN:
						{
							if(guideGridVCount < 1){
								guideGridVCount = 0;
							} else {
								guideGridVCount--;

							}
							guideGrid = generateGuideGrid(guideGridHCount, guideGridVCount);
							break;
						}
					case OF_KEY_LEFT:
						{
							if(guideGridHCount < 1){
								guideGridHCount = 0;
							} else {
								guideGridHCount--;

							}
							guideGrid = generateGuideGrid(guideGridHCount, guideGridVCount);
							break;
						}

					case OF_KEY_RIGHT:
						{
							guideGridHCount++;
							guideGrid = generateGuideGrid(guideGridHCount, guideGridVCount);
							break;
						}
				}
				break;
			}
		case img:
			{
				switch (key) {
					case OF_KEY_UP:
							break;
					case OF_KEY_DOWN:
						break;
					case OF_KEY_LEFT:
						break;
					case OF_KEY_RIGHT:
						break;
				}
				break;
			}
	}

}