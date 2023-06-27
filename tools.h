#pragma once

#include <GL/glut.h> 
#include <math.h>
#include "color.h"
#include <time.h>

class Tools{
public:
	static float RandomNumber(float M, float N);
	static void DrawCircle(float x, float y, float radius, Color color);
	static void DrawRectangle(float x, float y, float width, float height, Color color);
	static double ShortestDistance(float x1,float y1,float x2,float y2,float x3,float y3);
};
