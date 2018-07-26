#pragma once
#include "ofMain.h"

class perspectivalGrid {
  public:
    void setup(int w, int h);
    void draw();

  private:
    ofPolyline grid;


};