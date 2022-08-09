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
	void moveRobot(ROBOT_MOVE_DIRECTION direction, float amount);
	void rotateRobot();
	void rotateRobot(float angle);
	void rotateRobotHand(ROBOT_JOINT joint);
	void rotateRobotHand(ROBOT_JOINT joint, float amount);
	void liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action);
	void liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action, float amount);
	void moveRobotHead(ROBOT_HEAD_MOVEMENT movement);
	void moveRobotHead(ROBOT_HEAD_MOVEMENT movement, float angle);
	void setIFirstPerson(int isFirstPerson);
	Vector3 getCameraPosition();
	Vector3 getHeadPosition();
	void adjustAmbientLight(float* color);
	float* getAmbientColor();
	float getRobotRotation();
	float getRobotPosition();
	float getShoulderLift();
	float getShoulderRotation();
	float getElbowLift();
	float getElbowRotation();;
	float getPalmLift();
	float getPalmRotation();
	GLuint getTextureId(TEXTURE_TYPE texture);
	int getHelpImageWidth();
	int getHelpImageHeight();
	GLuint getgetHelpImageTexture();
	float getHeadRotation();
	float getHeadLift();
	void drawTexturedObject(TEXTURE_TYPE tex, materialStruct material);
};

