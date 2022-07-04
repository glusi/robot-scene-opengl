#include "Vector3.h"
#include <math.h>

Vector3::Vector3(GLfloat new_x, GLfloat new_y, GLfloat new_z)
{
	x = new_x;
	y = new_y;
	z = new_z;
}

Vector3::Vector3()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

void Vector3::update(GLfloat new_x, GLfloat new_y, GLfloat new_z)
{
	x = new_x;
	y = new_y;
	z = new_z;
}

void Vector3::update(Vector3 other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

Vector3 Vector3::operator+=(Vector3& other)
{
	// Guard self assignment
	if (this == &other)
		return *this;
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

Vector3 Vector3::operator-=(Vector3& other)
{
	// Guard self assignment
	if (this == &other)
		return *this;
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

Vector3 Vector3::operator-(Vector3& other)
{
	return Vector3(x-other.x,y-other.y,z-other.z);
}

Vector3 Vector3::operator=(Vector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

Vector3 Vector3::operator=(Vector3 other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

void Vector3::normalize()
{
	float value = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
	x /= value;
	y /= value;
	z /= value;
}

Vector3 Vector3::zero()
{
	return Vector3();
}
