#include "engine.h"
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
typedef struct Triangle {
  float coordinates[9];
} Triangle;
int offsetX, offsetY;
//code taken from https://gist.github.com/JamesPhillipsUK/fae5f5bf1e62fdf4118ed37dbbc258d2 as my implementation couldnt stack
void drawLine(int x1, int y1, int x2, int y2, short color)
{
  int dx, sx, dy, sy, gradientError, gradientErrorTwo;
  dx = abs(x2 - x1);/* Absolute integer value of the closest approximation of dx. */
  sx = x1 < x2 ? 1 : -1;/* 1 if positive gradient, -1 if not. */
  dy = abs(y2 - y1);/* Absolute integer value of the closest approximation of dy. */
  sy = y1 < y2 ? 1 : -1;/* 1 if positive gradient, -1 if not. */
  gradientError = (dx > dy ? dx : -dy) / 2;
  for(;;)
  {
    drawPoint(y1, x1, color);/* put a character in the current co-ordinate. */
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

void drawTriangle(int x1,int y1, int x2,int y2, int x3,int y3, short color){
  drawLine(x1,y1,x2,y2,color);
  drawLine(x2,y2,x3,y3,color);
  drawLine(x3,y3,x1,y1,color);
}

// implementation from https://gamedev.stackexchange.com/questions/178181/how-can-i-draw-filled-triangles-in-c. fuck rasterization can be a bitch
void drawFilledTriangle(int x1,int y1, int x2,int y2, int x3,int y3, short color){

}


void drawPoint(int x, int y, short color){
  start_color();
  init_pair(1, color, color); /* create foreground / background combination */
  attron(COLOR_PAIR(1)); /* use the above combination */
  mvprintw(-y + offsetY,x*2+offsetX,"..");
  attroff(COLOR_PAIR(1)); /* turn color off */
}
//for perspective proj rn
void simpleProjection(float a[2][3], float b[3][1], float c[2][1], float distance){
  for(int x = 0;x < 2;x++){
    float buffer = 0;
    for(int y = 0;y < 3; y++){
      //scuffed way but its alright
      buffer += (b[y][0] * a[x][y]) * 1 / (distance - b[2][0]);
    }
    c[x][0] = buffer;
 }
}

void twoByThreeMatMul(float a[2][3], float b[3][1], float c[2][1]){
  for(int x = 0;x < 2;x++){
    float buffer = 0;
    for(int y = 0;y < 3; y++){
      buffer += (b[y][0] * a[x][y]);
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

double degToRad(float degree){
return degree * 0.01745329251;
}
