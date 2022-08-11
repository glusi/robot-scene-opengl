#include "Menu.h"

Menu::Menu()
{
    ambient_color = new float[4];
    point_color = new float[4];
}

Menu::Menu(Scene* scene_new)
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

    rotate_camera_z = scene->getCameraAngle();
    lift_camera = scene->getCameraLift();
}

void Menu::moveRobotJoint(ROBOT_JOINT robot_joint, float lift, float rotation, const char* name) {
    //Move joint
    float lift_new = lift;
    ImGui::SliderFloat(Tools::concatStrings("Lift ", name).c_str(), &lift, -85.0f, 85.0f);
    //Update new  lift value
    if (lift_new != lift)
            scene->liftRobotHand(robot_joint, ROBOT_HAND_UP, -lift);

    //Rotate joint
    float rotation_new = rotation;
    ImGui::SliderFloat(Tools::concatStrings("Rotate ", name).c_str(), &rotation, -180.0f, 180.0f);
    //Update new rotation value
    if (rotation_new != rotation)
            scene->rotateRobotHand(robot_joint, -rotation);
}

void Menu::createMenu() {
    //Create menu with flags such as assuring fixed position and auto resize
    ImGui::Begin("Menu", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | 
        ImGuiWindowFlags_AlwaysUseWindowPadding | ImGuiWindowFlags_MenuBar);
    //Get at start of every frame the values of the modifiable fields and could be changed
    getInitialValues();
    //Add menu bar with Welcome message
    ImGui::BeginMenuBar();
    ImGui::Text("Welcome to my Robot OpenGl Simulation!");
    ImGui::EndMenuBar();
    //Create main control menus
    lightMenu();   
    robotMenu();
    cameraMenu();
    //Add 'Exit' and 'Help' buttons and place then in middle of the line in the menu
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
    ImGui::End();
    //Help Window
    helpMenu();
}

