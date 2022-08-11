#include "Gui.h"


void Gui::draw()
{
    //Disable all 3D parameters - depth and lightning
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    //Create 2D view on the screen to project on
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.8, 0.8, 0.8);
    glNormal3d(0, 0, 1);
    //Print current mode on the right left corner
    if (camera_mode)
        drawText(55, 90, "Camera Mode", color_font);
    else
        drawText(60, 90, "Robot Mode", color_font);
    //Enable all 3D parameters - depth and lightning
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
    glLineWidth(1.7);
    glutStrokeString(GLUT_STROKE_ROMAN, (unsigned char*)text.c_str());
    glLoadIdentity();
    glPopMatrix();

}

/**
 * Setter for camera mode boolean
 */
void Gui::setMode(bool mode)
{
    camera_mode = mode;
}

