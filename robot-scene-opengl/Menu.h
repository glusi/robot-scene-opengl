#pragma once
#include "Tools.h"
#include "Initialscene.h"


class Menu
{
	int isFirstPerson = 0;
	float rotate_head_right_left = 0;
	float rotate_head_up_down = 0;
	float rotate_camera_right_left;
	float rotate_camera_up_down;
	float rotate_camera_front_back;
	float* ambient_color;
	float* point_color;
	Vector3 point_light_position;
	float move_robot_foward_back;
	float rotate_robot = 0;
	float move_shoulder;
	float rotate_shoulder;
	float move_elbow;
	float rotate_elbow;
	float move_palm;
	float rotate_palm;
	InitialScene* scene;
	bool help_window_open = false; 
	bool ambient_enabled = true;
	bool point_enabled = true;
	void getInitialValues();
	void moveRobotJoint(ROBOT_JOINT robot_joint, float lift, float rotation, const char* name);
	void MyHelpFunction();
	void helpFunc();
	void lightMenu();
	void robotMenu();
	void cameraMenu();
public:
	Menu();
	Menu(InitialScene* scene);
	void createMenu();
};

