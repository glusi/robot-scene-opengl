#include "InitialScene.h"
#include "../third-party/imgui/imgui_impl_glut.h"

void InitialScene::addDecorations()
{
	buildEatingCorner();
	buildTVCorner();
}

void InitialScene::buildEatingCorner()
{
	glPushMatrix();
	glTranslatef(-2, 0, -9);
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
	glColor4f(0.0f, 1.0f, 1.0f, 0.4);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glPushMatrix();
	glTranslatef(-2, 5, 0);
	glRotatef(90, 1, 0, 0);
	Tools::drawCylinder(0.25, 1, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.2, 5, 1);
	glRotatef(90, 1, 0, 0);
	Tools::drawCylinder(0.25, 1, 100);
	glPopMatrix();
	glDisable(GL_BLEND);
	glDisable(GL_COLOR_MATERIAL);

	buildChair();

	glPushMatrix();
	glTranslatef(8, 0, 0);
	buildChair();
	glPopMatrix();

	glPopMatrix();
}

void InitialScene::buildTVCorner()
{
	glPushMatrix();
	glTranslatef(13, 0, 11);

	//TV table
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(6, 2, 3);
	glutSolidCube(1);
	glPopMatrix();

	//TV
	glPushMatrix();
	glTranslatef(0, 3, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(6, 6, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	texture.bindTexture(TEXTURE_TV);
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(-4.25, 4, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	//glScalef(6, 5, 0.2);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3, 4.1, -2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3, 4.1, 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(3, 4.1, 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(3, 4.1, -2);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void InitialScene::buildChair()
{
	Tools::assignMaterial(silver);
	//Chair legs
	glPushMatrix();
	glTranslatef(-4, 0, 0);
	glPushMatrix();
	glTranslatef(-1.5, 0, -1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, -1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.5, 0, 1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, 1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	glPopMatrix();

	//chair top
	glDisable(GL_BLEND);
	glDisable(GL_COLOR_MATERIAL);
	glColor3f(0.5f, 0.35f, 0.05f);
	glPushMatrix();
	glTranslatef(-4.75, 2, 0);
	glScalef(2, 0.2, 2.2);
	glutSolidCube(1);
	glPopMatrix();

	
	
}

InitialScene::InitialScene()
{
	texture = Texture();
	camera = new Camera();
	floor = new Floor();
	lights = new Lights();
	robot = new Robot();
}

InitialScene::InitialScene(std::list<Button> buttons) {
	texture = Texture();
	camera = new Camera();
	floor = new Floor();
	lights = new Lights();
	robot = new Robot();
	gui = Gui(buttons);
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
	//glPushMatrix();
	if(camera->getIFirstPerson())
		robot->applyCameraRotation();
	lights->draw();
	texture.bindTexture(TEXTURE_FLOOR);
	floor->draw();
	robot->draw();
	addDecorations();
	texture.bindTexture(TEXTURE_BACKGROUND);
	//gui.draw();

	/*ImGui::Text("Hello, world %d", 123);
	if (ImGui::Button("Save"))
		printf("save");*/
	//ImGui::InputText("string", buf, IM_ARRAYSIZE(buf));
	//ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
	glPopMatrix();

}

void InitialScene::moveCamera(USER_ACTION_CAMERA action)
{
	camera->moveCamera(action);
}

void InitialScene::moveCamera(USER_ACTION_CAMERA action, float amount)
{
	camera->moveCamera(action, amount);
}

void InitialScene::rotateCamera(int mouseX, int mouseY)
{
	camera->rotateCamera(mouseX, mouseY);
}

void InitialScene::moveRobot(ROBOT_MOVE_DIRECTION direction)
{
	robot->move(direction);
}

void InitialScene::moveRobot(ROBOT_MOVE_DIRECTION direction, float amount)
{
	robot->move(direction, amount);
}

void InitialScene::rotateRobot()
{
	robot->rotate();
}

void InitialScene::rotateRobot(float angle)
{
	robot->rotate(angle);
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

void InitialScene::moveRobotHead(ROBOT_HEAD_MOVEMENT movement, float angle)
{
	robot->moveHead(movement, angle);
}

void InitialScene::setIFirstPerson(int isFirstPerson)
{
	camera->setIFirstPerson(isFirstPerson);
}

Vector3 InitialScene::getCameraPosition()
{
	return camera->getCameraPosition();
}

Vector3 InitialScene::getHeadPosition()
{
	return robot->getHeadPosition();
}

void InitialScene::adjustAmbientLight(float* color)
{
	lights->adjustAmbientLight(color);
}

float* InitialScene::getAmbientColor()
{
	return lights->getAmbientColor();
}
