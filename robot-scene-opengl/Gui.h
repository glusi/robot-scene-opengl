#pragma once
#include <GL/glut.h>
#include <GL\freeglut_ext.h>
#include <string>
#include "Vector3.h"

class Gui
{
	const Vector3 color_font = Vector3(0, 0, 0);
	bool camera_mode = true;
public:
	Gui();
	void draw();
	void drawText(float x, float y, std::string text, Vector3 color);
	void setMode(bool mode);
};

