#include "Robot.h"

Robot::Robot()
{
	move_direction = Vector3(0, 0, 1);
	translated_position = Vector3::zeroVector();
	angle = 0.0;
	shoulder_rotation = 0.0;
	elbow_rotation = 0.0;
	palm_rotation = 0.0;
	shoulder_position_to_robot = Vector3(-0.8, 3.5, 0);//Vector3(-0.8, 3.5, 0);
	elbow_position_to_robot = Vector3(-1.7, 2.6, 0);
	palm_position_to_robot = Vector3(-2.6, 2.35, 0);
}

void Robot::drawHand()
{
	//drawJoint(Vector3(0.8, 3.5, 0), 90, ROTATED_AROUND_X, -45, ROTATED_AROUND_Z, Vector3(1, 0, 0), 1.2);
	//drawJoint(Vector3(1.7, 2.5, 0), 90, ROTATED_AROUND_X, 15, ROTATED_AROUND_Z, Vector3(1, 0, 0), 1);
	glPushMatrix();
	//glLoadIdentity();
	drawJoint(shoulder_position_to_robot);
	applyJointRotation(ROBOT_SHOULDER);
	drawTube(shoulder_position_to_robot, -90, ROTATED_AROUND_X, 45, ROTATED_AROUND_Z, Vector3(1, 0, 0), 1.2);
	drawJoint(elbow_position_to_robot);
	glPushMatrix();
	applyJointRotation(ROBOT_ELBOW);
	drawTube(elbow_position_to_robot, -90, ROTATED_AROUND_X, 15, ROTATED_AROUND_Z, Vector3(1, 0, 0), 1);
	drawJoint(palm_position_to_robot);
	glPushMatrix();
	applyJointRotation(ROBOT_PALM);
	drawPalm(palm_position_to_robot);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	
}

void Robot::drawTube(Vector3 position, float angle1, ROTATION_TYPE rotation_type1, float angle2, ROTATION_TYPE rotation_type2, Vector3 color, float length)
{
	glColor3f(color.x, color.y, color.z);
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	Tools::rotate(angle2, rotation_type2);
	Tools::rotate(angle1, rotation_type1);
	Tools::drawCylinder(ROBOT_HAND_SIZE, length, 100);
	glPopMatrix();
}

void Robot::drawHead()
{
	glPushMatrix();
	glTranslatef(0, 4.75, 0);
	glScalef(0.75, 0.75, 0.75);
	glColor3f(0.0f, 1.0f, 1.0f);//Blue
	glutSolidSphere(1.0, 100, 100);
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

void Robot::drawPalm(Vector3 poistion)
{

}

void Robot::translateToNewPosition() {
	glTranslatef(translated_position.x, translated_position.y, translated_position.z);
}

void Robot::rotateToNewAngle()
{
	glRotatef(angle, 0, 1, 0);
}





void Robot::moveHead(float left, float right, float up, float down)
{
}

void Robot::draw() {
	
	glColor3f(0.0f, 1.0f, 1.0f);//Blue
	glMaterialfv(GL_FRONT, GL_AMBIENT, material1.Ka);
	glMaterialf(GL_FRONT, GL_SHININESS, material1.n);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material1.Ks);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material1.Kd);
	glMaterialf(GL_FRONT, GL_EMISSION, 0);
	
	glPushMatrix();
	translateToNewPosition();
	rotateToNewAngle();
	drawHead();
	drawBody();
	drawHand();
	glPopMatrix();
}

void Robot::move(ROBOT_MOVE_DIRECTION direction)
{
	if(direction == ROBOT_MOVE_FRONT)
		translated_position += move_direction;
	else
		translated_position -= move_direction;
}

void Robot::applyJointRotation(ROBOT_JOINT joint)
{
	switch (joint) {
	case ROBOT_SHOULDER:
		//glRotatef(-90, 1, 0, 0);
		glTranslatef(shoulder_position_to_robot.x, shoulder_position_to_robot.y, shoulder_position_to_robot.z);
		glRotatef(shoulder_rotation, 1, 0, 0);
		glTranslatef(-shoulder_position_to_robot.x, -shoulder_position_to_robot.y, -shoulder_position_to_robot.z);
		//glRotatef(90, 1, 0, 0);
		break;
	case ROBOT_ELBOW:
		glTranslatef(elbow_position_to_robot.x, elbow_position_to_robot.y, shoulder_position_to_robot.z);
		glRotatef(elbow_rotation, 1, 0, 0);
		glTranslatef(-elbow_position_to_robot.x, -elbow_position_to_robot.y, -shoulder_position_to_robot.z);
		break;
	case ROBOT_PALM:
		glTranslatef(-palm_position_to_robot.x, -palm_position_to_robot.y, -palm_position_to_robot.z);
		glRotatef(palm_rotation, 1, 0, 0);
		glTranslatef(palm_position_to_robot.x, palm_position_to_robot.y, palm_position_to_robot.z);
		break;
	};
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

void Robot::rotate()
{
	angle++;
	move_direction = Vector3(sin(angle*(M_PI / 180)), 0, cos(angle * (M_PI / 180)));
	move_direction.normalize();
}
