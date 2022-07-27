#pragma once
#include "SceneItem.h"

class Lights : SceneItem
{
	GLfloat color[4];
	GLfloat position[4];
	GLfloat* light_ambient;
	GLfloat light_diffuse[4];
public:
	Lights();
	void draw();
	void adjustAmbientLight(float* color_new);
	float* getAmbientColor();
};

