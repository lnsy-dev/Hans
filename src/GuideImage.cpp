#include "GuideImage.h"


void GuideImage::setup(int w, int h, string filePath) {
  loadImage(filePath);
  resizeImage(w, h);
}

void GuideImage::draw(){
  displayImage.draw(0,0);
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