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
	eye = Vector3(-2.0, 12.0, 6.0);
	center = Vector3(0, 2 ,0);
	upz = Vector3(0.0, 1.0, 0.0);

	direction_foward = eye-center;
	direction_foward.y = 0;
	direction_foward.normalize();

	angle_x = 0.0;
	angle_y = 0.0;

	eye_robot = Vector3(0,0,0);
	center_robot = Vector3(0,0,10);
	upz_robot = Vector3(0.0, 1.0, 0.0);

	direction_moving = center - eye;
	direction_moving.normalize();
	camera_angle_z = 33;
	camera_lift = 33;
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
	center += direction_moving;
}

void Camera::rotateCamera(float angle)
{
	float angle_dif = angle - camera_angle_z;
	double x1 = center.x - eye.x;
	double z1 = center.z - eye.z;

	double x2 = x1 * cos(angle_dif * (M_PI / 180)) - z1 * sin(angle_dif * (M_PI / 180));
	double z2 = x1 * sin(angle_dif * (M_PI / 180)) + z1 * cos(angle_dif * (M_PI / 180));

	center.x = x2 + eye.x;
	center.z = z2 + eye.z;

	camera_angle_z = angle;
	direction_moving = center - eye;
	direction_moving.normalize();
}

void Camera::liftCamera(float angle)
{
	float angle_dif = angle - camera_lift;
	float z1 = center.z - eye.z;
	float y1 = center.y - eye.y;

	float z2 = z1 * cos(angle_dif * (M_PI / 180)) - y1 * sin(angle_dif * (M_PI / 180));
	float y2 = z1 * sin(angle_dif * (M_PI / 180)) + y1 * cos(angle_dif * (M_PI / 180));

	center.z = z2 + eye.z;
	center.y = y2 + eye.y;
	camera_lift = angle;
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

float Camera::getCameraAngle()
{
	return camera_angle_z;
}

float Camera::getCameraLift()
{
	return camera_lift;
}


