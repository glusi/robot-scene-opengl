#include "Robot.h"

Robot::Robot()
{
	move_direction = Vector3(0, 0, 1);
	translated_position = Vector3::zeroVector();
	translated_position_old = Vector3::zeroVector();
	angle = 0.0;
	shoulder_position_to_robot = Vector3(-0.8, 3.5, 0);//Vector3(-0.8, 3.5, 0);
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
	//drawJoint(Vector3(0.8, 3.5, 0), 90, ROTATED_AROUND_X, -45, ROTATED_AROUND_Z, Vector3(1, 0, 0), 1.2);
	//drawJoint(Vector3(1.7, 2.5, 0), 90, ROTATED_AROUND_X, 15, ROTATED_AROUND_Z, Vector3(1, 0, 0), 1);
	glPushMatrix();
	//glLoadIdentity();
	drawJoint(shoulder_position_to_robot);
	applyJointRotationAndLift(ROBOT_SHOULDER);
	drawTube(shoulder_position_to_robot, -90, ROTATED_AROUND_X, Vector3(1, 0, 0), 1);
	drawJoint(elbow_position_to_robot);
	glPushMatrix();
	applyJointRotationAndLift(ROBOT_ELBOW);
	drawTube(elbow_position_to_robot, -90, ROTATED_AROUND_X, Vector3(1, 0, 0), 0.8);
	drawJoint(palm_position_to_robot);
	glPushMatrix();
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
	//Tools::rotate(angle2, rotation_type2);
	Tools::rotate(angle1, rotation_type1);
	Tools::drawCylinder(ROBOT_HAND_SIZE, length, 100);
	glPopMatrix();
}

