#include "Camera.h"


void Camera::updateCamera() {
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z,
		center.x, center.y, center.z,
		upz.x, upz.y, upz.z);
}

Camera::Camera()
{
	eye = Vector3(-4.0, 7.0, 8.0);
	center = Vector3();
	upz = Vector3(0.0, 1.0, 0.0);

	direction_foward = eye-center;
	direction_foward.y = 0;
	direction_foward.normalize();

	angle_x = 0.0;
	angle_y = 0.0;
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

void Camera::rotateCamera(int xoffset, int yoffset)
{
	
}
