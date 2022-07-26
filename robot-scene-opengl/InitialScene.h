#pragma once
#include "Floor.h"
#include "Robot.h"
#include "Lights.h"
#include "Camera.h"
#include "SceneItem.h"
#include "Texture.h"
#include "Gui.h"

class InitialScene
{
	Floor* floor;
	Lights* lights;
	Robot* robot;
	Camera* camera;
	void addDecorations();
	Texture texture;
	Gui gui;
	void buildEatingCorner();
	void buildTVCorner();
	void buildChair();
public:

	InitialScene();
	InitialScene(std::list<Button> buttons);
	void draw();
	void moveCamera(USER_ACTION_CAMERA action);
	void moveCamera(USER_ACTION_CAMERA action, float angle);
	void rotateCamera(int mouseX, int mouseY);
	void moveRobot(ROBOT_MOVE_DIRECTION direction);
	void rotateRobot();
	void rotateRobotHand(ROBOT_JOINT joint);
	void liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action);
	void moveRobotHead(ROBOT_HEAD_MOVEMENT movement);
	void moveRobotHead(ROBOT_HEAD_MOVEMENT movement, float angle);
	void setIFirstPerson(int isFirstPerson);
	Vector3 getCameraPosition();
	Vector3 getHeadPosition();
};

