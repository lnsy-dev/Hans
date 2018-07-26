#pragma once
#include "ofMain.h"

class GuideImage {
  public:
    void setup(int w, int h, string filePath);
    void draw();
    void loadImage();
    void loadImage(string filePath);
    void resizeImage(int w, int h);

  private:
    ofImage displayImage;
};