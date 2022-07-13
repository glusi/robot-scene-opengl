#pragma once
#include <GL/glut.h>

typedef struct materialStruct {
	GLfloat Ka[4];
	GLfloat Kd[4];
	GLfloat Ks[4];
	GLfloat n;
} materialStruct;

static const materialStruct glass{
	{0.1f,0.19f,0.17f,0.8f}, // Ka
	{0.4f,0.74f,0.69f,0.8f}, // Kd
	{0.3f,0.31f,0.31f,0.8f}, // Ks
	12.8 // n
};
static const materialStruct polished_copper{
	{0.2295f, 0.08825f, 0.0275f, 1.0f}, // Ka
	{0.5508f, 0.2118f, 0.066f, 1.0f}, // Kd
	{0.580594f, 0.223257f, 0.0695701f, 1.0f}, // Ks
	51.2f // n
};
static const materialStruct silver{
	{0.19, 0.19, 0.19, 1.0f}, // Ka
	{0.51, 0.51, 0.51, 1.0f}, // Kd
	{0.51, 0.51, 0.51, 1.0f}, // Ks
	51.2 // n
};

static const materialStruct floor_material{
		{0.05f,0.05f,0.05f,1.0f}, // Ka
		{0.5f,0.5f,0.5f,1.0f}, // Kd
		{0.7f,0.7f,0.04f,1.0f}, // Ks
		5.3 // n
};

static void assignMaterial(materialStruct  material) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, material.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, material.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material.Ks);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material.Kd);
}
