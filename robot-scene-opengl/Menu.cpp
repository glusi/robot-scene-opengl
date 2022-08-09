#include "Menu.h"

Menu::Menu()
{
    ambient_color = new float[4];
    point_color = new float[4];
}

Menu::Menu(InitialScene* scene_new)
{
    ambient_color = new float[4];
    point_color = new float[4];
    scene = scene_new;
}

void Menu::getInitialValues() {
    rotate_head_right_left = scene->getHeadRotation();
    rotate_head_up_down = scene->getHeadLift();
    rotate_camera_right_left = scene->getCameraPosition().x;
    rotate_camera_up_down = scene->getCameraPosition().y;
    rotate_camera_front_back = scene->getCameraPosition().z;

    Tools::copyColor(&ambient_color, scene->getAmbientColor());

    move_robot_foward_back = scene->getRobotPosition();
    rotate_robot = scene->getRobotRotation();
    // move_robot_foward_back = scene->getRobotPosition();

    move_shoulder = scene->getShoulderLift();
    rotate_shoulder = scene->getShoulderRotation();
    move_elbow = scene->getElbowLift();
    rotate_elbow = scene->getElbowRotation();;
    move_palm = scene->getPalmLift();
    rotate_palm = scene->getPalmRotation();

    point_light_position.x = scene->getPointLightPosition(POINT_LIGHT_X);
    point_light_position.y = scene->getPointLightPosition(POINT_LIGHT_Y);
    point_light_position.z = scene->getPointLightPosition(POINT_LIGHT_Z);
    Tools::copyColor(&point_color, scene->getPointLightColor());
}

void Menu::moveRobotJoint(ROBOT_JOINT robot_joint, float lift, float rotation, const char* name) {
    //Move shoulder
    float lift_new = lift;
    ImGui::SliderFloat(Tools::concatStrings("Move ", name).c_str(), &lift, -90.0f, 90.0f);
    if (lift_new != lift)
        if (lift > 0)
            scene->liftRobotHand(robot_joint, ROBOT_HAND_UP, lift);
        else
            scene->liftRobotHand(robot_joint, ROBOT_HAND_DOWN, -lift);

    //Rotate shoulder
    float rotation_new = rotation;
    ImGui::SliderFloat(Tools::concatStrings("Rotate ", name).c_str(), &rotation, -180.0f, 180.0f);
    if (rotation_new != rotation)
        if (move_shoulder > 0)
            scene->rotateRobotHand(robot_joint, rotation);
        else
            scene->rotateRobotHand(robot_joint, rotation);
}

void Menu::MyHelpFunction()
{
}

void Menu::createMenu() {
    ImGui::Begin("Menu", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | 
        ImGuiWindowFlags_AlwaysUseWindowPadding | ImGuiWindowFlags_MenuBar);
    getInitialValues();

    ImGui::BeginMenuBar();
    ImGui::Text("Welcome to my Robot OpenGl Simulation!");
    ImGui::EndMenuBar();

    lightMenu();   
    robotMenu();
    cameraMenu();

    ImGuiStyle& style = ImGui::GetStyle();
    float width = 0.0f;
    width += ImGui::CalcTextSize("Help").x;
    width += style.ItemSpacing.x;
    width += ImGui::CalcTextSize("Exit").x;
    Tools::AlignForWidth(width);

    if (ImGui::Button("Help"))
        helpFunc();
    ImGui::SameLine();
    if (ImGui::Button("Exit"))
        exit(0);

    /*if (Tools::ButtonCenteredOnLine("Help", 0.5))
        MyHelpFunction();
    ImGui::SameLine();
    if (ImGui::Button("Exit"))
        exit(0);*/

    // }
         //ImGui::SetNextWindowPos();
    ImGui::End();
    static bool x_pressable = true;
    if (help_window_open) {
        ImGui::OpenPopup("help");
        
        ImGui::BeginPopupModal("help", &x_pressable, 0);
        if (x_pressable) {
            float aspect = scene->getHelpImageHeight() / scene->getHelpImageWidth();
            float width = scene->getWidth() / scene->getHelpImageWidth() ;
            ImGui::Image((void*)(intptr_t)scene->getgetHelpImageTexture(), ImVec2(width * 300.0 , aspect * width * 300.0 ));
            ImGui::EndPopup();
        }
        else {
            help_window_open = false;
            x_pressable = true;
        }
    }
}

void Menu::helpFunc() {
    help_window_open = true;    
}

