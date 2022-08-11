#include "Robot.h"

Robot::Robot()
{
	move_direction = Vector3(0, 0, 1);
	translated_position = Vector3::zeroVector();
	translated_position_old = Vector3::zeroVector();
	angle = 0.0;
	shoulder_position_to_robot = Vector3(-0.8, 3.5, 0);
	shoulder_lift = 45;
	shoulder_rotation = 0.0;
	elbow_position_to_robot = Vector3(-1.8, 3.5, 0);
	elbow_lift = -90;
	elbow_rotation = 0;
	palm_position_to_robot = Vector3(-2.6, 3.5, 0);
	palm_lift = 0;
	palm_rotation = 90.0;
	head_rotation = 0;
	head_lift = 0;
	head_position = Vector3(0, 5, 0);
}

void Robot::drawHand()
{
	//Draw shoulder
	glPushMatrix();
	drawJoint(shoulder_position_to_robot);
	applyJointRotationAndLift(ROBOT_SHOULDER);
	drawTube(shoulder_position_to_robot, -90, ROTATED_AROUND_X, Vector3(1, 0, 0), 1);
	drawJoint(elbow_position_to_robot);
	glPushMatrix();
	//Draw elbow
	applyJointRotationAndLift(ROBOT_ELBOW);
	drawTube(elbow_position_to_robot, -90, ROTATED_AROUND_X, Vector3(1, 0, 0), 0.8);
	drawJoint(palm_position_to_robot);
	glPushMatrix();
	//Draw palm
	applyJointRotationAndLift(ROBOT_PALM);
	drawPalm(palm_position_to_robot);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//Circle around shoulder
	glPushMatrix();
	glTranslatef(shoulder_position_to_robot.x, shoulder_position_to_robot.y, shoulder_position_to_robot.z);
	glScalef(0.1, 1, 1);
	glutSolidSphere(0.5, 10, 10);
	glPopMatrix();
}

void Robot::drawTube(Vector3 position, float angle1, ROTATION_TYPE rotation_type1, Vector3 color, float length)
{
	glColor3f(color.x, color.y, color.z);
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	Tools::rotate(angle1, rotation_type1);
	Tools::drawCylinder(ROBOT_HAND_SIZE, length, 100);
	glPopMatrix();
}

void Robot::drawHead()
{
	//Translate head to its place on top of body
	glPushMatrix();
	glTranslatef(head_position.x, head_position.y, head_position.z);

	//Apply Head lift
	glPushMatrix();
	glRotatef(head_rotation, 0, 1, 0);
	

	//Apply Head rotation
	glPushMatrix();
	glRotatef(-head_lift, 1, 0, 0);

	//Draw the head
	glPushMatrix();
	glutSolidCube(1.1);

	//Draw an antenna
	glPushMatrix();
	glTranslatef(0, 1.3, 0);
	glRotatef(90, 1, 0, 0);
	Tools::drawCylinder(0.02, 1.3, 10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 1.3, 0);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	//Draw eyes
	Tools::assignMaterial(robot_eye_material,1);
	//First eye
	glPushMatrix();
	glTranslatef(0.3, 0.1, 0.5);
	glutSolidSphere(0.15, 10, 10);
	glPopMatrix();
	//Second eye
	glPushMatrix();
	glTranslatef(-0.3, 0.1, 0.5);
	glutSolidSphere(0.15, 10, 10);
	glPopMatrix();

	//Draw mouth
	Tools::assignMaterial(materialTV,0);
	glPushMatrix();
	glTranslatef(0, -0.3, 0.55);
	glScalef(5, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	//Draw neck
	Tools::assignMaterial(robot_material, 1);
	glPushMatrix();
	glTranslatef(0, -0.7, 0);
	glutSolidCube(0.5);
	glPopMatrix();

	glPopMatrix();

}

void Robot::drawBody()
{
	glPushMatrix();
	glTranslatef(0, 2, 0);
	glScalef(1, 2.75, 1);
	glutSolidCube(1.5);
	glPopMatrix();
}

void Robot::drawJoint(Vector3 position)
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(ROBOT_HAND_SIZE, 10, 10);
	glPopMatrix();
}

