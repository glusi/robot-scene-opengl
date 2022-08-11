#include "Scene.h"
#include "../third-party/imgui/imgui_impl_glut.h"

void Scene::addDecorations()
{
	//Draw eating corner including table, two chairs, teapot and two glasses.
	buildEatingCorner();
	buildTVCorner();

	Tools::assignMaterial(wood, 0);
	//Draw door
	glPushMatrix();
	glTranslatef(-16.1, 0, 0);

	//The wooden door
	glPushMatrix();
	glTranslatef(0, 4.55, 0);
	glScalef(0.25, 9, 5);
	drawTexturedObject(TEXTURE_TABLE);
	glPopMatrix();

	//The door handle
	glPushMatrix();
	Tools::assignMaterial(silver, 0);
	glTranslatef(1, 5, 1.8);
	glutSolidSphere(0.2, 10, 10);
	glPopMatrix();

	glPopMatrix();

	//Draw ball
	glPushMatrix();
	Tools::assignMaterial(green_plastic, 0);
	glTranslatef(-11, 1, 14);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	//Draw cube
	glPushMatrix();
	Tools::assignMaterial(blue_rubber, 0);
	glTranslatef(-14, 1, 14);
	glutSolidCube(2);
	glPopMatrix();

	//Draw dodecahedron
	glPushMatrix();
	Tools::assignMaterial(jade, 0);
	glTranslatef(-12, 2.85, 14);
	glRotatef(45, 0, 0, 1);
	glScalef(0.75, 0.75, 0.75);
	glutSolidDodecahedron();
	glPopMatrix();

	//Draw box gold
	glPushMatrix();
	Tools::assignMaterial(polished_gold, 0);
	glTranslatef(-9, 0.125, 15);
	glRotatef(45, 0, 1, 0);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();
	//Draw box silver
	glPushMatrix();
	Tools::assignMaterial(silver, 0);
	glTranslatef(-10, 0.375, 15);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	//Draw window
	Tools::assignMaterial(materialTV, 1);
	texture.bindTexture(TEXTURE_WINDOW);
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	//Translate to needed position and angle
	glTranslatef(12.95, 6, -4);
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glBegin(GL_QUADS);
	//Map the window texture
	glTexCoord2f(0.0, 0.0); glVertex3f(-3, 3, -2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3, 3, 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(3, 3, 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(3, 3, -2);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Scene::buildEatingCorner()
{
	glPushMatrix();
	glTranslatef(-2, 0, -14);
	//Draw table top
	glColor3f(0.5f, 0.35f, 0.05f);
	glPushMatrix();
	glTranslatef(0, 4, 0);
	glScalef(6, 0.2, 4);
	Tools::assignMaterial(wood, 0);
	drawTexturedObject(TEXTURE_TABLE);
	glPopMatrix();

	Tools::assignMaterial(silver, 0);
	//Draw table legs
	//Draw leg 1
	glPushMatrix();
	glTranslatef(-2.5, 0, -1.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 4, 10, 5);
	glPopMatrix();
	//Draw leg 2
	glPushMatrix();
	glTranslatef(2.5, 0, -1.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 4, 10, 5);
	glPopMatrix();
	//Draw leg 3
	glPushMatrix();
	glTranslatef(-2.5, 0, 1.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 4, 10, 5);
	glPopMatrix();
	//Draw leg 4
	glPushMatrix();
	glTranslatef(2.5, 0, 1.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 4, 10, 5);
	glPopMatrix();
	//Draw metallic teapot
	Tools::assignMaterial(pewter_material, 0);
	glPushMatrix();
	glTranslatef(1, 5, 0);
	glRotatef(-200, 0, 1, 0);
	glutSolidTeapot(1);
	glPopMatrix();

	//Draw glasses
	glEnable(GL_COLOR_MATERIAL);
	Tools::assignMaterial(glass, 0);
	glColor4f(0.0f, 1.0f, 1.0f, 0.4);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	//First glass
	glPushMatrix();
	glTranslatef(-2, 5, 0);
	glRotatef(90, 1, 0, 0);
	Tools::drawCylinder(0.25, 1, 100);
	glPopMatrix();
	//Second glass
	glPushMatrix();
	glTranslatef(-1.2, 5, 1);
	glRotatef(90, 1, 0, 0);
	Tools::drawCylinder(0.25, 1, 100);
	glPopMatrix();
	glDisable(GL_BLEND);
	glDisable(GL_COLOR_MATERIAL);

	//Draw chair
	Tools::assignMaterial(wood, 0);
	buildChair();

	//Draw second chair translated and rotated
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glRotatef(180, 0, 1, 0);
	buildChair();
	glPopMatrix();

	glPopMatrix();
}

void Scene::buildTVCorner()
{
	glPushMatrix();
	glTranslatef(15, 0, 11);

	//Draw TV table
	Tools::assignMaterial(wood, 0);
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(6, 2, 3);

	drawTexturedObject(TEXTURE_TABLE);
	glPopMatrix();

	//Draw TV Screen
	Tools::assignMaterial(silver, 0);
	glPushMatrix();
	glTranslatef(0, 4, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(6, 4, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	//Draw image on TV
	Tools::assignMaterial(materialTV, 1);
	texture.bindTexture(TEXTURE_TV);
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(-4.25, 4, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	//Map the texture
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3, 4.1, -2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3, 4.1, 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(3, 4.1, 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(3, 4.1, -2);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	//build sofa
	glPushMatrix();
	glTranslatef(-10, 0, 0);

	//Draw sofa back
	glPushMatrix();
	glTranslatef(0, 2.25, 0);
	glScalef(0.25, 4.5, 9);
	Tools::assignMaterial(wood, 0);
	drawTexturedObject(TEXTURE_TABLE);
	glPopMatrix();
	
	//Draw sofa base
	glPushMatrix();
	glTranslatef(2.1, 1, 0);
	glScalef(4, 1.5, 9); 
	Tools::assignMaterial(fabric, 0);
	drawTexturedObject(TEXTURE_FABRIC);
	glPopMatrix();

	//Draw sofa pillow
	glPushMatrix();
	glTranslatef(0.6, 3, 0);
	glScalef(1, 3, 9);
	drawTexturedObject(TEXTURE_FABRIC);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void Scene::buildChair()
{
	Tools::assignMaterial(silver, 0);
	//Draw chair legs
	glPushMatrix();
	glTranslatef(-4, 0, 0);
	//Draw leg 1
	glPushMatrix();
	glTranslatef(-1.5, 0, -1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	//Draw leg 2
	glPushMatrix();
	glTranslatef(0, 0, -1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	//Draw leg 3
	glPushMatrix();
	glTranslatef(-1.5, 0, 1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	//Draw leg 4
	glPushMatrix();
	glTranslatef(0, 0, 1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	//Draw chair back holds
	//Draw hold 1
	glPushMatrix();
	glTranslatef(-1.5, 2, 1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	//Draw hold 2
	glPushMatrix();
	glTranslatef(-1.5, 2, -1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	glPopMatrix();

	//Draw chair sitting top
	Tools::assignMaterial(wood, 0);
	glDisable(GL_BLEND);
	glDisable(GL_COLOR_MATERIAL);
	glColor3f(0.5f, 0.35f, 0.05f);
	glPushMatrix();
	glTranslatef(-4.75, 2, 0);
	glScalef(2, 0.2, 2.2);
	drawTexturedObject(TEXTURE_TABLE);
	glPopMatrix();

	//Draw hair back
	Tools::assignMaterial(wood, 0);
	glPushMatrix();
	glTranslatef(-5.5, 4, 0);
	glScalef(0.2, 1, 2.2);
	drawTexturedObject(TEXTURE_TABLE);
	glPopMatrix();

}

Scene::Scene()
{
	texture = Texture();
	camera = new Camera();
	floor = new Floor();
	lights = new Lights();
	robot = new Robot();
}

void Scene::draw() {
	//Draw camera
	camera->draw();
	//If in first person camera mode, apply rotation and translation according to robot state
	if (camera->getIFirstPerson())
		robot->applyCameraRotation();
	//Draw lights
	lights->draw();
	//Draw floor
	texture.bindTexture(TEXTURE_FLOOR);
	floor->draw();
	//Draw walls
	texture.bindTexture(TEXTURE_WALL);
	floor->buildWalls();
	//Draw robot
	robot->draw();
	//Draw more decorations in room
	addDecorations();
	//Draw sphere for point light
	lights->drawOrb();
	//Draw a 2d GUI message about current camera mode
	gui.draw();
	glPopMatrix();
	//If in first person camera mode, pop used matrices for rotation and translation according to robot state
	if (camera->getIFirstPerson())
	{
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}
	//Update for the last frame values
	robot->updateOldPosition();
}

void Scene::moveCamera(USER_ACTION_CAMERA action)
{
	camera->moveCamera(action);
}

void Scene::moveCamera(USER_ACTION_CAMERA action, float amount)
{
	camera->moveCamera(action, amount);
}

void Scene::rotateCamera(CAMERA_MOVE camera_type)
{
	if (camera_type == CAMERA_ROTATE)
		camera->rotateCamera();
	else
		camera->liftCamera();
}


void Scene::rotateCamera(CAMERA_MOVE camera_type, float angle)
{
	if (camera_type == CAMERA_ROTATE)
		camera->rotateCamera(angle);
	else
		camera->liftCamera(angle);
}

void Scene::moveRobot(ROBOT_MOVE_DIRECTION direction)
{
	robot->move(direction);
}

void Scene::moveRobot(ROBOT_MOVE_DIRECTION direction, float amount)
{
	robot->move(direction, amount);
}

void Scene::rotateRobot(ROBOT_ROTATION rotation_type)
{
	robot->rotate(rotation_type);
}

void Scene::rotateRobot(float angle)
{
	robot->rotate(angle);
}

void Scene::rotateRobotHand(ROBOT_JOINT joint)
{
	robot->rotateHandJoint(joint);
}

void Scene::rotateRobotHand(ROBOT_JOINT joint, float amount)
{
	robot->rotateHandJoint(joint, amount);
}

void Scene::liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action)
{
	robot->liftHandJoint(joint, action);
}

void Scene::liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action, float amount)
{
	robot->liftHandJoint(joint, action, amount);
}

void Scene::moveRobotHead(ROBOT_HEAD_MOVEMENT movement)
{
	robot->moveHead(movement);
}

void Scene::moveRobotHead(ROBOT_HEAD_MOVEMENT movement, float angle)
{
	robot->moveHead(movement, angle);
}

void Scene::setIFirstPerson(int isFirstPerson)
{
	camera->setIFirstPerson(isFirstPerson);
	bool mode = (isFirstPerson == 0) ? true : false;
	gui.setMode(mode);
}

Vector3 Scene::getCameraPosition()
{
	return camera->getCameraPosition();
}

Vector3 Scene::getHeadPosition()
{
	return robot->getHeadPosition();
}

void Scene::adjustAmbientLight(float* color)
{
	lights->adjustAmbientLight(color);
}

float* Scene::getAmbientColor()
{
	return lights->getAmbientColor();
}

float Scene::getRobotRotation()
{
	return robot->getRobotRotation();
}

float Scene::getRobotPosition()
{
	return robot->getRobotPosition();
}

float Scene::getShoulderLift()
{
	return robot->getShoulderLift();
}

float Scene::getShoulderRotation()
{
	return robot->getShoulderRotation();
}

float Scene::getElbowLift()
{
	return robot->getElbowLift();
}

float Scene::getElbowRotation()
{
	return robot->getElbowRotation();
}

float Scene::getPalmLift()
{
	return robot->getPalmLift();
}

float Scene::getPalmRotation()
{
	return robot->getPalmRotation();
}

int Scene::getHelpImageWidth()
{
	return texture.getHelpImageWidth();
}

int Scene::getHelpImageHeight()
{
	return texture.getHelpImageHeight();
}

GLuint Scene::getgetHelpImageTexture()
{
	return texture.getHelpImageTexture();
}

float Scene::getHeadRotation()
{
	return robot->getHeadRotation();
}

float Scene::getHeadLift()
{
	return robot->getHeadLift();
}

void Scene::drawTexturedObject(TEXTURE_TYPE tex)
{
	texture.bindTexture(tex);
	glEnable(GL_TEXTURE_2D);
	Tools::glutSolidCube(1);
	glDisable(GL_TEXTURE_2D);
}

float Scene::getPointLightPosition(POINT_LIGHT_POS axis)
{
	return lights->getPointLightPosition(axis);
}

void Scene::applyPointLightPos(Vector3 point_light_position)
{
	lights->applyPointLightPos(point_light_position);
}

float* Scene::getPointLightColor()
{
	return lights->getPointLightColor();
}

void Scene::adjustPointLight(float* color)
{
	lights->adjustPointLight(color);
}

void Scene::setWidth(float width)
{
	this->width = width;
}

void Scene::setHeight(float height)
{
	this->height = height;
}

float Scene::getWidth()
{
	return width;
}

float Scene::getHeight()
{
	return height;
}

void Scene::disableAmbient(bool enabled)
{
	lights->disableAmbient(enabled);
}

void Scene::disablePoint(bool enabled)
{
	lights->disablePoint(enabled);
}

float Scene::getCameraAngle()
{
	return camera->getCameraAngle();
}

float Scene::getCameraLift()
{
	return camera->getCameraLift();
}




