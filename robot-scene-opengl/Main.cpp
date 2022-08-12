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
//Scene Object
Scene* scene;
//Menu object
Menu menu;
//Menu show flag
static bool show_menu = true;
//Aspect of the window
float aspect = 1;
//Camera mode -First person or external camera
bool is_ff = false;

/**
 * The display function that is called every frame.
 * 
 */
void display() {
    //Clears
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    //imgui new frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGLUT_NewFrame();

    //Create the menu
    menu.createMenu();
    ImGui::Render();
    ImGuiIO& io = ImGui::GetIO();

    //Set projection and model view
    glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, io.DisplaySize.x / io.DisplaySize.y, 1.0, 150.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Draw the scene
    scene->draw();

    //Imgui render
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    //Clean
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
    
}

/**
 * Binds keyboard keys to different actions.
 * 
 * \param Key
 * \param x
 * \param y
 */
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
        //Arm
        case 'y': scene->liftRobotHand(ROBOT_SHOULDER, ROBOT_HAND_UP); break;
        case 'h': scene->liftRobotHand(ROBOT_SHOULDER, ROBOT_HAND_DOWN); break;
        case 'n': scene->rotateRobotHand(ROBOT_SHOULDER); break;
        case 'u': scene->liftRobotHand(ROBOT_ELBOW, ROBOT_HAND_UP); break;
        case 'j': scene->liftRobotHand(ROBOT_ELBOW, ROBOT_HAND_DOWN); break;
        case 'm': scene->rotateRobotHand(ROBOT_ELBOW); break;
        case 'i': scene->liftRobotHand(ROBOT_PALM, ROBOT_HAND_UP); break;
        case 'k': scene->liftRobotHand(ROBOT_PALM, ROBOT_HAND_DOWN); break;
        case ',': scene->rotateRobotHand(ROBOT_PALM); break;
        //Head
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

/**
 * The Initialize function, called once.
 * 
 */
void Init() {
    //Flags for Opengl to render the 3d simulation
    glEnable(GL_NORMALIZE);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);                            // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);               // Black Background
    glClearDepth(1.0f);                                 // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);                            // Depth Buffer Setup                       // Enables Depth Testing
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Really Nice Perspective Calculations
    glEnable(GL_LIGHTING);
    //Initialize objects
    scene = new Scene();
    menu = Menu(scene);
}

/**
 * idle callback for opengl window. Calls redisplay to keep window functional.
 * 
 */
void idleFucn() {
    display();
}

/**
 * reshaping window size callback for opengl window. Reshapes the window using ImGui function,
 * calculates new values for aspect and window sizes, and creates the new Viewport.
 * 
 * \param w
 * \param h
 */
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

/**
 * The main function of the project.
 * 
 * \param argc
 * \param argv
 * \return 
 */
int main(int argc, char** argv)
{
    //Init Glut
    glutInit(&argc, argv);
    //Set Glut options
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE | GLUT_STENCIL);
    //Set initial parameters for the window and create it
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutCreateWindow("robot-scene");
    //Init
    Init();
    //Set callbacks
    glutIdleFunc(idleFucn);
    glutDisplayFunc(display);
    //Init ImGui
    initImgui();
    //Set callbacks
    glutReshapeFunc(reshapeFunc);
    glutKeyboardFunc(MyKeyboardFunc);
    glutMainLoop();
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();

    return 0;
}

