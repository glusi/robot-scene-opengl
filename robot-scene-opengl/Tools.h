#pragma once
#define _USE_MATH_DEFINES
#include <math.h> 
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "Constants.h"
#include "Materials.h"
#include <string>
#include "../third-party/imgui/imgui_impl_glut.h"
#include "../third-party/imgui/imgui_impl_opengl3.h"
#include "../third-party/imgui/imgui.h"

static class Tools
{
public:
	static void drawCylinder(float radius, float halfLength, int slices);
	static void rotate(float angle, ROTATION_TYPE rotation_type);
	static void assignMaterial(materialStruct  material);
	static void copyColor(float** ambient_color, float* new_color);
	static std::string concatStrings(const char* one, const char* two);
	static void AlignForWidth(float width, float alignment = 0.5f);
};

