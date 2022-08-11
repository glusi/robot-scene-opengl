#pragma once
#include "Floor.h"
#include "Robot.h"
#include "Lights.h"
#include "Camera.h"
#include "SceneItem.h"
#include "Texture.h"
#include "Gui.h"

class Scene
{
	//Floor Object
	Floor* floor;
	//Light Object
	Lights* lights;
	//Robot Object
	Robot* robot;
	//Camera Object
	Camera* camera;
	//Texture Object
	Texture texture;
	//Gui Object
	Gui gui;
	//Window width
	float width = 500;;
	//Window height
	float height = 500;
	/**
	 * Adds room decorations such as table corner, TV corner, window and door.
	 *
	 */
	void addDecorations();
	/**
	 * Draws eating corner including table, two chairs, teapot and two glasses.
	 *
	 */
	void buildEatingCorner();
	/**
	 * Draws a TV corner including sofa and TV.
	 *
	 */
	void buildTVCorner();
	/**
	 * Draws a chair with wooden sitting parts and metallic holds.
	 *
	 */
	void buildChair();
public:
	/**
	 * Creates scene object, initializing all of its objects.
	 *
	 */
	Scene();
	/**
	 * Draws all the scene items.
	 *
	 */
	void draw();
	/**
	 * Moves a camera by one unit according to specified movement action.
	 * 
	 * \param action - how to move the camera
	 * Used for keyboard camera movement actions.
	 */
	void moveCamera(USER_ACTION_CAMERA action);
	/**
	 * Moves a camera by amount according to specified movement action.
	 *  
	 * \param action - on which axis to move camera
	 * \param amount - how much to move camera
	 * Used for camera sliders in the menu
	 */
	void moveCamera(USER_ACTION_CAMERA action, float amount);
	/**
	 *  Rotates a camera by one unit according to specified movement action.
	 * 
	 * \camera_type action - how to rotate the camera
	 * Used for camera sliders in the menu
	 */
	void rotateCamera(CAMERA_MOVE camera_type);
	/**
	 *  Rotates a camera by one unit according to specified movement action.
	 *
	 * \camera_type action - how to rotate the camera
	 * \param angle - how much to rotate camera
	 * Used for keyboard camera movement actions.
	 */
	void rotateCamera(CAMERA_MOVE camera_type, float angle);
	/**
	 * Moves robot by one unit according to specified movement action.
	 * 
	 * \param direction - Move robot forward or backwards
	 * Used for keyboard robot movement actions.
	 */
	void moveRobot(ROBOT_MOVE_DIRECTION direction);
	/**
	 * Moves robot by amount according to specified movement action.
	 *
	 * \param direction - Move robot forward or backwards
	 * \param amount - how much to much robot
	 * Used for keyboard robot movement actions.
	 */
	void moveRobot(ROBOT_MOVE_DIRECTION direction, float amount);
	/**
	 * Rotates robot by one unit according to rotation type.
	 * 
	 * \param rotation_type - rotate right or left
	 */
	void rotateRobot(ROBOT_ROTATION rotation_type);
	/**
	 *  Rotates robot by one unit.
	 *
	 * \param angle - how much to rotate robot
	 * Used for keyboard camera movement actions.
	 */
	void rotateRobot(float angle);
	/**
	 * Rotates robot joint by one unit.
	 * 
	 * \param joint - which joint to rotate
	 */
	void rotateRobotHand(ROBOT_JOINT joint);
	/**
	 * Rotates robot joint by amount.
	 * 
	 * \param joint - which joint to rotate
	 * \param amount - how much to rotate
	 */
	void rotateRobotHand(ROBOT_JOINT joint, float amount);
	/**
	 * Lifts robot joint by one unit.
	 * 
	 * \param joint - which joint to rotate
	 * \param action - how to lift the joint - up or down
	 */
	void liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action);
	/**
	 * Lifts robot joint by amount.
	 * 
	 * \param joint - which joint to rotate
	 * \param action - how to lift the joint - up or down.
	 * \param amount - how much to rotate
	 */
	void liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action, float amount);
	/**
	 * Moves robot head by one unit in movement type.
	 * 
	 * \param movement - how to move the head
	 */
	void moveRobotHead(ROBOT_HEAD_MOVEMENT movement);
	/**
	 * Moves robot head by amount in movement type.
	 *
	 * \param movement - how to move the head
	 * \param angle - angle to rotate by
	 */
	void moveRobotHead(ROBOT_HEAD_MOVEMENT movement, float angle);
	/**
	 * Setter for boolean about camera mode.
	 * 
	 * \param isFirstPerson
	 */
	void setIFirstPerson(int isFirstPerson);
	/**
	 * Getter for camera position.
	 * 
	 * \return camera position
	 */
	Vector3 getCameraPosition();
	/**
	 * Getter for head position.
	 * 
	 * \return head position
	 */
	Vector3 getHeadPosition();
	/**
	 * Sets new ambient color.
	 * 
	 * \param color - new ambient color
	 */
	void adjustAmbientLight(float* color);
	/**
	 * Getter ambient color.
	 * 
	 * \return ambient color
	 */
	float* getAmbientColor();
	/**
	 * .
	 * 
	 * \return 
	 */
	float getRobotRotation();
	float getRobotPosition();
	float getShoulderLift();
	float getShoulderRotation();
	float getElbowLift();
	float getElbowRotation();;
	float getPalmLift();
	float getPalmRotation();
	int getHelpImageWidth();
	int getHelpImageHeight();
	GLuint getgetHelpImageTexture();
	float getHeadRotation();
	float getHeadLift();
	void drawTexturedObject(TEXTURE_TYPE tex);
	float getPointLightPosition(POINT_LIGHT_POS axis);
	void applyPointLightPos(Vector3 point_light_position);
	float* getPointLightColor();
	void adjustPointLight(float* color);
	void setWidth(float width);
	void setHeight(float height);
	float getWidth();
	float getHeight();
	void disableAmbient(bool enabled);
	void disablePoint(bool enabled);
	float getCameraAngle();
	float getCameraLift();
};

