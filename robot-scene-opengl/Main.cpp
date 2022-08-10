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
#include "Gui.h"
#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
#include "Menu.h"

//Default values for initial window
constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 500;
constexpr auto WINDOW_POSITION_X = 50;
constexpr auto WINDOW_POSITION_Y = 50;


//the current width and height of the window
GLsizei new_width, new_height;
Scene* scene;
Menu menu;

bool first_time_right_mouse = true;
float xlast_mouse =0.0, ylast_mouse =0.0;


static bool show_menu = true;
float aspect = 1;

bool is_ff = false;

// Set Perspective projection
void setPrespProjection() {
    glMatrixMode(GL_PROJECTION); // Set projection
    glLoadIdentity();
    gluPerspective(65, aspect, 1.0, 150.0);
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

    //imgui new frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGLUT_NewFrame();
    //ImGui::NewFrame();

    menu.createMenu();

    ImGui::Render();
    ImGuiIO& io = ImGui::GetIO();
    glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, io.DisplaySize.x / io.DisplaySize.y, 1.0, 150.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    scene->draw();
    //drawAxis();

    //ImGui_ImplGLUT_RenderDrawData();
 
    //ImGui_Impl_RenderDrawData(ImGui::GetDrawData());
    glDisable(GL_LIGHTING);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glEnable(GL_LIGHTING);


    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
    
}


void MyKeyboardFunc(unsigned char Key, int x, int y)
{
    switch (Key)
    { 
        //Camera
        case 'w': scene->moveCamera(CAMERA_FRONT); break; //Camera front
        case 's': scene->moveCamera(CAMERA_BACK); break; //Camera back
        case 'a': scene->moveCamera(CAMERA_RIGHT); break; //Camera right
        case 'd': scene->moveCamera(CAMERA_LEFT); break; //Camera left
        case 'z': scene->moveCamera(CAMERA_UP); break; //Camera up
        case 'x': scene->moveCamera(CAMERA_DOWN); break; //Camera down
        case 'q': scene->rotateCamera(CAMERA_ROTATE); break; //Camera rotate
        case 'e': scene->rotateCamera(CAMERA_LIFT); break; //Camera lift
        case 'c': is_ff = !is_ff; scene->setIFirstPerson(is_ff); break; //Camera control
        //Robot
        case 't': scene->moveRobot(ROBOT_MOVE_FRONT); break;
        case 'g': scene->moveRobot(ROBOT_MOVE_BACK); break;
        case 'r': scene->rotateRobot(ROBOT_ROTATE_RIGHT); break; //Rotate Robot
        case 'f': scene->rotateRobot(ROBOT_ROTATE_LEFT); break; //Rotate Robot

        case 'y': scene->liftRobotHand(ROBOT_SHOULDER, ROBOT_HAND_UP); break;
        case 'h': scene->liftRobotHand(ROBOT_SHOULDER, ROBOT_HAND_DOWN); break;
        case 'n': scene->rotateRobotHand(ROBOT_SHOULDER); break;
        case 'u': scene->liftRobotHand(ROBOT_ELBOW, ROBOT_HAND_UP); break;
        case 'j': scene->liftRobotHand(ROBOT_ELBOW, ROBOT_HAND_DOWN); break;
        case 'm': scene->rotateRobotHand(ROBOT_ELBOW); break;
        case 'i': scene->liftRobotHand(ROBOT_PALM, ROBOT_HAND_UP); break;
        case 'k': scene->liftRobotHand(ROBOT_PALM, ROBOT_HAND_DOWN); break;
        case ',': scene->rotateRobotHand(ROBOT_PALM); break;
        
        case 'o': scene->moveRobotHead(ROBOT_HEAD_UP); break;
        case 'l': scene->moveRobotHead(ROBOT_HEAD_DOWN); break;
        case 'v': scene->moveRobotHead(ROBOT_HEAD_RIGHT); break;
        case 'b': scene->moveRobotHead(ROBOT_HEAD_LEFT); break; 
    case 27:
        exit(1);
        break;
    };
    glutPostRedisplay();
}

void MyGlutSpecialFunc(int Key, int x, int y) {
    switch (Key)
    {
    case GLUT_KEY_UP: scene->moveRobot(ROBOT_MOVE_FRONT); break;
    case GLUT_KEY_DOWN: scene->moveRobot(ROBOT_MOVE_BACK); break;
    case GLUT_KEY_HOME:  break;
    case GLUT_KEY_END:  break;
    case 27:
        exit(1);
        break;
    };
    glutPostRedisplay();
}

void initImgui() {
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Setup Platform/Renderer bindings
    ImGui_ImplGLUT_Init();
    ImGui_ImplGLUT_InstallFuncs();
    ImGui_ImplOpenGL3_Init();

    // Setup style
    ImGui::StyleColorsClassic();

    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.2, 0.2, 0.2, 0.8);
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
    //glutIgnoreKeyRepeat(0);
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);
   // glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
   // glFrontFace(GL_CCW);
   // glCullFace(GL_BACK);
   // glEnable(GL_CULL_FACE);
    scene = new Scene();
    menu = Menu(scene);
    

}

void idleFucn() {
    display();
}

void reshapeFunc(GLint w, GLint h)
{
    // imgui reshape func
    ImGui_ImplGLUT_ReshapeFunc(w, h);
    new_width = w;
    new_height = h;
    glViewport(0, 0, w, h);
    aspect = float(w / h);
    scene->setWidth(w);
    scene->setHeight(h);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE | GLUT_STENCIL);
    //Set initial parameters for the window
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutCreateWindow("robot-scene");
    Init();
    glutIdleFunc(idleFucn);
    glutDisplayFunc(display);
    initImgui();
    glutReshapeFunc(reshapeFunc);
    glutKeyboardFunc(MyKeyboardFunc);
    //glutIgnoreKeyRepeat(1);
    glutSpecialUpFunc(MyGlutSpecialFunc);
    glutMainLoop();
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();

    return 0;
}

