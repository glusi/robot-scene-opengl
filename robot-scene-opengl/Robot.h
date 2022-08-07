#pragma once
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "SceneItem.h"

class Robot : SceneItem
{
	const float ROBOT_HAND_SIZE = 0.25;
	const float INITIAL_SHOULDER_ROTATION = 0;
	const float INITIAL_ELBOW_ROTATION = 0;
	const int HAND_UP_OFFSET = 18;
	const int HAND_DOWN_OFFSET = 10;
	const int ELBOW_UP_OFFSET = 10;
	const int ELBOW_DOWN_OFFSET = 10;
	const int PALM_DOWN_OFFSET = 5;
	const int PALM_UP_OFFSET = 5;
	const float INITIAL_PALM_ROTATION = 0;

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
	materialStruct material3{
	{0.0, 1.0, 1.0, 1.0}, // Ka
	{0.0, 1.0, 1.0, 1.0}, // Kd
	{0.0, 1.0, 1.0, 1.0}, // Ks
	2 // n
	};
	Vector3 translated_position;
	Vector3 translated_position_old;
	Vector3 move_direction;
	float angle = 0;

	Vector3 shoulder_position_to_robot;
	float shoulder_rotation;
	float shoulder_lift;
	Vector3 elbow_position_to_robot;
	float elbow_rotation;
	float elbow_lift;
	Vector3 palm_position_to_robot;
	float palm_rotation;
	float palm_lift;
	float head_rotation;
	float head_lift;
	Vector3 head_position;
	float amount_move = 0;

	void drawHand();
	void drawTube(Vector3 position, float angle1, ROTATION_TYPE rotation_type1, Vector3 color, float length);
	void drawHead();
	void drawBody();
	void drawJoint(Vector3 poistion);
	void drawPalm(Vector3 poistion);
	void translateToNewPosition();
	void rotateToNewAngle();
	void applyJointRotationAndLift(ROBOT_JOINT joint);
	void applyHeadRotationAndLift();
	void applyMaterial(materialStruct maaterial, float emission);

	public:
		Robot();
		void moveHead(ROBOT_HEAD_MOVEMENT movement);
		void moveHead(ROBOT_HEAD_MOVEMENT movement, float angle);
		void draw();
		void move(ROBOT_MOVE_DIRECTION direction);
		void move(ROBOT_MOVE_DIRECTION direction, float amount);
		void rotateHandJoint(ROBOT_JOINT joint);
		void rotateHandJoint(ROBOT_JOINT joint, float amount);
		void liftHandJoint(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action);
		void liftHandJoint(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action, float amount);
		void rotate();
		void rotate(float angle_new);
		Vector3 getHeadPosition();
		void applyCameraRotation();
		float getRobotRotation();
		float getRobotPosition();
		float getShoulderLift();
		float getShoulderRotation();
		float getElbowLift();
		float getElbowRotation();;
		float getPalmLift();
		float getPalmRotation();
		float getHeadRotation();
		float getHeadLift();
		void updateOldPosition();
};

