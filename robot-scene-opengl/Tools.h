#pragma once
#define _USE_MATH_DEFINES
#include <math.h> 
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "Constants.h"

static class Tools
{
public:
	static void drawCylinder(float radius, float halfLength, int slices);
	static void rotate(float angle, ROTATION_TYPE rotation_type);
};
