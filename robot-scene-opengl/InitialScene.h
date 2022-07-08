#pragma once
#include "Floor.h"
#include "Robot.h"
#include "Lights.h"
#include "Camera.h"

class InitialScene
{
	Floor* floor;
	Lights* lights;
	Robot* robot;
	Camera* camera;
public:
	InitialScene();
	void draw();
	void moveCamera(USER_ACTION_CAMERA action);
	void rotateCamera(int mouseX, int mouseY);
	void moveRobot(ROBOT_MOVE_DIRECTION direction);
	void rotateRobot();
	void rotateRobotHand(ROBOT_JOINT joint);
	void liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action);
};

