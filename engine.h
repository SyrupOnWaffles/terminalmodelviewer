#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
void drawLine(int x1, int y1, int x2, int y2, short color);
void drawTriangle(int x1,int y1, int x2,int y2, int x3,int y3, short color);
void drawFilledTriangle(int x1,int y1, int x2,int y2, int x3,int y3, short color);
void drawPoint(int x, int y, short color);
void twoByThreeMatMul(float a[2][3], float b[3][1], float c[2][1]);
void simpleProjection(float a[2][3], float b[3][1], float c[2][1], float distance);
void threeByThreeMatMul(float a[3][3], float b[3][1], float c[3][1]);
void fourByFourMatMul(float a[4][4], float b[4][1],float c[4][1]);
double degToRad(float degree);
typedef struct Vector Vector;
typedef struct Triangle Triangle;
#endif
