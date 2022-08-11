#pragma once
#include "SceneItem.h"
#define _USE_MATH_DEFINES
#include <math.h> 
#define DEG2RAD(a) (a * (M_PI / 180.0f))

class Camera : SceneItem
{
	//The position of the Camera
	Vector3 eye;
	//The position the camera is looking to 
	Vector3 center;
	//The up direction of camera
	Vector3 upz;
	//The position of the Camera in Robot (First Person) mode
	Vector3 eye_robot;
	//The position the camera is looking to in Robot (First Person) mode
	Vector3 center_robot;
	//The up direction of camera in Robot (First Person) mode
	Vector3 upz_robot;
	//Direction vector for camera to move forward by
	Vector3 direction_foward;
	//Direction vector for camera to move right by
	Vector3 direction_right;
	//Direction vector for camera to up forward by
	Vector3 direction_up;
	//True if is in robot mode - First Person
	bool is_first_person = false;
	//Direction vector to move to
	Vector3 direction_moving;
	//Camera angle around z
	float camera_angle_z;
	//Camera angle up down
	float camera_lift;
	
	void updateCamera();
public:
	/**
	 * Constructs a Camera object, initializing all its fields
	 */
	Camera();
	/**
	 * Draws the camera - updates the scene with new camera values
	 */
	void draw();
	/**
	 * moves the camera by one, according to the parameter:
	 * @USER_ACTION_CAMERA action - type of camera movement to apply to
	 * Used for keyboard inputs to move camera.
	 */
	void moveCamera(USER_ACTION_CAMERA action);
	/**
	 * moves the camera by <amount>, according to the parameter:
 	 * USER_ACTION_CAMERA action - type of camera movement to apply to
     * amount - how much the camera should move
     * Used for values from the slider in the menu which move camera.
	 */
	void moveCamera(USER_ACTION_CAMERA action, float angle);
	/*
	Rotates the camera by one.
	Used for keyboards inputs that rotate camera.
	*/
	void rotateCamera();
	/*
	Rotates the camera by <angle>:
	- float angle - the angle to rotate the camera by.
	Used for values from the slider in the menu which rotate camera.
	*/
	void rotateCamera(float angle);
	/*
	Lifts the camera by one.
	Used for keyboards inputs that lift camera.
	*/
	void liftCamera();
	/*
	Lifts the camera by <angle>:
	- float angle - the angle to lift the camera by.
	Used for values from the slider in the menu which lift camera.
	*/
	void liftCamera(float angle);
		/*
	Setter for is_first_person_int
	*/
	void setIFirstPerson(int is_first_person);
	/*
	Getter for is_first_person_int
	*/
	bool getIFirstPerson();
		/*
	Getter for camera's eye
	*/
	Vector3 getCameraPosition();
	/*
	Getter for camera's angle around z
	*/
	float getCameraAngle();
	/*
	Getter for camera's lift
	*/
	float getCameraLift();
};

