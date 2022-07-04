#include "Camera.h"


void Camera::updateCamera() {
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z,
		center.x, center.y, center.z,
		upz.x, upz.y, upz.z);
}

Camera::Camera()
{
	eye = Vector3(5.0, 5.0, 5.0);
	center = Vector3();
	upz = Vector3(0.0, 1.0, 0.0);
	direction_foward = eye-center;
	direction_foward.y = 0;
	direction_foward.normalize();
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
			eye_change.update(direction_foward);
			break;
		case CAMERA_BACK: 
			eye_change.update(Vector3::zero()-direction_foward);
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
