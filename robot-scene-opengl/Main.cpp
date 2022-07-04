#include <GL/glut.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <GL\freeglut_ext.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#include "InitialScene.h"
#include "Constants.h"

//Default values for initial window
constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 500;
constexpr auto WINDOW_POSITION_X = 50;
constexpr auto WINDOW_POSITION_Y = 50;


//the current width and height of the window
GLsizei new_width, new_height;
InitialScene scene;

// Set Perspective projection
void setPrespProjection() {
    glMatrixMode(GL_PROJECTION); // Set projection
    glLoadIdentity();
    gluPerspective(65, new_width / new_height, 1.0, 150.0);
}


//Draw axises X,Y and Z for reference and as shown in the assignment
void drawAxis() {
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    glEnd();
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 10, 0);
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 10);
    glEnd();

}

void display() {
    //Clears
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    setPrespProjection();
    
    
    scene.draw();

    drawAxis();
    glFlush();
    glutSwapBuffers();
}

// handles window reshape	
void windowResize(int width, int height) {
    //calculate scene  new scale width and hight
    float scale_width = width / (float)WINDOW_WIDTH;
    float scale_height = height / (float)WINDOW_HEIGHT;
    //find the deciding scale
    float scale = (scale_width > scale_height) ? scale_height : scale_width;
    //calculate new window's scale width and hight
    new_width = scale * WINDOW_WIDTH;
    new_height = scale * WINDOW_HEIGHT;
    //Set new viewport
    glViewport(0, height - new_height, new_width, new_height);
}

void MyKeyboardFunc(unsigned char Key, int x, int y)
{
    switch (Key)
    {
    
    case 'w': scene.moveCamera(CAMERA_FRONT); break; //Camera front
    case 'a': scene.moveCamera(CAMERA_LEFT); break; //Camera left
    case 's': scene.moveCamera(CAMERA_BACK); break; //Camera back
    case 'd': scene.moveCamera(CAMERA_RIGHT); break; //Camera right
    case 'e': scene.moveCamera(CAMERA_UP); break; //Camera up
    case 'q': scene.moveCamera(CAMERA_DOWN); break; //Camera down
    case GLUT_KEY_PAGE_UP: break;
    case GLUT_KEY_PAGE_DOWN:  break;
    case GLUT_KEY_HOME:  break;
    case GLUT_KEY_END:  break;
    case 27:
        exit(1);
        break;
    };
    glutPostRedisplay();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    //Set initial parameters for the window
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutCreateWindow("robot-scene");
    glutDisplayFunc(display);
    glutReshapeFunc(windowResize);
    glutKeyboardFunc(MyKeyboardFunc);
    glutMainLoop();
    return 0;
}