void Robot::drawHead()
{
	glPushMatrix();
	glTranslatef(head_position.x, head_position.y, head_position.z);

	glPushMatrix();
	glRotatef(-head_lift, 1, 0, 0);
	glTranslatef(-head_position.x, -head_position.y, -head_position.z);
	glRotatef(head_rotation, 0, 1, 0);
	
	glTranslatef(head_position.x, head_position.y, head_position.z);

	glPushMatrix();
	//glTranslatef(head_position.x, head_position.y, head_position.z);
	//glScalef(0.75, 0.75, 0.75);
	//glColor3f(0.0f, 1.0f, 1.0f);//Blue
	glutSolidCube(1.1);

	applyMaterial(material3,1);
	glPushMatrix();
	glTranslatef(0.3, 0.1, 0.5);
	glutSolidSphere(0.15, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, 0.1, 0.5);
	glutSolidSphere(0.15, 10, 10);
	glPopMatrix();

	applyMaterial(material2,0);

	glPushMatrix();
	glTranslatef(0, -0.3, 0.55);
	glScalef(5, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	//neck
	applyMaterial(material1, 1);
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
	glPushMatrix();
	glTranslatef(position.x-0.45, position.y, position.z);
	glScalef(1, 0.3, 1.2);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(position.x-0.85, position.y, position.z + 0.09);
	glScalef(3, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(position.x - 0.85, position.y, position.z - 0.09);
	glScalef(3, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(position.x - 0.85, position.y, position.z+0.26);
	glScalef(3, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(position.x - 0.85, position.y, position.z - 0.26);
	glScalef(3, 1, 1);
	glutSolidCube(0.1);
	glPopMatrix();

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
	if (movement == ROBOT_HEAD_UP)
		head_lift++;
	if (movement == ROBOT_HEAD_DOWN)
		head_lift--;
	if (movement == ROBOT_HEAD_RIGHT)
		head_rotation--;
	if (movement == ROBOT_HEAD_LEFT)
		head_rotation++;
}

void Robot::moveHead(ROBOT_HEAD_MOVEMENT movement, float angle)
{
	if (movement == ROBOT_HEAD_UP_DOWN )
		head_lift = angle;
	if (movement == ROBOT_HEAD_RIGHT)
		head_rotation = -angle;
	if (movement == ROBOT_HEAD_LEFT)
		head_rotation = -angle;
}

void Robot::draw() {
	
	applyMaterial(material1, 0);
	glPushMatrix();
	translateToNewPosition();
	rotateToNewAngle();
	glPushMatrix();
	glTranslatef(0, 0.475, 0);
	drawHead();
	drawBody();
	drawHand();
	glPopMatrix();
	glPushMatrix();
	//Wheels
	Tools::assignMaterial(black_rubber);
	glTranslatef(-0.6,0.2,-0.6);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.6, 0.2, -0.6);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.6, 0.2, 0.6);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();
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
		translated_position = move_direction * amount * 0.1;
		amount_move = amount;
	} else {
		translated_position = move_direction * (-amount) * 0.1;
		amount_move = -amount;
	}
	
}

void Robot::applyJointRotationAndLift(ROBOT_JOINT joint)
{
	switch (joint) {
	case ROBOT_SHOULDER:
		//glRotatef(-90, 1, 0, 0);
		glTranslatef(shoulder_position_to_robot.x, shoulder_position_to_robot.y, shoulder_position_to_robot.z);
		glRotatef(shoulder_rotation, 1, 0, 0);
		glRotatef(shoulder_lift, 0, 0, 1);
		glTranslatef(-shoulder_position_to_robot.x, -shoulder_position_to_robot.y, -shoulder_position_to_robot.z);
		//glRotatef(90, 1, 0, 0);
		break;
	case ROBOT_ELBOW:
		glTranslatef(elbow_position_to_robot.x, elbow_position_to_robot.y, shoulder_position_to_robot.z);
		glRotatef(elbow_rotation, 1, 0, 0);
		glRotatef(elbow_lift, 0, 0, 1);
		glTranslatef(-elbow_position_to_robot.x, -elbow_position_to_robot.y, -shoulder_position_to_robot.z);
		break;
	case ROBOT_PALM:
		glTranslatef(palm_position_to_robot.x, palm_position_to_robot.y, palm_position_to_robot.z);
		glRotatef(palm_rotation, 1, 0, 0);
		glRotatef(palm_lift, 0, 0, 1);
		glTranslatef(-palm_position_to_robot.x, -palm_position_to_robot.y, -palm_position_to_robot.z);
		break;
	};
}

void Robot::applyMaterial(materialStruct maaterial, float emmision)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, maaterial.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, maaterial.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, maaterial.Ks);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, maaterial.Kd);
	glMaterialf(GL_FRONT, GL_EMISSION, emmision);
}


void Robot::rotateHandJoint(ROBOT_JOINT joint)
{
	switch (joint) {
	case ROBOT_SHOULDER:
		shoulder_rotation++;
		break;
	case ROBOT_ELBOW:
		elbow_rotation++;
		break;
	case ROBOT_PALM:
		palm_rotation++;
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
		if ((shoulder_lift + INITIAL_SHOULDER_ROTATION > 90 - HAND_DOWN_OFFSET && action == ROBOT_HAND_UP) || (shoulder_lift + INITIAL_SHOULDER_ROTATION < -90 + HAND_UP_OFFSET && action == ROBOT_HAND_DOWN))
			shoulder_lift = shoulder_lift;
		else {
			if (action == ROBOT_HAND_UP)
				shoulder_lift++;
			else
				shoulder_lift--;
		}	
		break;
	case ROBOT_ELBOW:
		if ((elbow_lift  > 180 - ELBOW_DOWN_OFFSET- INITIAL_ELBOW_ROTATION && action == ROBOT_HAND_UP) || (elbow_lift < -INITIAL_ELBOW_ROTATION -90 - ELBOW_UP_OFFSET && action == ROBOT_HAND_DOWN))
			elbow_lift = elbow_lift;
		else {
			if (action == ROBOT_HAND_UP)
				elbow_lift++;
			else
				elbow_lift--;
		}
		break;
	case ROBOT_PALM:
		if ((palm_lift > 180 - PALM_DOWN_OFFSET - INITIAL_PALM_ROTATION && action == ROBOT_HAND_UP) || (palm_lift < -INITIAL_PALM_ROTATION - 90 - PALM_UP_OFFSET && action == ROBOT_HAND_DOWN))
			palm_lift = palm_lift;
		else {
			if (action == ROBOT_HAND_UP)
				palm_lift++;
			else
				palm_lift--;
		}
		break;
	};
}

