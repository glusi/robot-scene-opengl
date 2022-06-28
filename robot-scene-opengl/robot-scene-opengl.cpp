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

//Default values for initial window
constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 500;
constexpr auto WINDOW_POSITION_X = 50;
constexpr auto WINDOW_POSITION_Y = 50;


//the current width and height of the window
GLsizei new_width, new_height;


void display() {
    //Clears
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);



    glFlush();
    glutSwapBuffers();
}



// Handle pressing any key, so that user can switch between Orthogonal and Perspective projection
void MyKeyboardFunc(unsigned char Key, int x, int y)
{

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

