#include "Camera.h"


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

Camera::Camera()
{
	eye = Vector3(-4.0, 10.0, 8.0);
	center = Vector3();
	upz = Vector3(0.0, 1.0, 0.0);

	direction_foward = eye-center;
	direction_foward.y = 0;
	direction_foward.normalize();

	angle_x = 0.0;
	angle_y = 0.0;

	eye_robot = Vector3(0,5,0);
	center_robot = Vector3(0,5,10);
	upz_robot = Vector3(0.0, 1.0, 0.0);
}

void Camera::draw()
{
	glMatrixMode(GL_MODELVIEW);
	updateCamera();
}

void Camera::moveCamera(USER_ACTION_CAMERA action)
{
	Vector3 eye_change = Vector3();
	switch (action) {
		case CAMERA_FRONT: 
			eye_change.update(Vector3::zeroVector() - direction_foward);
			break;
		case CAMERA_BACK: 
			eye_change.update(direction_foward);
			break;
		case CAMERA_RIGHT: 
			break;
		case CAMERA_LEFT: 
			break;
		case CAMERA_UP: break;
		case CAMERA_DOWN: break;
		default: break;
	}
	eye -= eye_change;
	center -= eye_change;
}

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
}

void Camera::rotateCamera(int xoffset, int yoffset)
{
	
}

void Camera::setIFirstPerson(int is_first_person_int)
{
	is_first_person = (is_first_person_int == 1) ? true : false;
}

bool Camera::getIFirstPerson()
{
	return is_first_person;
}

void Camera::setFirstPersonCamera(Vector3 translate_position)
{
	translate_position_camera_robot += translate_position;
}

Vector3 Camera::getCameraPosition()
{
	return eye;
}