void Robot::liftHandJoint(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action, float amount)
{
	switch (joint) {
	case ROBOT_SHOULDER:
			if (action == ROBOT_HAND_UP)
				shoulder_lift = amount;
			else
				shoulder_lift = -amount;
		break;
	case ROBOT_ELBOW:
			if (action == ROBOT_HAND_UP)
				elbow_lift = amount;
			else
				elbow_lift = -amount;
		break;
	case ROBOT_PALM:
			if (action == ROBOT_HAND_UP)
				palm_lift = amount;
			else
				palm_lift = -amount;
		break;
	};
}

void Robot::rotate()
{
	angle++;
	move_direction = Vector3(sin(angle*(M_PI / 180)), 0, cos(angle * (M_PI / 180)));
	move_direction.normalize();
}

void Robot::rotate(float angle_new)
{
	angle = angle_new;
	move_direction = Vector3(sin(angle * (M_PI / 180)), 0, cos(angle * (M_PI / 180)));
	move_direction.normalize();
}

Vector3 Robot::getHeadPosition()
{
	return head_position;
}

void Robot::applyCameraRotation()
{
	glPushMatrix();
	glTranslatef(-translated_position.x, -translated_position.y, -translated_position.z);
	//glTranslatef(-head_position.x, -head_position.y, -head_position.z);
	glTranslatef(translated_position.x, translated_position.y, translated_position.z);
	glRotatef(-angle, 0, 1, 0);
	glTranslatef(-translated_position.x, -translated_position.y, -translated_position.z);
	//glTranslatef(head_position.x, head_position.y, head_position.z);*/
	//glScalef(-1, 1, -1);
	glPushMatrix();
	glTranslatef(-head_position.x, -head_position.y, -head_position.z- FP_CAMERA_OFFSET);

	glPushMatrix();
	glTranslatef(translated_position.x, translated_position.y, translated_position.z);
	glTranslatef(head_position.x, head_position.y, head_position.z+ FP_CAMERA_OFFSET);
	glRotatef(head_lift, 1, 0, 0);
	glTranslatef(-head_position.x, -head_position.y, -head_position.z- FP_CAMERA_OFFSET);
	glTranslatef(-translated_position.x, -translated_position.y, -translated_position.z);
	
	glTranslatef(translated_position.x, translated_position.y, translated_position.z);
	glTranslatef(head_position.x, head_position.y, head_position.z+ FP_CAMERA_OFFSET);
	glRotatef(-head_rotation, 0, 1, 0);
	glTranslatef(-head_position.x, -head_position.y, -head_position.z- FP_CAMERA_OFFSET);
	glTranslatef(-translated_position.x, -translated_position.y, -translated_position.z);

	glPushMatrix();

	//translateToNewPosition();
	//glTranslatef(translated_position.x, translated_position.y, translated_position.z);
	//glScalef(-1, 1, -1);
	//rotateToNewAngle();
	//glRotatef(-angle, 0, 1, 0);

	//glPushMatrix();
	/*glTranslatef(-head_position.x, -head_position.y, -head_position.z);
	glRotatef(-head_lift, 1, 0, 0);
	glTranslatef(head_position.x, head_position.y, head_position.z);
	//glPopMatrix();
	
	//glPushMatrix();
	glTranslatef(-head_position.x, -head_position.y, -head_position.z);
	glRotatef(-head_rotation, 0, 1, 0);
	glTranslatef(head_position.x, head_position.y, head_position.z);
	//glPopMatrix();*/
	
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
	translated_position_old = translated_position;
}