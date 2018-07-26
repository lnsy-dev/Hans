#pragma once
#include "ofMain.h"

class PerspectivalGrid {
  public:
    void setup(int w, int h);
    void draw();

  private:
    ofPolyline grid;
};