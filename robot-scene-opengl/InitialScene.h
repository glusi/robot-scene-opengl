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
};

