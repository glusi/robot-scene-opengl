#include "Robot.h"

void Robot::draw() {
	glColor3f(0.0f, 1.0f, 1.0f);//Blue
	glMaterialfv(GL_FRONT, GL_AMBIENT, brass.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, brass.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, brass.Ks);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brass.Kd);
	glMaterialf(GL_FRONT, GL_EMISSION, 0);
	glutSolidCube(1.5);

	glTranslatef(0, 1.5, 0);
	glScalef(0.75, 0.75, 0.75);
	glColor3f(0.0f, 1.0f, 1.0f);//Blue
	glutSolidSphere(1.0,100,100);
}