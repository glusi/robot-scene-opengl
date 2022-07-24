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
    glDisable(GL_TEXTURE_2D);
    //drawButton(Button(Vector3(-85,-60,0), 10.0, 10.0, "hello"));
    drawAllButtons();

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

//Draws text given in <text>, in the position (<x>,<y>), that can be resized according to window size
void Gui::drawText(float x, float y, std::string text, Vector3 color) {
    glColor3f(color.x, color.y, color.z);
    glPushMatrix();
    //glRasterPos2f(x, y);
    glTranslatef(x+0.5, y+2.5, 0);
    glScalef(0.05, 0.05, 0);
    //glLineWidth(1);
    glutStrokeString(GLUT_STROKE_ROMAN, (unsigned char*)text.c_str());
    glLoadIdentity();
    glPopMatrix();

}

void Gui::drawButton(Button button) {
    glColor3f(0.9, 0.9, 0.9);
    //glEnable(C)
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_QUADS);
    glVertex3f(button.position.x-0.05, button.position.y - 0.05, 0.0f);
    glVertex3f(button.position.x + button.width + 0.05, button.position.y - 0.05, 0.0f);
    glVertex3f(button.position.x + button.width + 0.05, button.position.y + button.length + 0.05, 0.0f);
    glVertex3f(button.position.x - 0.05, button.position.y + button.length + 0.05, 0.0f);
    glEnd();
    glColor3f(0.2, 0.2, 0.2);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
    glVertex3f(button.position.x, button.position.y, 0.0f);
    glVertex3f(button.position.x + button.width, button.position.y, 0.0f);
    glVertex3f(button.position.x + button.width, button.position.y + button.length, 0.0f);
    glVertex3f(button.position.x, button.position.y + button.length, 0.0f);
    glEnd();
    drawText(button.position.x, button.position.y, button.name, Vector3(0.5,1.0,1.0));
}