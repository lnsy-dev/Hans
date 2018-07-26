#pragma once

#include "ofMain.h"
#include "warper.h"
#include "perspectivalGrid.h"


class ofApp : public ofBaseApp{

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void drawHelpText();
		bool SHOWHELP = true;

		enum Mode {perspective, grid, img};
		Mode mode = perspective;

		ofxGLWarper warper;

		perspectivalGrid perspectiveGrid;

		ofPolyline generateGuideGrid(int hCount, int vCount);
		int guideGridHCount;
		int guideGridVCount;

		ofPolyline guideGrid;

		bool SHIFTKEYPRESSED = false;
		bool CTRLKEYPRESSED = false;

		void handleArrowKeys(int key);

		void loadImage(string filePath);
		ofImage displayImage;

		int windowWidth = 2736;
		int windowHeight = 1824;
};
