#pragma once
#include "Constants.h"
#include "SceneItem.h"
#include "Vector3.h"

class Camera : SceneItem
{
	Vector3 eye;
	Vector3 center;
	Vector3 upz;
	Vector3 direction_foward;
	Vector3 direction_right;
	Vector3 direction_up;
	void updateCamera();
public:
	Camera();
	void draw();
	void moveCamera(USER_ACTION_CAMERA action);
	
};

