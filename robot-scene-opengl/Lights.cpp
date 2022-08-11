#include "Lights.h"

Lights::Lights() :
	//point light initial position
	point_light_poistion{ 0.0f, 12.0f, -1.0f , 1.0f } {
	//initialize colors of lights
	light_ambient = new GLfloat[4];
	point_light_color = new GLfloat[4];
	for (int i=0; i<4; i++)
		light_ambient[i] = 0.5;
	point_light_color[0] = 0.9;
	point_light_color[1] = 0.9;
	point_light_color[2] = 0.3;
	point_light_color[3] = 0.5;
}


void Lights::draw() {
	//Ambient light draw
	if (ambient_enabled) {
		glEnable(GL_LIGHT0);
		light_ambient[3] = 1.0;
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	}
	else {
		glDisable(GL_LIGHT0);
	}
	//Point light draw
	if (point_enabled) {
		glEnable(GL_LIGHT1);
		//Set alpha
		point_light_poistion[3] = 1.0;
		glLightfv(GL_LIGHT1, GL_POSITION, point_light_poistion);
		//Set alpha
		point_light_color[3] = 1.0;
		glLightfv(GL_LIGHT1, GL_DIFFUSE, point_light_color);
		glLightfv(GL_LIGHT1, GL_SPECULAR, point_light_color);
		//uniform light distribution
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 180.0f);
	}
	else {
		glDisable(GL_LIGHT1);
	}
	glShadeModel(GL_SMOOTH);
}

void Lights::adjustAmbientLight(float* color)
{
	Tools::copyColor(&light_ambient, color);
}

float* Lights::getAmbientColor()
{
	return light_ambient;
}

float Lights::getPointLightPosition(POINT_LIGHT_POS axis)
{
	float res = 0;
	switch (axis)
	{
	case POINT_LIGHT_X: res = point_light_poistion[0]; break;
	case POINT_LIGHT_Y: res = point_light_poistion[1]; break;
	case POINT_LIGHT_Z: res = point_light_poistion[2]; break;
	default:
		break;
	}
	return res;
}

void Lights::applyPointLightPos(Vector3 point_light_position)
{
	this->point_light_poistion[0] = point_light_position.x;
	this->point_light_poistion[1] = point_light_position.y;
	this->point_light_poistion[2] = point_light_position.z;
}

GLfloat* Lights::getPointLightColor()
{
	return point_light_color;
}

void Lights::adjustPointLight(float* color)
{
	Tools::copyColor(&point_light_color, color);
}

void Lights::drawOrb()
{
	//draw orb in the place of point light
	glPushMatrix();
	Tools::assignMaterial(glass, 1);
	glTranslatef(point_light_poistion[0] - 0.25, point_light_poistion[1] - 0.25, point_light_poistion[2] - 0.25);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();
}

void Lights::disableAmbient(bool enabled)
{
	ambient_enabled = enabled;
}

void Lights::disablePoint(bool enabled)
{
	point_enabled = enabled;
}
