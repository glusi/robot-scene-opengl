#include "Menu.h"

Menu::Menu()
{
    ambient_color = new float[4];
}

Menu::Menu(InitialScene* scene_new)
{
    ambient_color = new float[4];
    scene = scene_new;
}

void Menu::getInitialValues() {
    //rotate_head_right_left = scene->getHeadPosition().x;
    //rotate_head_up_down = scene->getHeadPosition().;
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
}

void Menu::moveRobotJoint(ROBOT_JOINT robot_joint, float lift, float rotation, const char* name) {
    //Move shoulder
    float lift_new = lift;
    ImGui::SliderFloat(Tools::concatStrings("Move ", name).c_str(), &lift, -90.0f, 90.0f);
    if (lift_new != lift)
        if (lift > 0)
            scene->liftRobotHand(robot_joint, ROBOT_HAND_UP);
        else
            scene->liftRobotHand(robot_joint, ROBOT_HAND_DOWN);

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
    ImGui::Begin("Menu");
    getInitialValues();

    float try1;
    ImGui::SliderFloat("Adjust ambient", &try1, 0.0f, 3.0f);
    //ImGui::TreePop();
    int t;
    // ImGui::RadioButton("external view", &t, 0); ImGui::SameLine();

    /*if (ImGui::TreeNode("tv")) {
            }       */

    //Adjust ambient color
    ImGui::ColorEdit4("Ambient color", ambient_color);
    scene->adjustAmbientLight(ambient_color);
   
    if (ImGui::CollapsingHeader("Robot")) {

        //Move robot
        float rotate_robot_new = rotate_robot, move_robot_foward_back_new = move_robot_foward_back;
        ImGui::SliderFloat("Move robot", &move_robot_foward_back, -180.0f, 180.0f);
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
            if (rotate_head_right_left > 0)
                scene->moveRobotHead(ROBOT_HEAD_RIGHT, rotate_head_right_left);
            else
                scene->moveRobotHead(ROBOT_HEAD_LEFT, rotate_head_right_left);

        float rotate_head_up_down_new = rotate_head_up_down;
        ImGui::SliderFloat("Rotate head up down", &rotate_head_up_down, -180.0f, 180.0f);
        //Rotate head up and down
        if (rotate_head_up_down_new != rotate_head_up_down)
            if (rotate_head_up_down >= 0)
                scene->moveRobotHead(ROBOT_HEAD_UP, -rotate_head_up_down);
            else
                scene->moveRobotHead(ROBOT_HEAD_DOWN, -rotate_head_up_down);

        ImGui::Text("Robot hand");
        moveRobotJoint(ROBOT_SHOULDER, move_shoulder, rotate_shoulder, "Shoulder");
        moveRobotJoint(ROBOT_ELBOW, move_elbow, rotate_elbow, "Elbow");
        moveRobotJoint(ROBOT_PALM, move_palm, rotate_palm, "Palm");
    }
    if (ImGui::CollapsingHeader("Camera")) {

        ImGui::RadioButton("external view", &isFirstPerson, 0); ImGui::SameLine();
        ImGui::RadioButton("robot view", &isFirstPerson, 1);
        scene->setIFirstPerson(isFirstPerson);

        //Move camera right and left
        float rotate_camera_right_left_new = rotate_camera_right_left;
        ImGui::SliderFloat("Move camera right and left", &rotate_camera_right_left, -100.0f, 100.0f);
        if (rotate_camera_right_left != rotate_camera_right_left_new)
            if (rotate_camera_right_left > 0)
                scene->moveCamera(CAMERA_RIGHT, rotate_camera_right_left);
            else
                scene->moveCamera(CAMERA_LEFT, -rotate_camera_right_left);

        //Move camera up and down
        float rotate_camera_up_down_new = rotate_camera_up_down;
        ImGui::SliderFloat("Move camera up and down", &rotate_camera_up_down, -100.0f, 100.0f);
        if (rotate_camera_up_down != rotate_camera_up_down_new)
            if (rotate_camera_up_down > 0)
                scene->moveCamera(CAMERA_UP, rotate_camera_up_down);
            else
                scene->moveCamera(CAMERA_DOWN, -rotate_camera_up_down);

        //Move camera front and back
        float rotate_camera_front_back_new = rotate_camera_front_back;
        ImGui::SliderFloat("Move camera front and back", &rotate_camera_front_back, -100.0f, 100.0f);
        if (rotate_camera_front_back != rotate_camera_front_back)
            if (rotate_camera_front_back > 0)
                scene->moveCamera(CAMERA_FRONT, rotate_camera_front_back);
            else
                scene->moveCamera(CAMERA_BACK, -rotate_camera_front_back);
    }

    ImGuiStyle& style = ImGui::GetStyle();
    float width = 0.0f;
    width += ImGui::CalcTextSize("Hello").x;
    width += style.ItemSpacing.x;
    width += ImGui::CalcTextSize("World!").x;
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
            ImGui::Text("nana");
            GLvoid* pixels;
            glGetTexImage(scene->getTextureId(TEXTURE_TV), scene->getTextureId(TEXTURE_TV), scene->getTextureId(TEXTURE_TV), scene->getTextureId(TEXTURE_TV), &pixels);
            ImGui::Image(pixels, ImVec2(120, 120));
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