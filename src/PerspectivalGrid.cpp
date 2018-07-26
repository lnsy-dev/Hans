#include "PerspectivalGrid.h"

void PerspectivalGrid::setup(int w, int h){

  ofPoint center;
  float horizontalPos = w / 2;
  float verticalPos = h / 2;

  center.set(horizontalPos, verticalPos);

  float i = 0;
  float r = w;

  if (h > w) {
    r = h;
  }

  while (i < TWO_PI) {
    float x = horizontalPos + cos(i) * r;
    float y = verticalPos + sin(i) * r;
    ofPoint point;
    point.set(x,y);
    grid.addVertex(center);
    grid.addVertex(point);
    i += HALF_PI * 0.2;
  }

  grid.close();
}

void PerspectivalGrid::draw(){
  grid.draw();
}