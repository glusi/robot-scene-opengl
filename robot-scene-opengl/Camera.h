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
	Vector3 eye_robot;
	Vector3 center_robot;
	Vector3 upz_robot;
	Vector3 direction_foward;
	Vector3 direction_right;
	Vector3 direction_up;
	float angle_x;
	float angle_y;
	bool is_first_person = false;
	Vector3 translate_position_camera_robot;
	Vector3 direction_moving;
	float camera_angle_z;
	void updateCamera();
public:
	Camera();
	void draw();
	void moveCamera(USER_ACTION_CAMERA action);
	void moveCamera(USER_ACTION_CAMERA action, float angle);
	void rotateCamera(float angle);
	void setIFirstPerson(int is_first_person);
	bool getIFirstPerson();
	void setFirstPersonCamera(Vector3 translate_position);
	Vector3 getCameraPosition();
	float getCameraAngle();
};

