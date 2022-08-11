#pragma once
#include "SceneItem.h"

class Lights : SceneItem
{
	//Color for point light
	GLfloat* point_light_color;
	//Point light position
	GLfloat point_light_poistion[4];
	//Color for ambient light
	GLfloat* light_ambient;
	//Boolean true if ambient is enabled in menu
	bool ambient_enabled = true;
	//Boolean true if point is enabled in menu
	bool point_enabled = true;
public:
	/**
	 * Constructor for Lights - initializes fields
	 * 
	 */
	Lights();
	/**
	 * draw the lights - ambient and point
	 * 
	 */
	void draw();
	/**
	 * set new ambient color
	 * 
	 * \param color_new - the new color
	 */
	void adjustAmbientLight(float* color_new);
	/**
	 * Getter for ambient color
	 * 
	 * \return ambient color
	 */
	float* getAmbientColor();
	/**
	 * gets the light position on axis
	 * 
	 * \param axis -  the axis on which we want the position
	 * \return - position on axis
	 */
	float getPointLightPosition(POINT_LIGHT_POS axis);
	/**
	 * set point light position
	 * 
	 * \param point_light_position -  the new position
	 */
	void applyPointLightPos(Vector3 point_light_position);
	/**
	 * Getter for point color
	 *
	 * \return point color
	 */
	GLfloat* getPointLightColor();
	/**
	 * set new point color
	 *
	 * \param color_new - the new color
	 */
	void adjustPointLight(float* color);
	/**
	 * draw orn around point light, so it will be more visible
	 * 
	 */
	void drawOrb();
	/**
	 * set ambient light enabled or disabled
	 * 
	 * \param enabled
	 */
	void disableAmbient(bool enabled);
	/**
	 * set point light enabled or disabled
	 *
	 * \param enabled
	 */
	void disablePoint(bool enabled);
};

