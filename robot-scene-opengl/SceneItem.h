#pragma once
#include "tools.h"
#include "Vector3.h"

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

