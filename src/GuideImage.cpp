#include "GuideImage.h"


void GuideImage::setup(int w, int h, string filePath) {
  loadImage(filePath);
  resizeImage(w, h);
  warpAmount.addListener(this, &GuideImage::warpAmountChanged);
  // warpCenter.addListener(this, &GuideImage::warpCenterChanged);
  gui.setup();
  gui.add(warpAmount.setup("warp amount", 140, 10, 300));
  gui.add(warpCenter.setup("warp center", ofVec2f(ofGetWidth()*.5, ofGetHeight()*.5), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
  gui.setPosition(ofGetWindowWidth(), 0);

}

void GuideImage::draw(){
  displayImage.draw(0,0);
}

void GuideImage::drawGui(){
  gui.draw();

}

void GuideImage::resizeImage(int w, int h){
  displayImage.resize(w, h);
}

void GuideImage::loadImage(){
  ofFileDialogResult openFileResult=ofSystemLoadDialog("Select a jpg or png");
  if (openFileResult.bSuccess){
    ofFile file (openFileResult.getPath());
    if (file.exists()){
      string fileExtension = ofToUpper(file.getExtension());
      if (fileExtension == "JPG" || fileExtension == "PNG") {
        loadImage(openFileResult.getPath());
      }
    }
  }
}

void GuideImage::loadImage(string filePath){
  displayImage.load(filePath);
}

void GuideImage::handleKeyPress(int key){
  switch(key) {
    case 'r':
      resizeImage(ofGetWindowWidth(), ofGetWindowHeight());
      break;
    case 'o':
      loadImage();
    default:
      break;
  }
}

void GuideImage::warpAmountChanged(float & warpAmount){

}

void GuideImage::warpCenterChanged(ofVec2f & warpCenter) {

}