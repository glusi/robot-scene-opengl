#include "Tools.h"

void Tools::drawCylinder(float radius, float height, int slices) {
	GLUquadricObj* IDquadric = gluNewQuadric();
	gluQuadricNormals(IDquadric, GLU_SMOOTH);  // Create Smooth Normals ( NEW )
	gluCylinder(IDquadric, radius, radius, height, slices, slices);
}

void Tools::rotate(float angle, ROTATION_TYPE rotation_type)
{
	switch (rotation_type) {
	case ROTATED_AROUND_X: glRotatef(angle, 1, 0, 0);
	case ROTATED_AROUND_Y: glRotatef(angle, 0, 1, 0);
	case ROTATED_AROUND_Z: glRotatef(angle, 0, 0, 1);
	}
}

void Tools::assignMaterial(materialStruct  material) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, material.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, material.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material.Ks);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material.Kd);
}

void Tools::copyColor(float **ambient_color, float* new_color)
{
	for (int i = 0; i < 4; i++) {
		(*ambient_color)[i] = new_color[i];
	}
}

