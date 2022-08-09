#include "Initialscene.h"
#include "../third-party/imgui/imgui_impl_glut.h"


void InitialScene::addDecorations()
{
	buildEatingCorner();
	buildTVCorner();

	//Door
	glPushMatrix();
	glTranslatef(-16.1, 0, 0);

	glPushMatrix();
	glTranslatef(0, 4.55, 0);
	glScalef(0.25, 9, 5);
	drawTexturedObject(TEXTURE_TABLE, material2);
	glPopMatrix();

	glPushMatrix();
	Tools::assignMaterial(silver);
	glTranslatef(1, 5, 1.8);
	glutSolidSphere(0.2, 10, 10);
	glPopMatrix();

	glPopMatrix();

	//ball
	glPushMatrix();
	Tools::assignMaterial(green_plastic);
	glTranslatef(-11, 1, 14);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	Tools::assignMaterial(blue_rubber);
	glTranslatef(-14, 1, 14);
	glutSolidCube(2);
	glPopMatrix();


	glPushMatrix();
	Tools::assignMaterial(jade);
	glTranslatef(-12, 2.85, 14);
	glRotatef(45, 0, 0, 1);
	glScalef(0.75, 0.75, 0.75);
	glutSolidDodecahedron();
	glPopMatrix();

	Tools::assignMaterial(silver);

	
}

void InitialScene::buildEatingCorner()
{
	glPushMatrix();
	glTranslatef(-2, 0, -14);
	//Table top
	glColor3f(0.5f, 0.35f, 0.05f);
	glPushMatrix();
	glTranslatef(0, 4, 0);
	glScalef(6, 0.2, 4);
	drawTexturedObject(TEXTURE_TABLE, material2);
	glPopMatrix();
	

	/*texture.bindTexture(TEXTURE_TABLE);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-3, 4.1, -2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-3, 4.1, 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(3, 4.1, 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(3, 4.1, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);*/
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
	Tools::assignMaterial(pewter_material);
	glPushMatrix();
	glTranslatef(1, 5, 0);
	glRotatef(-200, 0, 1, 0);
	glutSolidTeapot(1);
	glPopMatrix();

	//material2es
	glEnable(GL_COLOR_MATERIAL);
	//Tools::assignMaterial(material2);
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
	glTranslatef(-1, 0, 0);
	glRotatef(180, 0, 1, 0);
	buildChair();
	glPopMatrix();

	glPopMatrix();

	
}

void InitialScene::buildTVCorner()
{
	glPushMatrix();
	glTranslatef(15, 0, 11);

	//TV table
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(6, 2, 3);
	drawTexturedObject(TEXTURE_TABLE, material2);
	glPopMatrix();

	//TV
	Tools::assignMaterial(silver);
	glPushMatrix();
	glTranslatef(0, 4, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(6, 4, 0.2);
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

	//build sofa
	glPushMatrix();
	glTranslatef(-10, 0, 0);

	glPushMatrix();
	glScalef(0.25,9,9);
	drawTexturedObject(TEXTURE_TABLE, material2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.1, 0, 0);
	glScalef(4, 3, 9);
	drawTexturedObject(TEXTURE_FABRIC, material2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, 3, 0);
	glScalef(1, 3, 9);
	drawTexturedObject(TEXTURE_FABRIC, material2);
	glPopMatrix();

	glPopMatrix();

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
	//holds
	glPushMatrix();
	glTranslatef(-1.5, 2, 1);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glutSolidCylinder(0.1, 2, 10, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.5, 2, -1);
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
	drawTexturedObject(TEXTURE_TABLE, material2);
	glPopMatrix();

	//Chair back
	glPushMatrix();
	glTranslatef(-5.5, 4, 0);
	glScalef(0.2, 1 , 2.2);
	drawTexturedObject(TEXTURE_TABLE, material2);
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
	lights->draw();
	if(camera->getIFirstPerson())
		robot->applyCameraRotation();
	
	texture.bindTexture(TEXTURE_FLOOR);
	floor->draw();
	texture.bindTexture(TEXTURE_WALL);
	floor->buildWalls();
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
	if (camera->getIFirstPerson())
	{
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}
	robot->updateOldPosition();
	
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

void InitialScene::rotateRobotHand(ROBOT_JOINT joint, float amount)
{
	robot->rotateHandJoint(joint, amount);
}

void InitialScene::liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action)
{
	robot->liftHandJoint(joint, action);
}

void InitialScene::liftRobotHand(ROBOT_JOINT joint, ROBOT_UP_DOWN_ACTION action, float amount)
{
	robot->liftHandJoint(joint, action, amount);
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

float InitialScene::getRobotRotation()
{
	return robot->getRobotRotation();
}

float InitialScene::getRobotPosition()
{
	return robot->getRobotPosition();
}

float InitialScene::getShoulderLift()
{
	return robot->getShoulderLift();
}

float InitialScene::getShoulderRotation()
{
	return robot->getShoulderRotation();
}

float InitialScene::getElbowLift()
{
	return robot->getElbowLift();
}

float InitialScene::getElbowRotation()
{
	return robot->getElbowRotation();
}

float InitialScene::getPalmLift()
{
	return robot->getPalmLift();
}

float InitialScene::getPalmRotation()
{
	return robot->getPalmRotation();
}

GLuint InitialScene::getTextureId(TEXTURE_TYPE texture)
{
	GLuint res = this->texture.getTextureId(texture);
	return res;
}

int InitialScene::getHelpImageWidth()
{
	return texture.getHelpImageWidth();
}

int InitialScene::getHelpImageHeight()
{
	return texture.getHelpImageHeight();
}

GLuint InitialScene::getgetHelpImageTexture()
{
	return texture.getgetHelpImageTexture();
}

float InitialScene::getHeadRotation()
{
	return robot->getHeadRotation();
}

float InitialScene::getHeadLift()
{
	return robot->getHeadLift();
}

void InitialScene::drawTexturedObject(TEXTURE_TYPE tex , materialStruct material)
{
	//Tools::assignMaterial(material);
	texture.bindTexture(tex);
	glEnable(GL_TEXTURE_2D);
	Tools::glutSolidCube(1);
	glDisable(GL_TEXTURE_2D);
}

float InitialScene::getPointLightPosition(POINT_LIGHT_POS axis)
{
	return lights->getPointLightPosition(axis);
}

void InitialScene::applyPointLightPos(Vector3 point_light_position)
{
	lights->applyPointLightPos(point_light_position);
}

float* InitialScene::getPointLightColor()
{
	return lights->getPointLightColor();
}

void InitialScene::adjustPointLight(float* color)
{
	lights->adjustPointLight(color);
}

void InitialScene::setWidth(float width)
{
	this->width = width;
}

void InitialScene::setHeight(float height)
{
	this->height = height;
}

float InitialScene::getWidth()
{
	return width;
}

float InitialScene::getHeight()
{
	return height;
}




