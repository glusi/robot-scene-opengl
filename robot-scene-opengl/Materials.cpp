#include "Materials.h"

static void Materials::assignMaterial(materialStruct  material) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, material.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, material.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material.Ks);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material.Kd);
}