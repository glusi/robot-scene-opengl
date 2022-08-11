#pragma once
#include <GL/glut.h>

/**
 * This class implements a geometric Vector.
 */
class Vector3
{
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	/**
	 * Constructs a Vector object - (x,y,z).
	 * 
	 * \param x
	 * \param y
	 * \param z
	 */
	Vector3(GLfloat x,GLfloat y, GLfloat z);
	/**
	 * Constructs a Zero Vector object.
	 * 
	 */
	Vector3();
	/**
	 * update vector to be (x,y,z).
	 * 
	 * \param x
	 * \param y
	 * \param z
	 */
	void update(GLfloat x, GLfloat y, GLfloat z);
	/**
	 * update vector to be (other.x,other.y,other.z).
	 * 
	 * \param other
	 */
	void update(Vector3 other);
	/**
	 * '+=' operator for vectors.
	 * 
	 * \param other
	 * \return 
	 */
	Vector3 operator+=(Vector3 other);
	/**
	 * '-=' operator for vectors.
	 *
	 * \param other
	 * \return
	 */
	Vector3 operator-=(Vector3 other);
	/**
	 * '*' operator for vector and scalar.
	 *
	 * \param other
	 * \return
	 */
	Vector3 operator*(float other);
	/**
	 * '*=' operator for vector and scalar.
	 *
	 * \param other
	 * \return
	 */
	Vector3 operator*=(float other); 
	/**
	 * '*=' operator for two vectors - dot product.
	 * 
	 * \param other
	 * \return 
	 */
	Vector3 operator*=(Vector3 other);
	/**
	 * '+=' operator for two vectors.
	 *
	 * \param other
	 * \return
	 */
	Vector3 operator+(Vector3 other);
	/**
	 * '-=' operator for two vectors .
	 *
	 * \param other
	 * \return
	 */
	Vector3 operator-(Vector3& other);
	/**
	 * '=' operator for two vectors .
	 *
	 * \param other
	 * \return
	 */
	Vector3 operator=(Vector3 other);
	/**
	 * normalizes a vector, so that its size woukd be 1.
	 * 
	 */
	void normalize();
	/**
	 * Creates a (0,0,0) Vector.
	 * 
	 * \return 
	 */
	static Vector3 zeroVector();
};

