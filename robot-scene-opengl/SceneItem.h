#pragma once
#include <GL/glut.h>
#include <GL\freeglut.h>
class SceneItem
{
protected:
	typedef struct materialStruct {
		GLfloat Ka[4];
		GLfloat Kd[4];
		GLfloat Ks[4];
		GLfloat n;
	} materialStruct;
public:
	void draw();
};

