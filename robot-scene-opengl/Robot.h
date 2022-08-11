#pragma once
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "SceneItem.h"

class Robot : SceneItem
{
	//Robot hand size
	const float ROBOT_HAND_SIZE = 0.25;
	//Shoulder offsets to draw
	const int HAND_UP_OFFSET = 18;
	const int HAND_DOWN_OFFSET = 10;
	//Elbow offsets to draw
	const int ELBOW_UP_OFFSET = 10;
	const int ELBOW_DOWN_OFFSET = 10;
	//Palm offsets to draw
	const int PALM_DOWN_OFFSET = 5;
	const int PALM_UP_OFFSET = 5;
	//First person offset
	const float FP_CAMERA_OFFSET = 0.55;
	//Translated position of robot
	Vector3 translated_position;
	//Translated position of robot of previous frame
	Vector3 translated_position_old;
	//Move direction of robot
	Vector3 move_direction;
	//Robot angle
	float angle = 0;
	//Translated position of shoulder relatively to robot
	Vector3 shoulder_position_to_robot;
	//Rotation of shoulder
	float shoulder_rotation;
	//Lift of shoulder
	float shoulder_lift;
	//Translated position of elbow relatively to robot
	Vector3 elbow_position_to_robot;
	//Rotation of elbow
	float elbow_rotation;
	//Lift of elbow
	float elbow_lift;
	//Translated position of palm relatively to robot
	Vector3 palm_position_to_robot;
	//Rotation of palm
	float palm_rotation;
	//Lift of palm
	float palm_lift;
	//Rotation of head
	float head_rotation;
	//Lift of head
	float head_lift;
	//Translated position of head
	Vector3 head_position;
	//How much robot moves
	float amount_move = 0;
	//How much robot moved last frame
	float amount_move_old = 0;
	/**
	 * Draws the hand including Shoulder ,elbow and palm joints.
	 * 
	 */
	void drawHand();
	/**
	 * Draws a tube for hand part rotated and in desired length and color.
	 * 
	 * \param position - where to draw tube
	 * \param angle1 - angle to rotate tube
	 * \param rotation_type1 - how to rotate - which axis
	 * \param color - color of tube
	 * \param length - length of tube
	 */
	void drawTube(Vector3 position, float angle1, ROTATION_TYPE rotation_type1, Vector3 color, float length);
	/**
	 * Draw robot head with eyes, mouth and antenna.
	 * 
	 */
	void drawHead();
	/**
	 * Draws robot Body.
	 * 
	 */
	void drawBody();
	/**
	 * Draws robot joint sphere in desired position.
	 * 
	 * \param poistion - position of joint
	 */
	void drawJoint(Vector3 poistion);
	/**
	 * draws robot hand palm withfingers.
	 * 
	 * \param poistion
	 */
	void drawPalm(Vector3 poistion);
	/**
	 * Translates robot to new position according to translated_position var.
	 * 
	 */
	void translateToNewPosition();
	/**
	 * Rotates robot to new angle according to angle var.
	 * 
	 */
	void rotateToNewAngle();
	/**
	 * Apply Joint rotation and lift according to <joint>_rotation and <joint>_lift vars.
	 * 
	 * \param joint
	 */
	void applyJointRotationAndLift(ROBOT_JOINT joint);
	
	public:
		/**
		 * Moves robot head by one unit in movement type.
		 *
		 * \param movement - how to move the head
		 */
		void moveHead(ROBOT_HEAD_MOVEMENT movement);
		/**
		 * Moves robot head by amount in movement type.
		 *
		 * \param movement - how to move the head
		 * \param angle - angle to rotate by
		 */
		void moveHead(ROBOT_HEAD_MOVEMENT movement, float angle);
		/**
		 * draws robot with all its parts and materials.
		 * 
		 */
		void draw();
		/**
		 * Constructs a Robot object with the needed initializations.
		 * 
		 */
		Robot();
		/**
		 * Moves robot by one unit according to specified movement action.
		 *
		 * \param direction - Move robot forward or backwards
		 * Used for keyboard robot movement actions.
		 */
		void move(ROBOT_MOVE_DIRECTION direction);
		/**
		 * Moves robot by amount according to specified movement action.
		 *
		 * \param direction - Move robot forward or backwards
		 * \param amount - how much to much robot
		 * Used for keyboard robot movement actions.
		 */
		void move(ROBOT_MOVE_DIRECTION direction, float amount);
		/**
		 * Rotates robot joint by one unit.
		 *
		 * \param joint - which joint to rotate
		 */
		void rotateHandJoint(ROBOT_JOINT joint);
		/**
		 * Rotates robot joint by amount.
		 *
		 * \param joint - which joint to rotate
		 * \param amount - how much to rotate
		 */
		void rotateHandJoint(ROBOT_JOINT joint, float amount);
		/**
		 * Lifts robot joint by one unit.
		 *
		 * \param joint - which joint to rotate
		 * \param action - how to lift the joint - up or down
		 */
		void liftHandJoint(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action);
		/**
		 * Lifts robot joint by amount.
		 *
		 * \param joint - which joint to rotate
		 * \param action - how to lift the joint - up or down.
		 * \param amount - how much to rotate
		 */
		void liftHandJoint(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action, float amount);
		/**
		 * Rotates robot by one unit according to rotation type.
		 *
		 * \param rotation_type - rotate right or left
		 */
		void rotate(ROBOT_ROTATION rotation_type);
		/**
		 *  Rotates robot by one unit.
		 *
		 * \param angle - how much to rotate robot
		 * Used for keyboard camera movement actions.
		 */
		void rotate(float angle_new);
		/**
		 * Getter for head position.
		 *
		 * \return head position
		 */
		Vector3 getHeadPosition();
		/**
		 * Rotate scene similarly to robot head for first person camera.
		 * 
		 */
		void applyCameraRotation();
		/**
		 * Getter for robot angle.
		 * 
		 * \return robot angle
		 */
		float getRobotRotation();
		/**
		 * Getter for robot position.
		 * 
		 * \return amount of robot movements
		 */
		float getRobotPosition();
		/**
		 * Getter for robot shoulder lift.
		 * 
		 * \return robot shoulder lift
		 */
		float getShoulderLift();
		/**
		 * Getter for robot shoulder rotation.
		 * 
		 * \return robot shoulder rotation
		 */
		float getShoulderRotation();
		/**
		 * Getter for robot elbow lift.
		 * 
		 * \return robot elbow lift
		 */
		float getElbowLift();
		/**
		 * Getter for robot elbow rotation.
		 * \return robot elbow rotation
		 */
		float getElbowRotation();
		/**
		 * Getter for robot palm lift.
		 * 
		 * \return palm lift
		 */
		float getPalmLift();
		/**
		 * Getter for robot palm rotation.
		 * 
		 * \return robot palm rotation
		 */
		float getPalmRotation();
		/**
		 * Getter for robot head rotation.
		 * 
		 * \return robot head rotation
		 */
		float getHeadRotation();
		/**
		 * Getter for robot head lift.
		 *
		 * \return head lift
		 */
		float getHeadLift();
		/**
		 * Updated the position of robot at end of frame to new value.
		 * 
		 */
		void updateOldPosition();
};

