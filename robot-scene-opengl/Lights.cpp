#include "Lights.h"

Lights::Lights() :
	//light_diffuse { 0.8, 0.8, 0.8, 1.0 },
	//point_light_color{ 0.9f, 0.9f, 0.3f , 1.0f },
	point_light_poistion{ 0.0f, 12.0f, -1.0f , 1.0f } {
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
	GLfloat light_pos[] = { 0.0, 2.0, 9.0, 1.0 };
	//glEnable(GL_LIGHTING);
	if (ambient_enabled) {
		glEnable(GL_LIGHT0);
		light_ambient[3] = 1.0;
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	}
	else {
		glDisable(GL_LIGHT0);
	}
	//GLfloat position0[] = { 0.0, 5.0, 1.0, 1.0 };
	//GLfloat diffuse0[] = { 0.5f, 0.5f, 0.5f };
	//GLfloat specular0[] = { 1.0f, 1.0f, 1.0f };
	//GLfloat ambient0[] = { 0.2f, 0.2f, 0.2f };
//	glEnable(GL_LIGHTING);
	if (point_enabled) {
		glEnable(GL_LIGHT1);
		point_light_poistion[3] = 1.0;
		glLightfv(GL_LIGHT1, GL_POSITION, point_light_poistion);
		point_light_color[3] = 1.0;
		glLightfv(GL_LIGHT1, GL_DIFFUSE, point_light_color);
		glLightfv(GL_LIGHT1, GL_SPECULAR, point_light_color);
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 180.0f);
	}
	else {
		glDisable(GL_LIGHT1);
	}

	//glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse0);
	//glLightfv(GL_LIGHT1, GL_SPECULAR, specular0);
	//glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);

	/*GLfloat diffu[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat spec[] = { 0.5f, 0.5f, 0.5f, 0.5f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffu);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spec);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);*/

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
	//draw orb
	glPushMatrix();
	Tools::assignMaterial(glass);
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