void Menu::lightMenu()
{
    if (ImGui::CollapsingHeader("Lights")) {
        ImGui::Text("Adjust ambient Light");
        ImGui::ColorEdit4("Ambient color", ambient_color);
        scene->adjustAmbientLight(ambient_color);
        ImGui::Text("Adjust point light");
        ImGui::InputFloat("Position X", &point_light_position.x, 1.0f);
        ImGui::InputFloat("Position Y", &point_light_position.y, 1.0f);
        ImGui::InputFloat("Position Z", &point_light_position.z, 1.0f);
        scene->applyPointLightPos(point_light_position);
        ImGui::ColorEdit4("Point light color", point_color);
        scene->adjustPointLight(point_color);
    }
}

void Menu::robotMenu()
{
    if (ImGui::CollapsingHeader("Robot")) {

        //Move robot
        float rotate_robot_new = rotate_robot, move_robot_foward_back_new = move_robot_foward_back;
        ImGui::InputFloat("Move robot", &move_robot_foward_back, 1.0f);
        ImGui::SliderFloat("Rotate robot", &rotate_robot, 0.0f, 360.0f);
        if (move_robot_foward_back_new != move_robot_foward_back)
            scene->moveRobot(ROBOT_MOVE_FRONT, move_robot_foward_back);
        if (rotate_robot_new != rotate_robot)
            scene->rotateRobot(rotate_robot);

        ImGui::Text("Robot head");
        float rotate_head_right_left_new = rotate_head_right_left;
        ImGui::SliderFloat("Rotate head right", &rotate_head_right_left, -360.0f, 360.0f);
        //Rotate head right and left
        if (rotate_head_right_left_new != rotate_head_right_left)
            //   if (rotate_head_right_left > 0)
            scene->moveRobotHead(ROBOT_HEAD_RIGHT_LEFT, rotate_head_right_left);
        // else
          //   scene->moveRobotHead(ROBOT_HEAD_LEFT, rotate_head_right_left);

        float rotate_head_up_down_new = rotate_head_up_down;
        ImGui::SliderFloat("Lift head up down", &rotate_head_up_down, -60.0f, 200.0f);
        //Rotate head up and down
        if (rotate_head_up_down_new != rotate_head_up_down)
            scene->moveRobotHead(ROBOT_HEAD_UP_DOWN, rotate_head_up_down);

        ImGui::Text("Robot hand");
        moveRobotJoint(ROBOT_SHOULDER, move_shoulder, rotate_shoulder, "Shoulder");
        moveRobotJoint(ROBOT_ELBOW, move_elbow, rotate_elbow, "Elbow");
        moveRobotJoint(ROBOT_PALM, move_palm, rotate_palm, "Palm");
    }
}

void Menu::cameraMenu()
{
    if (ImGui::CollapsingHeader("Camera")) {

        ImGui::RadioButton("external view", &isFirstPerson, 0); ImGui::SameLine();
        ImGui::RadioButton("robot view", &isFirstPerson, 1);
        scene->setIFirstPerson(isFirstPerson);

        //Move camera right and left
        float rotate_camera_right_left_new = rotate_camera_right_left;
        ImGui::InputFloat("Move camera right and left", &rotate_camera_right_left, 1.0f);
        if (rotate_camera_right_left != rotate_camera_right_left_new)
            if (rotate_camera_right_left > 0)
                scene->moveCamera(CAMERA_RIGHT, rotate_camera_right_left);
            else
                scene->moveCamera(CAMERA_LEFT, -rotate_camera_right_left);

        //Move camera up and down
        float rotate_camera_up_down_new = rotate_camera_up_down;
        ImGui::InputFloat("Move camera up and down", &rotate_camera_up_down, 1.0f);
        if (rotate_camera_up_down != rotate_camera_up_down_new)
            if (rotate_camera_up_down > 0)
                scene->moveCamera(CAMERA_UP, rotate_camera_up_down);
            else
                scene->moveCamera(CAMERA_DOWN, -rotate_camera_up_down);

        //Move camera front and back
        float rotate_camera_front_back_new = rotate_camera_front_back;
        ImGui::InputFloat("Move camera front and back", &rotate_camera_front_back, 1.0f);
        if (rotate_camera_front_back != rotate_camera_front_back_new)
            if (rotate_camera_front_back > 0)
                scene->moveCamera(CAMERA_FRONT, rotate_camera_front_back);
            else
                scene->moveCamera(CAMERA_BACK, -rotate_camera_front_back);
    }
}
