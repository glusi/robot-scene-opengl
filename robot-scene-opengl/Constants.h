#pragma once

typedef enum {
	CAMERA_FRONT, CAMERA_BACK, CAMERA_RIGHT, CAMERA_LEFT, CAMERA_UP, CAMERA_DOWN
} USER_ACTION_CAMERA;

typedef enum {
	ROTATED_AROUND_X, ROTATED_AROUND_Y, ROTATED_AROUND_Z
}ROTATION_TYPE;

typedef enum {
	ROBOT_MOVE_FRONT, ROBOT_MOVE_BACK
}ROBOT_MOVE_DIRECTION;

typedef enum {
	ROBOT_SHOULDER, ROBOT_ELBOW, ROBOT_PALM
}ROBOT_JOINT;

typedef enum {
	ROBOT_HAND_UP, ROBOT_HAND_DOWN
}ROBOT_UP_DOWN_ACTION;

typedef enum {
	ROBOT_HEAD_UP, ROBOT_HEAD_DOWN, ROBOT_HEAD_RIGHT, ROBOT_HEAD_LEFT
}ROBOT_HEAD_MOVEMENT;

typedef enum {
	TEXTURE_FLOOR, TEXTURE_TABLE, TEXTURE_BACKGROUND, TEXTURE_TV
}TEXTURE_TYPE;

static const char* FLOOR_TEXTURE_PATH = "..//Assets//floor-tiles.jpg";
static const char* TABLE_TEXTURE_PATH = "..//Assets//wood.jpg";
static const char* BACKGROUND_TEXTURE_PATH = "..//Assets//background.jpg";
static const char* TV_TEXTURE_PATH = "..//Assets//tv_screen.jpg";

static const int NUM_OF_TEXTURES = 4;


