#pragma once
#include "ofMain.h"

class StandardGrid {
  public:
    void setup(int w, int h, int horizontalCount, int verticalCount);
    void draw();

  private:
    ofPolyline grid;
};