void Robot::drawPalm(Vector3 position)
{
	//Draw hand base
	glPushMatrix();
	glTranslatef(position.x-0.45, position.y, position.z);
	glScalef(1, 0.3, 1.2);
	glutSolidCube(0.5);
	glPopMatrix();
	//Draw finger 1
	glPushMatrix();
	glTranslatef(position.x-0.85, position.y, position.z + 0.09);
	glScalef(3, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();
	//Draw finger 2
	glPushMatrix();
	glTranslatef(position.x - 0.85, position.y, position.z - 0.09);
	glScalef(3, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();
	//Draw finger 3
	glPushMatrix();
	glTranslatef(position.x - 0.85, position.y, position.z+0.26);
	glScalef(3, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();
	//Draw finger 4
	glPushMatrix();
	glTranslatef(position.x - 0.85, position.y, position.z - 0.26);
	glScalef(3, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();
	//Draw finger 5
	glPushMatrix();
	glTranslatef(position.x - 0.55, position.y, position.z - 0.4);;
	glRotatef(-45, 0, 1, 0);
	glScalef(3, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();
}

void Robot::translateToNewPosition() {
	glTranslatef(translated_position.x, translated_position.y, translated_position.z);
}

void Robot::rotateToNewAngle()
{
	glRotatef(angle, 0, 1, 0);
}

void Robot::moveHead(ROBOT_HEAD_MOVEMENT movement)
{
	if (movement == ROBOT_HEAD_UP && head_lift < 200)
		head_lift++;
	if (movement == ROBOT_HEAD_DOWN && head_lift >-60)
		head_lift--;
	if (movement == ROBOT_HEAD_RIGHT)
		head_rotation++;
	if (movement == ROBOT_HEAD_LEFT)
		head_rotation--;
	//Constraints
	if (head_rotation > 360)
		head_rotation = 0;
	if (head_rotation < -360)
		head_rotation = 0;
}

void Robot::moveHead(ROBOT_HEAD_MOVEMENT movement, float angle)
{
	if (movement == ROBOT_HEAD_UP_DOWN )
		head_lift = angle;
	if (movement == ROBOT_HEAD_RIGHT_LEFT)
		head_rotation = angle;
}

void Robot::draw() {
	Tools::assignMaterial(robot_material, 0);
	glPushMatrix();
	//Move robot to current position
	translateToNewPosition();
	//Rotate robot to current angle
	rotateToNewAngle();
	//Draw the robot
	glPushMatrix();
	glTranslatef(0, 0.475, 0);
	//Draw head
	drawHead();
	//Draw body
	drawBody();
	//Draw hand
	drawHand();
	glPopMatrix();
	//Draw wheels
	Tools::assignMaterial(black_rubber, 0.5);
	//wheel 1
	glPushMatrix();
	glTranslatef(-0.6,0.2,-0.6);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();
	//wheel 2
	glPushMatrix();
	glTranslatef(0.6, 0.2, -0.6);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();
	//wheel 3
	glPushMatrix();
	glTranslatef(-0.6, 0.2, 0.6);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();
	//wheel 4
	glPushMatrix();
	glTranslatef(0.6, 0.2, 0.6);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();
	glPopMatrix();
}

void Robot::move(ROBOT_MOVE_DIRECTION direction)
{
	if (direction == ROBOT_MOVE_FRONT) {
		translated_position += move_direction ;
		amount_move++;
	} else {
		translated_position -= move_direction ;
		amount_move--;
	}
}

void Robot::move(ROBOT_MOVE_DIRECTION direction, float amount)
{

	if (direction == ROBOT_MOVE_FRONT) {
		translated_position = translated_position_old + move_direction * (amount - amount_move_old) * 0.1;
		amount_move = amount;
	} else {
		translated_position = translated_position_old + move_direction * (-amount + amount_move_old) * 0.1;
		amount_move = -amount;
	}
	
}

void Robot::applyJointRotationAndLift(ROBOT_JOINT joint)
{
	switch (joint) {
	case ROBOT_SHOULDER:
		//Translate to origin
		glTranslatef(shoulder_position_to_robot.x, shoulder_position_to_robot.y, shoulder_position_to_robot.z);
		//apply rotation
		glRotatef(shoulder_rotation, 1, 0, 0);
		//apply lift
		glRotatef(shoulder_lift, 0, 0, 1);
		//Translate back
		glTranslatef(-shoulder_position_to_robot.x, -shoulder_position_to_robot.y, -shoulder_position_to_robot.z);
		break;
	case ROBOT_ELBOW:
		//Translate to origin
		glTranslatef(elbow_position_to_robot.x, elbow_position_to_robot.y, shoulder_position_to_robot.z);
		//apply rotation
		glRotatef(elbow_rotation, 1, 0, 0);
		//apply lift
		glRotatef(elbow_lift, 0, 0, 1);
		//Translate back
		glTranslatef(-elbow_position_to_robot.x, -elbow_position_to_robot.y, -shoulder_position_to_robot.z);
		break;
	case ROBOT_PALM:
		//Translate to origin
		glTranslatef(palm_position_to_robot.x, palm_position_to_robot.y, palm_position_to_robot.z);
		//apply rotation
		glRotatef(palm_rotation, 1, 0, 0);
		//apply lift
		glRotatef(palm_lift, 0, 0, 1);
		//Translate back
		glTranslatef(-palm_position_to_robot.x, -palm_position_to_robot.y, -palm_position_to_robot.z);
		break;
	};
}

void Robot::rotateHandJoint(ROBOT_JOINT joint)
{
	switch (joint) {
	case ROBOT_SHOULDER:
		if (shoulder_rotation < 180)
			shoulder_rotation++;
		else
			shoulder_rotation = -180;
		break;
	case ROBOT_ELBOW:
		if (elbow_rotation < 180)
			elbow_rotation++;
		else
			elbow_rotation = -180;
		break;
	case ROBOT_PALM:
		if (palm_rotation < 180)
			palm_rotation++;
		else
			palm_rotation = -180;
		break;
	};
}

void Robot::rotateHandJoint(ROBOT_JOINT joint, float amount)
{
	switch (joint) {
	case ROBOT_SHOULDER:
		shoulder_rotation = amount;
		break;
	case ROBOT_ELBOW:
		elbow_rotation = amount;
		break;
	case ROBOT_PALM:
		palm_rotation = amount;
		break;
	};
}

void Robot::liftHandJoint(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action)
{
	switch (joint) {
	case ROBOT_SHOULDER:
		//Apply constraints
		if (!((shoulder_lift >= 85 && action == ROBOT_HAND_DOWN) || (shoulder_lift <= -85 && action == ROBOT_HAND_UP)))
			{
			if (action == ROBOT_HAND_UP)
				shoulder_lift--;
			else
				shoulder_lift++;
		}	
		break;
	case ROBOT_ELBOW:
		//Apply constraints
		if (!((elbow_lift  >= 85 && action == ROBOT_HAND_DOWN) || (elbow_lift <= -85 && action == ROBOT_HAND_UP)))
		{
			if (action == ROBOT_HAND_UP)
				elbow_lift--;
			else
				elbow_lift++;
		}
		break;
	case ROBOT_PALM:
		//Apply constraints
		if (!((palm_lift >= 85 && action == ROBOT_HAND_DOWN) || (palm_lift <= -85 && action == ROBOT_HAND_UP)))
			{
			if (action == ROBOT_HAND_UP)
				palm_lift--;
			else
				palm_lift++;
		}
		break;
	};
}

void Robot::liftHandJoint(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action, float amount)
{
	switch (joint) {
	case ROBOT_SHOULDER:
				shoulder_lift = amount;
		break;
	case ROBOT_ELBOW:
				elbow_lift = amount;
		break;
	case ROBOT_PALM:
				palm_lift = amount;
		break;
	};
}

void Robot::rotate(ROBOT_ROTATION rotation_type)
{
	if (rotation_type == ROBOT_ROTATE_RIGHT)
		angle++;
	else
		angle--;
	move_direction = Vector3(sin(DEG2RAD(angle)), 0, cos(DEG2RAD(angle)));
	move_direction.normalize();
}

void Robot::rotate( float angle_new)
{
	angle = angle_new;
	move_direction = Vector3(sin(DEG2RAD(angle)), 0, cos(DEG2RAD(angle)));
	move_direction.normalize();
}

Vector3 Robot::getHeadPosition()
{
	return head_position;
}

void Robot::applyCameraRotation()
{
	//Move to head position
	glPushMatrix();
	glTranslatef(-head_position.x, -head_position.y, -head_position.z- FP_CAMERA_OFFSET);
	
	//Move to robot position
	glPushMatrix();
	glTranslatef(-translated_position.x, -translated_position.y, -translated_position.z - FP_CAMERA_OFFSET);

	//Apply head lift
	glPushMatrix();
	//Translate to origin
	glTranslatef(translated_position.x, translated_position.y, translated_position.z);
	glTranslatef(head_position.x, head_position.y, head_position.z);
	//rotate to head lift
	glRotatef(head_lift, 1, 0, 0);
	//Translate back
	glTranslatef(-head_position.x, -head_position.y, -head_position.z);
	glTranslatef(-translated_position.x, -translated_position.y, -translated_position.z);

	//Apply robot rotation
	glPushMatrix();
	//Translate to origin
	glTranslatef(translated_position.x, translated_position.y, translated_position.z);
	glTranslatef(head_position.x, head_position.y, head_position.z);
	//rotate to robot angle
	glRotatef(-angle, 0, 1, 0);
	//Translate back
	glTranslatef(-head_position.x, -head_position.y, -head_position.z);
	glTranslatef(-translated_position.x, -translated_position.y, -translated_position.z);
	
	//Apply head rotation
	glPushMatrix();
	//Translate to origin
	glTranslatef(translated_position.x, translated_position.y, translated_position.z);
	glTranslatef(head_position.x, head_position.y, head_position.z);
	//rotate to head rotation
	glRotatef(-head_rotation, 0, 1, 0);
	//Translate back
	glTranslatef(-head_position.x, -head_position.y, -head_position.z);
	glTranslatef(-translated_position.x, -translated_position.y, -translated_position.z);
}

float Robot::getRobotRotation()
{
	return angle;
}

float Robot::getRobotPosition()
{
	return amount_move;
}

float Robot::getShoulderLift()
{
	return shoulder_lift;
}

float Robot::getShoulderRotation()
{
	return shoulder_rotation;
}

float Robot::getElbowLift()
{
	return elbow_lift;
}

float Robot::getElbowRotation()
{
	return elbow_rotation;
}

float Robot::getPalmLift()
{
	return palm_lift;
}

float Robot::getPalmRotation()
{
	return palm_rotation;
}

float Robot::getHeadRotation()
{
	return head_rotation;
}

float Robot::getHeadLift()
{
	return head_lift;
}

void Robot::updateOldPosition()
{
	//Apply new values of position and amount at end of frame to be old values in nect one
	translated_position_old = translated_position;
	amount_move_old = amount_move;
}