#include "Camera.h"

/*
function updates the LookAt direction according to eye, center, upz Vectors 
(Or in first person eye_robot,center_robot and upz_robot).
*/
void Camera::updateCamera() {
	glLoadIdentity();
	if(is_first_person)
		gluLookAt(eye_robot.x, eye_robot.y, eye_robot.z,
			center_robot.x, center_robot.y, center_robot.z,
			upz_robot.x, upz_robot.y, upz_robot.z);
	else
		gluLookAt(eye.x, eye.y, eye.z,
			center.x, center.y, center.z,
			upz.x, upz.y, upz.z);
}

/*
Constructs a Camera object, initializing all its fields
*/
Camera::Camera()
{
	eye = Vector3(-2.0, 12.0, 6.0);
	center = Vector3(0, 2 ,0);
	upz = Vector3(0.0, 1.0, 0.0);

	direction_foward = eye-center;
	direction_foward.y = 0;
	direction_foward.normalize();

	eye_robot = Vector3(0,0,0);
	center_robot = Vector3(0,0,10);
	upz_robot = Vector3(0.0, 1.0, 0.0);

	direction_moving = center - eye;
	direction_moving.normalize();
	camera_angle_z = 33;
	camera_lift = 33;
}

/*
Draws the camera - updates the scene with new camera values
*/
void Camera::draw()
{
	glMatrixMode(GL_MODELVIEW);
	updateCamera();
}

/*
moves the camera by one, according to the parameter:
- USER_ACTION_CAMERA action - type of camera movement to apply to
Used for keyboard inputs to move camera.
*/
void Camera::moveCamera(USER_ACTION_CAMERA action)
{
	Vector3 eye_change = Vector3();
	switch (action) {
		case CAMERA_FRONT: 
			eye += Vector3(0, 0, -1);
			break;
		case CAMERA_BACK: 
			eye += Vector3(0, 0, 1);
			break;
		case CAMERA_RIGHT:
			eye += Vector3(-1, 0, 0);
			break;
		case CAMERA_LEFT: 
			eye += Vector3(1, 0, 0);
			break;
		case CAMERA_UP: 
			eye += Vector3(0, -1, 0);
			break;
		case CAMERA_DOWN: 
			eye += Vector3(0, 1, 0);
			break;
		default: break;
	}
	center += direction_moving;
}

/*
moves the camera by <amount>, according to the parameter:
- USER_ACTION_CAMERA action - type of camera movement to apply to
- amount - how much the camera should move
Used for values from the slider in the menu which move camera.
*/
void Camera::moveCamera(USER_ACTION_CAMERA action, float amount)
{
	Vector3 eye_change = Vector3();
	switch (action) {
	case CAMERA_FRONT:
		eye = Vector3(eye.x, eye.y, 0) + (Vector3(0, 0, 1) * amount);
		
		break;
	case CAMERA_BACK:
		eye = Vector3(eye.x, eye.y, 0) + (Vector3(0, 0, 1) * (-amount));
		break;
	case CAMERA_RIGHT:
		eye = Vector3(0, eye.y, eye.z) + (Vector3(1,0,0)* amount);
		break;
	case CAMERA_LEFT:
		eye = Vector3(0, eye.y, eye.z) + (Vector3(1, 0, 0) * (-amount));
		break;
	case CAMERA_UP: 
		eye = Vector3(eye.x, 0, eye.z) + (Vector3(0, 1, 0) * amount);
		break;
	case CAMERA_DOWN:
		eye = Vector3(eye.x, 0, eye.z) + (Vector3(0, 1, 0) * (-amount));
		break;
	default: break;
	}
	center += direction_moving;
}

/*
Rotates the camera by one.
Used for keyboards inputs that rotate camera.
*/
void Camera::rotateCamera()
{
	//Translate to eye
	double x1 = center.x - eye.x;
	double z1 = center.z - eye.z;
	//Calculate new rotated center point
	double x2 = x1 * cos((M_PI / 180)) - z1 * sin((M_PI / 180));
	double z2 = x1 * sin((M_PI / 180)) + z1 * cos((M_PI / 180));
	//Translate back
	center.x = x2 + eye.x;
	center.z = z2 + eye.z;
	//Update relevant fields
	camera_angle_z ++;
	direction_moving = center - eye;
	direction_moving.normalize();
}

/*
Rotates the camera by <angle>:
- float angle - the angle to rotate the camera by.
Used for values from the slider in the menu which rotate camera.
*/
void Camera::rotateCamera(float angle)
{
	//Calculate new angle to move by
	float angle_dif = angle - camera_angle_z;
	//Translate to eye
	double x1 = center.x - eye.x;
	double z1 = center.z - eye.z;
	//Calculate new rotated center point
	double x2 = x1 * cos(angle_dif * (M_PI / 180)) - z1 * sin(angle_dif * (M_PI / 180));
	double z2 = x1 * sin(angle_dif * (M_PI / 180)) + z1 * cos(angle_dif * (M_PI / 180));
	//Translate back
	center.x = x2 + eye.x;
	center.z = z2 + eye.z;
	//Update relevant fields
	camera_angle_z = angle;
	direction_moving = center - eye;
	direction_moving.normalize();
}

/*
Lifts the camera by one.
Used for keyboards inputs that lift camera.
*/
void Camera::liftCamera()
{
	//Translate to eye
	float z1 = center.z - eye.z;
	float y1 = center.y - eye.y;
	//Calculate new rotated center point
	float z2 = z1 * cos((M_PI / 180)) - y1 * sin((M_PI / 180));
	float y2 = z1 * sin((M_PI / 180)) + y1 * cos((M_PI / 180));
	//Translate back
	center.z = z2 + eye.z;
	center.y = y2 + eye.y;
	//Update relevant fields
	camera_lift++;
}

/*
Lifts the camera by <angle>:
- float angle - the angle to lift the camera by.
Used for values from the slider in the menu which lift camera.
*/
void Camera::liftCamera(float angle)
{
	//Calculate new angle to move by
	float angle_dif = angle - camera_lift;
	//Translate to eye
	float z1 = center.z - eye.z;
	float y1 = center.y - eye.y;
	//Calculate new rotated center point
	float z2 = z1 * cos(angle_dif * (M_PI / 180)) - y1 * sin(angle_dif * (M_PI / 180));
	float y2 = z1 * sin(angle_dif * (M_PI / 180)) + y1 * cos(angle_dif * (M_PI / 180));
	//Translate back
	center.z = z2 + eye.z;
	center.y = y2 + eye.y;
	//Update relevant fields
	camera_lift = angle;
}

/*
setter for is_first_person_int
*/
void Camera::setIFirstPerson(int is_first_person_int)
{
	is_first_person = (is_first_person_int == 1) ? true : false;
}

/*
getter for is_first_person_int 
*/
bool Camera::getIFirstPerson()
{
	return is_first_person;
}

/*
getter for camera's eye
*/
Vector3 Camera::getCameraPosition()
{
	return eye;
}

/*
getter for camera's angle around z
*/
float Camera::getCameraAngle()
{
	return camera_angle_z;
}

/*
getter for camera's lift
*/
float Camera::getCameraLift()
{
	return camera_lift;
}


