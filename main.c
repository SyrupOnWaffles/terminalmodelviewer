#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "engine.c"
#include "engine.h"
#include <math.h>
#include <stdio.h>
int main( int argc, char *argv[] ){
  //Projection Matricies
  float angle = 45;
  float projection[2][3] = {{1,0,0},{0,1,0}};
  //
  Vector v[8] = {{-10,-10,10},{-10,10,10},{10,10,10},{10,-10,10},{-10,-10,-10},{-10,10,-10},{10,10,-10},{10,-10,-10}};
  float projected2D[2][1];
  initscr();
  curs_set(0);
  while(1){
    angle += 0.00005;
    erase();
    float rotationx[3][3] = {{1,0,0},{0,cos(angle),-sin(angle)},{0,sin(angle),cos(angle)}};
    float rotationy[3][3] = {{cos(angle), 0, sin(angle)},{0,1,0},{-sin(angle),0,cos(angle)}};
    float rotationz[3][3] = {{cos(angle),-sin(angle),0},{sin(angle),cos(angle),0},{0,0,1}};
    //drawLine(0,0,1,5);
   for(int i = 0; i < 8; ++i){
    float vector[3][1] = {{v[i].x},{v[i].y},{v[i].z}};
    //apply rotations
    //threeByThreeMatMul(rotationx,vector,vector);
    threeByThreeMatMul(rotationy,vector,vector);
    //threeByThreeMatMul(rotationz,vector,vector);

    twoByThreeMatMul(projection,vector,projected2D);
    drawPoint(projected2D[0][0],projected2D[1][0]);
    //drawPoint(v[i].x,v[i].y);
   }
  refresh();
  }
  return 0;
}
