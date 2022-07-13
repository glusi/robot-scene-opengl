#include "InitialScene.h"

void InitialScene::addDecorations()
{
	glPushMatrix();
	glTranslatef(-2, 0, -6);
	//Table top
	glColor3f(0.5f, 0.35f, 0.05f);
	glPushMatrix();
	glTranslatef(0, 4, 0);
	glScalef(6, 0.2, 4);
	glutSolidCube(1);
	glPopMatrix();

	texture.bindTexture(TEXTURE_TABLE);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3, 4.1, -2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3, 4.1, 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(3, 4.1, 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(3, 4.1, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	Tools::assignMaterial(silver);
	//Table legs
	glPushMatrix();
	glTranslatef(-2.5, 0, -1.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 4, 10, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.5, 0, -1.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 4, 10, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.5, 0, 1.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 4, 10, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.5, 0, 1.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 4, 10, 5);
	glPopMatrix();
	//Teapot
	Tools::assignMaterial(polished_copper);
	glPushMatrix();
	glTranslatef(1, 5, 0);
	glRotatef(-200, 0, 1, 0);
	glutSolidTeapot(1);
	glPopMatrix();

	//Glasses
	glEnable(GL_COLOR_MATERIAL);
	//Tools::assignMaterial(glass);
	glColor4f(0.0f, 1.0f, 1.0f, 0.5);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glPushMatrix();
	glTranslatef(-2, 5, 0);
	glRotatef(90, 1, 0, 0);
	Tools::drawCylinder(0.25,1,100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.2, 5, 1);
	glRotatef(90, 1, 0, 0);
	Tools::drawCylinder(0.25, 1, 100);
	glPopMatrix();
	glDisable(GL_BLEND);
	glDisable(GL_COLOR_MATERIAL);

	glPopMatrix();
}

InitialScene::InitialScene() {
	texture = Texture();
	camera = new Camera();
	floor = new Floor();
	lights = new Lights();
	robot = new Robot();
	/*glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0);*/
	//glEnable(GL_CULL_FACE); //<-- missing
	//glCullFace(GL_BACK);

	//glEnable(GL_LIGHTING); //<-- missing
	//glEnable(GL_LIGHT0);
	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0); //Despite culling is on anyway,
											  //the back faces of 'solid' meshes don't
											  //need illumination

	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS);
}

void InitialScene::draw() {
	camera->draw();
	lights->draw();
	texture.bindTexture(TEXTURE_FLOOR);
	floor->draw();
	robot->draw();
	addDecorations();
}

void InitialScene::moveCamera(USER_ACTION_CAMERA action)
{
	camera->moveCamera(action);
}

void InitialScene::rotateCamera(int mouseX, int mouseY)
{
	camera->rotateCamera(mouseX, mouseY);
}

void InitialScene::moveRobot(ROBOT_MOVE_DIRECTION direction)
{
	robot->move(direction);
}

void InitialScene::rotateRobot()
{
	robot->rotate();
}

void InitialScene::rotateRobotHand(ROBOT_JOINT joint)
{
	robot->rotateHandJoint(joint);
}

void InitialScene::liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action)
{
	robot->liftHandJoint(joint, action);
}

void InitialScene::moveRobotHead(ROBOT_HEAD_MOVEMENT movement)
{
	robot->moveHead(movement);
}
