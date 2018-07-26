#include "Hud.h"

void Hud::setup(){

    helptext << "(p): Perspective Mode"<<endl;
    helptext << "(g): Grid Mode"<<endl;
    helptext << "(i): Image Mode"<<endl;
    helptext << "(w): Toggle Warp Corners" << endl;
    helptext << "(h): Toggle this dialog"<< endl;
    helptext << "(r): Reset Warp and Mode" << endl;

}

void Hud::draw(){
  ofDrawBitmapStringHighlight(helptext.str().c_str(), 20, 20);

}