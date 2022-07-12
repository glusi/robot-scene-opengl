#include "InitialScene.h"

InitialScene::InitialScene() {
	camera = new Camera();
	floor = new Floor();
//	lights = new Lights();
//	robot = new Robot();
	/*glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0);*/
	//glEnable(GL_CULL_FACE); //<-- missing
	//glCullFace(GL_BACK);

	//glEnable(GL_LIGHTING); //<-- missing
	//glEnable(GL_LIGHT0);
	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0); //Despite culling is on anyway,
											  //the back faces of 'solid' meshes don't
											  //need illumination

	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS);
}

void InitialScene::draw() {
	camera->draw();
	lights->draw();
	floor->draw();
	//robot->draw();
}

void InitialScene::moveCamera(USER_ACTION_CAMERA action)
{
	camera->moveCamera(action);
}

void InitialScene::rotateCamera(int mouseX, int mouseY)
{
	camera->rotateCamera(mouseX, mouseY);
}

void InitialScene::moveRobot(ROBOT_MOVE_DIRECTION direction)
{
	robot->move(direction);
}

void InitialScene::rotateRobot()
{
	robot->rotate();
}

void InitialScene::rotateRobotHand(ROBOT_JOINT joint)
{
	robot->rotateHandJoint(joint);
}

void InitialScene::liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action)
{
	robot->liftHandJoint(joint, action);
}

void InitialScene::moveRobotHead(ROBOT_HEAD_MOVEMENT movement)
{
	robot->moveHead(movement);
}
