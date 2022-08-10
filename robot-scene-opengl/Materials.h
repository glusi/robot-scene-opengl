#pragma once
#include <GL/glut.h>

/**
 * This file contains different materials values constructed in material struct
 */

typedef struct materialStruct {
	GLfloat Ka[4]; //Ka -ambient
	GLfloat Kd[4]; // Kd - diffusion
	GLfloat Ks[4]; //Ks - specular
	GLfloat n;
} materialStruct;


static const materialStruct material1{
		{0.33, 0.22, 0.03, 0.5}, // Ka
		{0.78, 0.57, 0.11, 0.5}, // Kd
		{0.99, 0.91, 0.81, 0.5}, // Ks
		27.8 // n
};
static const materialStruct materialTV{
	{1.0, 1.0, 1.0, 1.0}, // Ka
	{1.0, 1.0, 1.0, 1.0}, // Kd
	{1.0, 1.0, 1.0, 1.0}, // Ks
	5 // n
};
static const materialStruct robot_eye_material{
{0.0, 1.0, 1.0, 1.0}, // Ka
{0.0, 1.0, 1.0, 1.0}, // Kd
{0.0, 1.0, 1.0, 1.0}, // Ks
2 // n
};

static const materialStruct glass{
	{0.1f,0.19f,0.17f,0.8f}, // Ka
	{0.4f,0.74f,0.69f,0.8f}, // Kd
	{0.3f,0.31f,0.31f,0.8f}, // Ks
	12.8 // n
};
static const materialStruct polished_copper{
	{0.2295f, 0.08825f, 0.0275f, 1.0f}, // Ka
	{0.5508f, 0.2118f, 0.066f, 1.0f}, // Kd
	{0.580594f, 0.223257f, 0.0695701f, 1.0f}, // Ks
	51.2f // n
};
static const materialStruct silver{
	{0.19, 0.19, 0.19, 1.0f}, // Ka
	{0.51, 0.51, 0.51, 1.0f}, // Kd
	{0.51, 0.51, 0.51, 1.0f}, // Ks
	51.2 // n
};

static const materialStruct floor_material{
	{0.1f,0.19f,0.17f,0.8f}, // Ka
	{0.4f,0.4f,0.49f,0.8f}, // Kd
  {1.0, 1.0, 1.0, 1.0},
  128.0
};

// PEWTER
static const materialStruct pewter_material{
	{0.105882, 0.058824, 0.113725, 1.000000},
	{ 0.427451, 0.470588, 0.541176, 1.000000 },
	{ 0.333333, 0.333333, 0.521569, 1.000000 },
	51.2
};

// BLACK_PLASTIC
static const materialStruct green_plastic{
	{0.000000, 0.500000, 0.000000, 1.000000},
	{ 0.010000, 0.510000, 0.010000, 1.000000 },
	{ 0.500000, 0.500000, 0.500000, 1.000000 },
		51.2
};

// BLUE_RUBBER
static const materialStruct blue_rubber{
	{0.020000, 0.020000, 0.520000, 1.000000},
	{ 0.010000, 0.010000, 0.510000, 1.000000 },
	{ 0.400000, 0.400000, 0.400000, 1.000000 },
	50
};

// JADE
static const materialStruct jade{
	{0.135000, 0.222500, 0.157500, 0.950000},
	{ 0.540000, 0.890000, 0.630000, 0.950000 },
	{ 0.316228, 0.316228, 0.316228, 0.950000 },
	 10
};

// BLACK_RUBBER
static const materialStruct black_rubber{
	{0.020000, 0.020000, 0.020000, 1.000000},
	{ 0.010000, 0.010000, 0.010000, 1.000000 },
	{ 0.400000, 0.400000, 0.400000, 1.000000 },
	50
};

// WALL
static const materialStruct material_wall{
	{ 0.25f, 0.20725f, 0.20725f, 0.922f },
	{1.0f, 0.829f, 0.829f, 0.922f },
	{0.296648f, 0.296648f, 0.296648f, 0.922f },
	11.264f
};