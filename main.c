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
  float fov = 90.0;
  float scaleFactor = 10;
  float fovRad = 1.0f / tanf(fov * 0.5f / 180.0f * 3.14159f);
  float aspectRatio = 236/54;
  float projection[2][3] = {{1,0,0},{0,1,0}};
  //
  float mesh[12][9] = {
		{ 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f },

		{ 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f },

		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f },

		{ 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f },
		{ 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f },

		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f },
  };

  //float cube[8][3] = {{1,1,0},{-1,1,0},{-1,-1,0},{1,-1,0},{1,1,-1},{-1,1,-1},{-1,-1,-1},{1,-1,-1}};
  initscr();
  curs_set(0);
  while(1){
    erase();
    //float rotationx[3][3] = {{1,0,0},{0,cos(angle),-sin(angle)},{0,sin(angle),cos(angle)}};
    //float rotationy[3][3] = {{cos(angle), 0, sin(angle)},{0,1,0},{-sin(angle),0,cos(angle)}};
    //float rotationz[3][3] = {{cos(angle),-sin(angle),0},{sin(angle),cos(angle),0},{0,0,1}};
    for(int i = 0; i < 12; ++i){
    //float v1[4][1] = {{cube[i][0]},{cube[i][1]},{cube[i][2]},1};
    //float v2[4][1] = {{mesh[i][0]},{mesh[i][1]},{mesh[i][2]},1};
    //float v3[4][1] = {{mesh[i][0]},{mesh[i][1]},{mesh[i][2]},1};
    float v1[3][1] = {{mesh[i][0]},{mesh[i][1]},{mesh[i][2]}};
    float v2[3][1] = {{mesh[i][3]},{mesh[i][4]},{mesh[i][5]}};
    float v3[3][1] = {{mesh[i][6]},{mesh[i][7]},{mesh[i][8]}};
    float p1[2][1],p2[2][1],p3[2][1];
    twoByThreeMatMul(projection,v1,p1);
    twoByThreeMatMul(projection,v2,p2);
    twoByThreeMatMul(projection,v3,p3);
    //drawPoint(p1[0][0]* scaleFactor,p1[1][0] * scaleFactor);
    drawTriangle(p1[0][0]*scaleFactor,p1[1][0]*scaleFactor,p2[0][0]*scaleFactor,p2[1][0]*scaleFactor,p3[0][0]*scaleFactor,p3[1][0]*scaleFactor);
   }
  refresh();
  }
  return 0;
}
