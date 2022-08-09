#pragma once
#include "SceneItem.h"

class Lights : SceneItem
{
	GLfloat* point_light_color;
	GLfloat point_light_poistion[4];
	GLfloat* light_ambient;
	//GLfloat light_diffuse[4];
public:
	Lights();
	void draw();
	void adjustAmbientLight(float* color_new);
	float* getAmbientColor();
	float getPointLightPosition(POINT_LIGHT_POS axis);
	void applyPointLightPos(Vector3 point_light_position);
	GLfloat* getPointLightColor();
	void adjustPointLight(float* color);
	void drawOrb();
};

