#pragma once

//Camera action type for movement
typedef enum {
	CAMERA_FRONT, CAMERA_BACK, CAMERA_RIGHT, CAMERA_LEFT, CAMERA_UP, CAMERA_DOWN
} USER_ACTION_CAMERA;

//Rotation types
typedef enum {
	ROTATED_AROUND_X, ROTATED_AROUND_Y, ROTATED_AROUND_Z
}ROTATION_TYPE;

//Robot move direction types
typedef enum {
	ROBOT_MOVE_FRONT, ROBOT_MOVE_BACK
}ROBOT_MOVE_DIRECTION;

//Robot joint types
typedef enum {
	ROBOT_SHOULDER, ROBOT_ELBOW, ROBOT_PALM
}ROBOT_JOINT;

//Robot arm movement types
typedef enum {
	ROBOT_HAND_UP, ROBOT_HAND_DOWN
}ROBOT_UP_DOWN_ACTION;

//Robot head movement types
typedef enum {
	ROBOT_HEAD_UP, ROBOT_HEAD_DOWN, ROBOT_HEAD_RIGHT, ROBOT_HEAD_LEFT, ROBOT_HEAD_UP_DOWN, ROBOT_HEAD_RIGHT_LEFT
}ROBOT_HEAD_MOVEMENT;

//Textures available in the project
typedef enum {
	TEXTURE_FLOOR, TEXTURE_TABLE, TEXTURE_TV, TEXTURE_WALL, TEXTURE_FABRIC, TEXTURE_WINDOW
}TEXTURE_TYPE;

//Light position moving on X, Y or Z
typedef enum {
    POINT_LIGHT_X, POINT_LIGHT_Y, POINT_LIGHT_Z
}POINT_LIGHT_POS;

//Camera movement left and right 
typedef enum {
    CAMERA_ROTATE, CAMERA_LIFT
}CAMERA_MOVE;

///Camera rotation left and right 
typedef enum {
    ROBOT_ROTATE_RIGHT, ROBOT_ROTATE_LEFT
}ROBOT_ROTATION;

/**
 * Paths to textures that are used in the project and located in the Assets folder
 */
static const char* FLOOR_TEXTURE_PATH = "..//Assets//floor-tiles.jpg";
static const char* TABLE_TEXTURE_PATH = "..//Assets//wood.jpg";
static const char* TV_TEXTURE_PATH = "..//Assets//tv_screen.jpg";
static const char* HELP_TEXTURE_PATH = "..//Assets//help.png";
static const char* WALL_TEXTURE_PATH = "..//Assets//wall.jpg";
static const char* FABRIC_TEXTURE_PATH = "..//Assets//fabric.jpg";
static const char* WINDOW_TEXTURE_PATH = "..//Assets//window.jpg";

//Number of texture types in the project
static const int NUM_OF_TEXTURES = 6;

//Cube vertices, used for building a textured cube
const static double cube[] =
{
    // x,   y,   z,  s,  t,
    +1.0,-1.0,-1.0,0.0,1.0,
    -1.0,-1.0,-1.0,1.0,1.0,
    -1.0,+1.0,-1.0,1.0,0.0,
    +1.0,+1.0,-1.0,0.0,0.0,

    -1.0,+1.0,-1.0,0.0,0.0,
    -1.0,-1.0,-1.0,0.0,1.0,
    -1.0,-1.0,+1.0,1.0,1.0,
    -1.0,+1.0,+1.0,1.0,0.0,

    -1.0,-1.0,+1.0,0.0,1.0,
    +1.0,-1.0,+1.0,1.0,1.0,
    +1.0,+1.0,+1.0,1.0,0.0,
    -1.0,+1.0,+1.0,0.0,0.0,

    +1.0,-1.0,-1.0,1.0,1.0,
    +1.0,+1.0,-1.0,1.0,0.0,
    +1.0,+1.0,+1.0,0.0,0.0,
    +1.0,-1.0,+1.0,0.0,1.0,

    +1.0,+1.0,-1.0,0.0,1.0,
    -1.0,+1.0,-1.0,1.0,1.0,
    -1.0,+1.0,+1.0,1.0,0.0,
    +1.0,+1.0,+1.0,0.0,0.0,

    +1.0,-1.0,+1.0,0.0,0.0,
    -1.0,-1.0,+1.0,1.0,0.0,
    -1.0,-1.0,-1.0,1.0,1.0,
    +1.0,-1.0,-1.0,0.0,1.0,
};
