#pragma once
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "SceneItem.h"

class Robot : SceneItem
{
	const float ROBOT_HAND_SIZE = 0.25;

	materialStruct material1{
		{0.33, 0.22, 0.03, 1.0}, // Ka
		{0.78, 0.57, 0.11, 1.0}, // Kd
		{0.99, 0.91, 0.81, 1.0}, // Ks
		27.8 // n
			};
	materialStruct material2{
		{1.0, 1.0, 1.0, 1.0}, // Ka
		{1.0, 1.0, 1.0, 1.0}, // Kd
		{1.0, 1.0, 1.0, 1.0}, // Ks
		2 // n
	};
	Vector3 translated_position;
	Vector3 move_direction;

	void drawHand();
	void drawTube(Vector3 position, float angle1, ROTATION_TYPE rotation_type1, float angle2, ROTATION_TYPE rotation_type2, Vector3 color, float length);
	void drawHead();
	void drawBody();
	void drawJoint(Vector3 poistion);
	void drawPalm(Vector3 poistion);
	void translateToNewPosition();

	public:
		Robot();
		void walk(float x, float y, float z);
		void move_head(float left, float right, float up, float down);
		void draw();
		void move();
};

