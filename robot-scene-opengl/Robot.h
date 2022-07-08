#pragma once
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "SceneItem.h"

class Robot : SceneItem
{
	const float ROBOT_HAND_SIZE = 0.25;
	const float INITIAL_SHOULDER_ROTATION = 45;
	const float INITIAL_ELBOW_ROTATION = 15;
	const int HAND_UP_OFFSET = 18;
	const int HAND_DOWN_OFFSET = 10;
	const int ELBOW_UP_OFFSET = 10;
	const int ELBOW_DOWN_OFFSET = 10;

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
	float angle;

	Vector3 shoulder_position_to_robot;
	float shoulder_rotation;
	float shoulder_lift;
	Vector3 elbow_position_to_robot;
	float elbow_rotation;
	float elbow_lift;
	Vector3 palm_position_to_robot;
	float palm_rotation;
	float palm_lift;

	void drawHand();
	void drawTube(Vector3 position, float angle1, ROTATION_TYPE rotation_type1, float angle2, ROTATION_TYPE rotation_type2, Vector3 color, float length);
	void drawHead();
	void drawBody();
	void drawJoint(Vector3 poistion);
	void drawPalm(Vector3 poistion);
	void translateToNewPosition();
	void rotateToNewAngle();
	void applyJointRotationAndLift(ROBOT_JOINT joint);

	public:
		Robot();
		void moveHead(float left, float right, float up, float down);
		void draw();
		void move(ROBOT_MOVE_DIRECTION direction);
		void rotateHandJoint(ROBOT_JOINT joint);
		void liftHandJoint(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action);
		void rotate();
};

