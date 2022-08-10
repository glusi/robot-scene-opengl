#pragma once
#include <GL/glut.h>
#include <GL\freeglut_ext.h>
#include <string>
#include "Vector3.h"

class Gui
{
	//Font color
	const Vector3 color_font = Vector3(0, 0, 0);
	//Camera mode flag
	bool camera_mode = true;
public:
	/**
	 * draw a 2D canvas with current mode
	 * 
	 */
	void draw();
	/**
	 * draws a realizable text
	 * 
	 * \param x - x position to draw text in
	 * \param y - y position to draw text in
	 * \param text - the string to be drawn
	 * \param color - the color of string to be drawn
	 */
	void drawText(float x, float y, std::string text, Vector3 color);
	void setMode(bool mode);
};

