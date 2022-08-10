#include "Gui.h"
#include "../third-party/imagui/imgui.h"

Gui::Gui()
{
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
    if (camera_mode)
        drawText(55, 90, "Camera Mode", color_font);
    else
        drawText(60, 90, "Robot Mode", color_font);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
	
}


//Draws text given in <text>, in the position (<x>,<y>), that can be resized according to window size
void Gui::drawText(float x, float y, std::string text, Vector3 color) {
    glColor3f(color.x, color.y, color.z);
    glPushMatrix();
    glRasterPos2f(x, y);
    glTranslatef(x+0.5, y+2.5, 0);
    glScalef(0.05, 0.05, 0);
    glLineWidth(1.5);
    glutStrokeString(GLUT_STROKE_ROMAN, (unsigned char*)text.c_str());
    glLoadIdentity();
    glPopMatrix();

}

void Gui::setMode(bool mode)
{
    camera_mode = mode;
}
