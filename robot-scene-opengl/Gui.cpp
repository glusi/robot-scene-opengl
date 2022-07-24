#include "Gui.h"

Gui::Gui()
{
    buttons = *(new std::list<Button>());
}

Gui::Gui(std::list<Button> new_list)
{
    buttons = new_list;
}

void Gui::draw()
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.8, 0.8, 0.8);
    glNormal3d(0, 0, 1);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-60.0f, 100.0f, 0.0f);
    glTexCoord2f(0.0, 1.0); glVertex3f(-100.0f, 100.0f, 0.0f);
    glTexCoord2f(1.0, 1.0); glVertex3f(-100.0f, -100.0f, 0.0f);
    glTexCoord2f(1.0, 0.0); glVertex3f(-60.0f, -100.0f, 0.0f);  
    
    glEnd();
    glDisable(GL_TEXTURE);
    drawButton(Button(Vector3(-85,-60,0), 10.0, 10.0, "hello"));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
}

void Gui::drawAllButtons()
{
    for (Button button : buttons)
    {
        drawButton(button);
    }
}

void Gui::drawButton(Button button) {
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(button.position.x, button.position.y, 0.0f);
    glVertex3f(button.position.x + button.width, button.position.y, 0.0f);
    glVertex3f(button.position.x + button.width, button.position.y + button.length, 0.0f);
    glVertex3f(button.position.x, button.position.y + button.length, 0.0f);
    glEnd();
}