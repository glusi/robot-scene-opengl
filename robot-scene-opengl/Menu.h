#pragma once
#include "Tools.h"
#include "Scene.h"


class Menu
{
	//Menu flag for camera mode
	int isFirstPerson = 0;
	//Menu slider value for robot head rotation left right
	float rotate_head_right_left = 0;
	//Menu slider value for robot head rotation up down
	float rotate_head_up_down = 0;
	//Menu slider value for camera rotation left right
	float rotate_camera_right_left;
	//Menu slider value for camera rotation up down
	float rotate_camera_up_down;
	//Menu slider value for camera rotation front back
	float rotate_camera_front_back;
	//Menu color value for ambient light
	float* ambient_color;
	//Menu color value for point light
	float* point_color;
	//Menu slider values for point light positions on axises
	Vector3 point_light_position;
	//Menu value for robot movement forward and backwards
	float move_robot_foward_back;
	//Menu slider value for robot rotation
	float rotate_robot = 0;
	//Menu slider value for robot shoulder lift
	float move_shoulder;
	//Menu slider value for robot shoulder rotation
	float rotate_shoulder;
	//Menu slider value for robot elbow lift
	float move_elbow;
	//Menu slider value for robot elbow rotation
	float rotate_elbow;
	//Menu slider value for robot palm lift
	float move_palm;
	//Menu slider value for robot palm rotation
	float rotate_palm;
	//Pointer to Scene object
	Scene* scene;
	//Menu flag for help popup window state
	bool help_window_open = false; 
	//Menu flag for ambient checkbox
	bool ambient_enabled = true;
	//Menu flag for point light checkbox
	bool point_enabled = true;
	//Menu slider value for camera rotation around z
	float rotate_camera_z = 0;
	//Menu slider value for camera lift
	float lift_camera = 0;
	//Menu flag for next button in help popup
	bool next_pressed = false;
	/**
	 * gets the values from the scene object for all menu fields.
	 * 
	 */
	void getInitialValues();
	/**
	 * Creates sub menu for joint rotation and lift.
	 * 
	 * \param robot_joint - which joint to create the slider for
	 * \param lift - the lift variable to create the slider with
	 * \param rotation - the rotation variable to create the slider with
	 * \param name - string name of joint to be printed
	 */
	void moveRobotJoint(ROBOT_JOINT robot_joint, float lift, float rotation, const char* name);
	/**
	 * Handles click on 'help' button.
	 * 
	 */
	void helpFunc();
	/**
	 * Creates a menu with all the lights controls.
	 * 
	 */
	void lightMenu();
	/**
	 * Creates a menu with all the robot controls.
	 * 
	 */
	void robotMenu();
	/**
	 * Creates a menu with all the camera controls.
	 *
	 */
	void cameraMenu();
	/**
	 * Creates a popup window with explanations about keyboard and mouse controls.
	 * 
	 */
	void helpMenu();
public:
	/**
	 * Constructs the Menu object. Initializes color arrays.
	 * 
	 */
	Menu();
	/**
	 * Constructs the Menu object. Initializes color arrays.
	 * Assigns scene object pointer.
	 * 
	 * \param scene - scene object pointer to be saved for later use
	 */ 
	Menu(Scene* scene);
	/**
	 * Creates Menu with all the controls for the simulation, using ImGui.
	 * 
	 */
	void createMenu();
};

