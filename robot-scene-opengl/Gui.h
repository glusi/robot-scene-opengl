#pragma once
#include <GL/glut.h>
#include <GL\freeglut_ext.h>
#include <string>
#include "Button.h"
#include <list>

class Gui
{
	std::list<Button> buttons;
	void drawButton(Button button);
public:
	Gui();
	Gui(std::list<Button> new_list);
	void draw();
	void drawAllButtons();
};

