#pragma once
#include <GL/glut.h>

class Vector3
{
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	Vector3(GLfloat x,GLfloat y, GLfloat z);
	Vector3();
	void update(GLfloat x, GLfloat y, GLfloat z);
	void update(Vector3 other);
	Vector3 operator+=(Vector3& other);
	Vector3 operator-=(Vector3& other);
	Vector3 operator-(Vector3& other);
	Vector3 operator=(Vector3& other);
	Vector3 operator=(Vector3 other);
	void normalize();
	static Vector3 zeroVector();
};

