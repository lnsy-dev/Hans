#pragma once
#include "ofMain.h"
#include "ofxGui.h"


class GuideImage {
  public:
    void setup(int w, int h, string filePath);
    void draw();
    void drawGui();
    void loadImage();
    void loadImage(string filePath);
    void resizeImage(int w, int h);
    void handleKeyPress(int key);
    void warpAmountChanged(float & warpAmount);
    void warpCenterChanged(ofVec2f & warpCenter);

  private:
    ofImage displayImage;
    ofxFloatSlider warpAmount;
    ofxVec2Slider warpCenter;
    ofxPanel gui;

};