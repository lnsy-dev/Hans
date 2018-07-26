#pragma once
#include "ofMain.h"

class standardGrid {
  public:
    void setup(int w, int h, int horizontalCount, int verticalCount);
    void draw();

  private:
    ofPolyline grid;
};