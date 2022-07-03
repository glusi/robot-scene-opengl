#pragma once
#include "Floor.h"
#include "Robot.h"
#include "Lights.h"

class InitialScene
{
	Floor* floor;
	Lights* lights;
	Robot* robot;
public:
	InitialScene();
	void draw();
};

