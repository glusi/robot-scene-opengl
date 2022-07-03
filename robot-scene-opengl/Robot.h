#pragma once
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "SceneItem.h"

class Robot : SceneItem
{
	materialStruct brass{
		{0.33, 0.22, 0.03, 1.0}, // Ka
		{0.78, 0.57, 0.11, 1.0}, // Kd
		{0.99, 0.91, 0.81, 1.0}, // Ks
		27.8 // n
			};

	public:
		void walk(float x, float y, float z);
		void move_head(float left, float right, float up, float down);
		void draw();
};

