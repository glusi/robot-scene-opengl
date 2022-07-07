#pragma once
#include "SceneItem.h"
#define _USE_MATH_DEFINES
#include <math.h> 
#define DEG2RAD(a) (a * (M_PI / 180.0f))

class Camera : SceneItem
{
	Vector3 eye;
	Vector3 center;
	Vector3 upz;
	Vector3 direction_foward;
	Vector3 direction_right;
	Vector3 direction_up;
	float angle_x;
	float angle_y;
	void updateCamera();
public:
	Camera();
	void draw();
	void moveCamera(USER_ACTION_CAMERA action);
	void rotateCamera(int mouseX, int mouseY);
	
};

