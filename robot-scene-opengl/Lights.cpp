#include "Lights.h"

Lights::Lights() :
	light_ambient {1.0, 1.0, 1.0, 1.0},
	light_diffuse { 0.8, 0.8, 0.8, 1.0 },
	color{ 0.9f, 0.9f, 0.3f , 1.0f },
	position{ 0.0f, 3.0f, -1.0f , 0.0f } {}


void Lights::draw() {
	GLfloat light_pos[] = { 0.0, 2.0, 5.0, 1.0 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	GLfloat position0[] = { 0.0, 5.0, 1.0, 1.0 };
	GLfloat diffuse0[] = { 1.0, 1.0, 1.0, 1.0 }; // Id term - Red
	GLfloat specular0[] = { 1.0, 1.0, 1.0, 1.0 }; // Is term - White
	GLfloat ambient0[] = { 0.0, 0.0, 0.0, 1.0 }; // Ia term - Gray
//	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_POSITION, position0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse0);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular0);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient0);

	/*GLfloat diffu[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat spec[] = { 0.5f, 0.5f, 0.5f, 0.5f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffu);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spec);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);*/

	//glShadeModel(GL_SMOOTH);
}
