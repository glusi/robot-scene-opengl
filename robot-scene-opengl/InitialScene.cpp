#include "InitialScene.h"

InitialScene::InitialScene() {
	camera = new Camera();
	floor = new Floor();
	lights = new Lights();
	robot = new Robot();
}

void InitialScene::draw() {
	camera->draw();
	lights->draw();
	floor->draw();
	robot->draw();
}

void InitialScene::moveCamera(USER_ACTION_CAMERA action)
{
	camera->moveCamera(action);
}
