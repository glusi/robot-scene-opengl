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
#include "Gui.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

//Default values for initial window
constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 500;
constexpr auto WINDOW_POSITION_X = 50;
constexpr auto WINDOW_POSITION_Y = 50;


//the current width and height of the window
GLsizei new_width, new_height;
InitialScene scene;

bool first_time_right_mouse = true;
float xlast_mouse =0.0, ylast_mouse =0.0;

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
    glClear(GL_DEPTH_BUFFER_BIT);

    setPrespProjection();   
    scene.draw();
    drawAxis();
    Gui gui;
    gui.draw();
    
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
    case 'r': scene.rotateRobot(); break; //Rotate Robot
    case 't': scene.rotateRobotHand(ROBOT_SHOULDER); break;
    case 'y': scene.rotateRobotHand(ROBOT_ELBOW); break;
    case 'u': scene.rotateRobotHand(ROBOT_PALM); break;
    case 'f': scene.liftRobotHand(ROBOT_SHOULDER, ROBOT_HAND_UP); break;
    case 'g': scene.liftRobotHand(ROBOT_SHOULDER, ROBOT_HAND_DOWN); break;
    case 'h': scene.liftRobotHand(ROBOT_ELBOW, ROBOT_HAND_UP); break;
    case 'j': scene.liftRobotHand(ROBOT_ELBOW, ROBOT_HAND_DOWN); break;
    case 'c': scene.moveRobotHead(ROBOT_HEAD_UP); break;
    case 'v': scene.moveRobotHead(ROBOT_HEAD_DOWN); break;
    case 'b': scene.moveRobotHead(ROBOT_HEAD_RIGHT); break;
    case 'n': scene.moveRobotHead(ROBOT_HEAD_LEFT); break;
    case 27:
        exit(1);
        break;
    };
    glutPostRedisplay();
}

void MyGlutSpecialFunc(int Key, int x, int y) {
    switch (Key)
    {
    case GLUT_KEY_UP: scene.moveRobot(ROBOT_MOVE_FRONT); break;
    case GLUT_KEY_DOWN: scene.moveRobot(ROBOT_MOVE_BACK); break;
    case GLUT_KEY_HOME:  break;
    case GLUT_KEY_END:  break;
    case 27:
        exit(1);
        break;
    };
    glutPostRedisplay();
}

void MyMouseFunc(int button, int state, int xpos, int ypos) {
    /*if (button == GLUT_RIGHT_BUTTON){
        int centerX = new_width / 2;
        int centerY = new_height / 2;

        int deltaX = -1 * (xpos - centerX);
        int deltaY = -1 * (ypos - centerY);

        if (deltaX != 0 || deltaY != 0) {
            scene.rotateCamera(deltaX, deltaY);
        }
    }*/

   /* if (button == GLUT_RIGHT_BUTTON){
        if (first_time_right_mouse) {
            xlast_mouse = xpos;
            ylast_mouse = ypos;
            first_time_right_mouse = false;
        }
        else {
            float xoffset = xpos - xlast_mouse;
            float yoffset = ylast_mouse - ypos;
            xlast_mouse = xpos;
            ylast_mouse = ypos;
            scene.rotateCamera(xoffset, yoffset);
        }
        
    }*/

}

//The Initialize function, called once:    
void Init() {
    glEnable(GL_NORMALIZE);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);                            // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);               // Black Background
    glClearDepth(1.0f);                                 // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);                            // Depth Buffer Setup                       // Enables Depth Testing
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Really Nice Perspective Calculations
    glEnable(GL_LIGHTING);
   // glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
   // glFrontFace(GL_CCW);
   // glCullFace(GL_BACK);
   // glEnable(GL_CULL_FACE);
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char* data = stbi_load(FLOOR_TEXTURE_PATH, &width, &height, &nrChannels, 3);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    //Set initial parameters for the window
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutCreateWindow("robot-scene");
    Init();
    glutDisplayFunc(display);
    glutReshapeFunc(windowResize);
    glutKeyboardFunc(MyKeyboardFunc);
    glutMouseFunc(MyMouseFunc);
    glutSpecialUpFunc(MyGlutSpecialFunc);
    glutMainLoop();
    return 0;
}

