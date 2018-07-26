#pragma once

#include "ofMain.h"
#include "warper.h"
#include "PerspectivalGrid.h"
#include "StandardGrid.h"
#include "GuideImage.h"
#include "Hud.h"


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

	private:
		bool SHOWHELP = true;
		Hud hud;

		enum Mode {perspective, grid, img};
		Mode mode = perspective;

		ofxGLWarper warper;

		PerspectivalGrid perspectivalGrid;
		StandardGrid guideGrid;
		GuideImage guideImage;

		bool SHIFTKEYPRESSED = false;
		bool CTRLKEYPRESSED = false;

		void handleModuleKeys(int key);

		int windowWidth = ofGetWindowWidth();
		int windowHeight = ofGetWindowHeight();
};
