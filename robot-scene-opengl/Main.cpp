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
InitialScene scene;
Menu menu;

bool first_time_right_mouse = true;
float xlast_mouse =0.0, ylast_mouse =0.0;

std::list<Button> buttons;

static bool show_menu = true;
float aspect = 1;

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

    scene.draw();
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
    GLint viewport[4];
    GLdouble mvmatrix[16], projmatrix[16];
    GLint realy; /* OpenGL y coordinate position */
    GLdouble wx, wy, wz; /* returned world x, y, z coords */
    glGetIntegerv(GL_VIEWPORT, viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
    /* note viewport[3] is height of window in pixels */
    realy = viewport[3] - (GLint)ypos - 1;
    gluUnProject((GLdouble)xpos, (GLdouble)realy, 0.0, mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
    printf("World coords at z = 0.0 are(% f, % f, % f)\n", wx, wy, wz);


    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        for (Button button : buttons) {
            //Check if the click was inside the 'exit' button
            if (wx >= button.position.x && wx <= button.position.x+button.width && wy >= button.position.y && wy <= button.position.y+button.length)
            {
               cout<<"clicked "+ button.name<<endl;
               button.function();
            }
        }
    }
}

void exitFunc() {
    exit(0);
}

void helpFunc() {
    if (!ImGui::Begin("My Window Name"))
    {
        ImGui::End();
    }
    else
    {
        ImGui::Text("your content here");
        ImGui::End();
    }
}

std::list<Button> makeButtons() {
    list<Button> res = *(new list<Button>());
    res.push_back(Button(Vector3(-85, -80, 0), 10.0, 11.0, "exit", exitFunc));
    res.push_back(Button(Vector3(-85, 20, 0), 10.0, 13.0, "help", helpFunc));
    res.push_back(Button(Vector3(-95, -50, 0), 20.0, 13.0, "Adjust ambient light", helpFunc));
    return res;
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
   // glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
   // glFrontFace(GL_CCW);
   // glCullFace(GL_BACK);
   // glEnable(GL_CULL_FACE);
    buttons = makeButtons();
    scene = InitialScene(buttons);
    menu = Menu(&scene);
    

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
    scene.setWidth(w);
    scene.setHeight(h);
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
    //glutReshapeFunc(windowResize);
    glutKeyboardFunc(MyKeyboardFunc);
    glutSpecialUpFunc(MyGlutSpecialFunc);
    
    /*glutMouseFunc(MyMouseFunc);
    */
    glutMainLoop();
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();

    return 0;
}

