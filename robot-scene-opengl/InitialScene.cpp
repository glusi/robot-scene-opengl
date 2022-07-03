#include "InitialScene.h"

InitialScene::InitialScene() {
	floor = new Floor();
	lights = new Lights();
	robot = new Robot();
}

void InitialScene::draw() {
	lights->draw();
	floor->draw();
	robot->draw();
}