void Menu::helpMenu() {
    //Variable for 'x' button on popup window
    static bool x_pressable = true;
    //If 'help' was pressed show window
    if (help_window_open) {
        ImGui::OpenPopup("help", ImGuiWindowFlags_AlwaysAutoResize);
        //Add 'x' option on popup window
        ImGui::BeginPopupModal("help", &x_pressable, 0);
        if (!next_pressed) {
            ImGui::Text("You can move the robot and camera by Keyboard:");
            if (x_pressable) {
                //Make the help image auto re-sizable according to simulation window size
                float aspect = scene->getHelpImageHeight() / scene->getHelpImageWidth();
                float width = scene->getWidth() / scene->getHelpImageWidth();
                //Draw the image with keyboard controls
                ImGui::Image((void*)(intptr_t)scene->getgetHelpImageTexture(), ImVec2(width * 700.0, aspect * width * 700.0));
                //Add in middle of line a 'next' button
                ImGuiStyle& style = ImGui::GetStyle();
                width = ImGui::CalcTextSize("next").x;
                Tools::AlignForWidth(width);
                if (ImGui::Button("next"))
                    next_pressed = true;
                ImGui::EndPopup();
            }
            else {
                help_window_open = false;
                x_pressable = true;
            }
        }
        else {
            //If 'next' was clicked show second page of help explaining the Menu controls
            if (x_pressable) {
                ImGui::Text("You can also control everything from the menu.");
                ImGui::Text("The menu is located in right top corner.");
                ImGui::NewLine();
                ImGui::Indent();
                //Lights sections
                ImGui::Text("Lights");
                ImGui::Text("In this section you can:");
                ImGui::BulletText("Enable / Disable ambient light");
                ImGui::BulletText("Choose color for ambient light");
                ImGui::BulletText("Enable / Disable point light");
                ImGui::BulletText("Choose color for point light");
                ImGui::BulletText("Move point light on X, Y and Z");
                //Robot section
                ImGui::NewLine();
                ImGui::Text("Robot");
                ImGui::Text("In this section you can:");
                ImGui::BulletText("Move robot forward and backwards");
                ImGui::BulletText("Rotate robot around itself right and left");
                ImGui::BulletText("Rotate and lift robot head");
                ImGui::BulletText("Rotate and lift robot shoulder");
                ImGui::BulletText("Rotate and lift robot elbow");
                ImGui::BulletText("Rotate and lift robot palm");
                //Camera section
                ImGui::NewLine();
                ImGui::Text("Camera");
                ImGui::Text("In this section you can:");
                ImGui::BulletText("Change the camera to robot eyes and back to external camera");
                ImGui::Indent();
                ImGui::Text("The current mode can be seen in the right top corner.");
                ImGui::Unindent();
                ImGui::BulletText("Move camera on X, Y and Z");
                ImGui::BulletText("Rotate camera around itself");
                ImGui::BulletText("Lift camera up and down");
                //Buttons sections
                ImGui::NewLine();
                ImGui::Text("Pressing 'exit' will close the simulation");
                ImGui::Text("Pressing 'help' will open this help window");
                ImGui::EndPopup();
            }
            else {
                help_window_open = false;
                x_pressable = true;
            }
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
        ImGui::Checkbox("Enable ambient light", &ambient_enabled);
        scene->disableAmbient(ambient_enabled);
        ImGui::ColorEdit3("Ambient color", ambient_color);
        //Update ambient light new values
        if (ambient_enabled)
            scene->adjustAmbientLight(ambient_color);
        ImGui::Text("Adjust point light");
        ImGui::Checkbox("Enable point light", &point_enabled);
        scene->disablePoint(point_enabled);
        ImGui::InputFloat("Position X", &point_light_position.x, 1.0f);
        ImGui::InputFloat("Position Y", &point_light_position.y, 1.0f);
        ImGui::InputFloat("Position Z", &point_light_position.z, 1.0f);       
        ImGui::ColorEdit3("Point light color", point_color);
        //Update point light new values
        if (point_enabled) {
            scene->applyPointLightPos(point_light_position);
            scene->adjustPointLight(point_color);
        }
    }
}

void Menu::robotMenu()
{
    if (ImGui::CollapsingHeader("Robot")) {

        //Move robot
        float rotate_robot_new = rotate_robot, move_robot_foward_back_new = move_robot_foward_back;
        ImGui::InputFloat("Move robot", &move_robot_foward_back, 1.0f);
        ImGui::SliderFloat("Rotate robot", &rotate_robot, -360.0f, 360.0f);
        //Update robot movement new values
        if (move_robot_foward_back_new != move_robot_foward_back)
            scene->moveRobot(ROBOT_MOVE_FRONT, move_robot_foward_back);
        if (rotate_robot_new != rotate_robot)
            scene->rotateRobot(rotate_robot);

        //robot head
        ImGui::Text("Robot head");
        float rotate_head_right_left_new = rotate_head_right_left;
        ImGui::SliderFloat("Rotate head right", &rotate_head_right_left, -360.0f, 360.0f);
        //Rotate head right and left
        if (rotate_head_right_left_new != rotate_head_right_left)
            scene->moveRobotHead(ROBOT_HEAD_RIGHT_LEFT, rotate_head_right_left);

        float rotate_head_up_down_new = rotate_head_up_down;
        ImGui::SliderFloat("Lift head up down", &rotate_head_up_down, -60.0f, 200.0f);
        //Rotate head up and down
        if (rotate_head_up_down_new != rotate_head_up_down)
            scene->moveRobotHead(ROBOT_HEAD_UP_DOWN, rotate_head_up_down);

        //Robot hand
        ImGui::Text("Robot hand");
        //Menus for different joints
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

        //Rotate camera around z
        float rotate_camera_z_new = rotate_camera_z;
        ImGui::SliderFloat("Rotate camera around z", &rotate_camera_z, -360.0f, 360.0f);
        if (rotate_camera_z != rotate_camera_z_new)
            scene->rotateCamera(CAMERA_ROTATE ,rotate_camera_z);

        //Rotate camera around z
        float lift_camera_new = lift_camera;
        ImGui::SliderFloat("Lift camera up down", &lift_camera, -360.0f, 360.0f);
        if (lift_camera_new != lift_camera)
            scene->rotateCamera(CAMERA_LIFT, lift_camera);
    }
}
