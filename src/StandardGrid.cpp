#include "StandardGrid.h"

void StandardGrid::setup(int w, int h, int horizontalCount, int verticalCount){
  grid.clear();

  int width = w;
  int height = h;

  int horizontalSize = width / horizontalCount;
  int verticalSize = height / verticalCount;

  ofPoint leftTopCorner;
  ofPoint rightTopCorner;
  ofPoint rightBottomCorner;
  ofPoint leftBottomCorner;

  leftTopCorner.set(0,0);
  rightTopCorner.set(width, 0);
  rightBottomCorner.set(width, height);
  leftBottomCorner.set(0, height);

  grid.addVertex(leftTopCorner);
  grid.addVertex(rightTopCorner);
  grid.addVertex(rightBottomCorner);
  grid.addVertex(leftBottomCorner);

  int i = 0;
  while (i < horizontalCount) {
    float x = horizontalSize * i;
    float y1 = 0;
    float y2 = height;
    ofPoint point1;
    ofPoint point2;
    point1.set(x, y1);
    point2.set(x, y2);

    if (i % 2 == 0) {
      grid.addVertex(point1);
      grid.addVertex(point2);
    }
    else {
      grid.addVertex(point2);
      grid.addVertex(point1);
    }
    i++;
  }

  i = 0;
  while (i < verticalCount) {
    float y = verticalSize * i;
    float x1 = 0;
    float x2 = width;
    ofPoint point1;
    ofPoint point2;
    point1.set(x1, y);
    point2.set(x2, y);

    if (i % 2 == 0) {
      grid.addVertex(point1);
      grid.addVertex(point2);
    }
    else {
      grid.addVertex(point2);
      grid.addVertex(point1);
    }
    i++;
  }

  grid.close();
}

void StandardGrid::draw(){
  grid.draw();
}