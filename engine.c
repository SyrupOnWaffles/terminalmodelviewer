#include "engine.h"
#include <ncurses.h>
typedef struct Vector {
   float x;
   float y;
   float z;
} Vector;

typedef struct Triangle {
  float coordinates[9];
} Triangle;

//code taken from https://gist.github.com/JamesPhillipsUK/fae5f5bf1e62fdf4118ed37dbbc258d2 as my implementation couldnt stack
void drawLine(int x1, int y1, int x2, int y2)
{
  int dx, sx, dy, sy, gradientError, gradientErrorTwo;
  dx = abs(x2 - x1);/* Absolute integer value of the closest approximation of dx. */
  sx = x1 < x2 ? 1 : -1;/* 1 if positive gradient, -1 if not. */
  dy = abs(y2 - y1);/* Absolute integer value of the closest approximation of dy. */
  sy = y1 < y2 ? 1 : -1;/* 1 if positive gradient, -1 if not. */
  gradientError = (dx > dy ? dx : -dy) / 2;
  for(;;)
  {
    drawPoint(y1, x1);/* put a character in the current co-ordinate. */
    if (x1 == x2 && y1 == y2)/* If there's no line to be drawn, just draw a dot. */
      break;
    /* Calculate the position of the next co-ordinate on the line using Bresenham's Line Drawing Algorithm. */
    gradientErrorTwo = gradientError;
    if (gradientErrorTwo > -dx)
    {
      gradientError -= dy;
      x1 += sx;
    }
    if (gradientErrorTwo < dy)
    {
      gradientError += dx;
      y1 += sy;
    }
  }
}

void drawTriangle(int x1,int y1, int x2,int y2, int x3,int y3){
  drawLine(x1,y1,x2,y2);
  drawLine(x1,x1,x3,y3);
  drawLine(x3,y3,x2,y2);
}

void drawPoint(int x, int y){
  mvprintw(-y + 26,x*2+118,"AA");
}

void twoByThreeMatMul(float a[2][3], float b[3][1], float c[2][1]){
  for(int x = 0;x < 2;x++){
    float buffer = 0;
    for(int y = 0;y < 3; y++){
      buffer += b[y][0] * a[x][y];
    }
    c[x][0] = buffer;
 }
}
void threeByThreeMatMul(float a[3][3], float b[3][1], float c[3][1]){
  for(int x = 0;x < 3;x++){
    float buffer = 0;
    for(int y = 0;y < 3; y++){
      buffer += b[y][0] * a[x][y];
    }
    c[x][0] = buffer;
 }
}
void fourByFourMatMul(float a[4][4], float b[4][1], float c[4][1]){
  for(int x = 0;x < 4;x++){
    float buffer = 0;
    for(int y = 0;y < 4; y++){
      buffer += b[y][0] * a[x][y];
    }
    c[x][0] = buffer;
 }
}


