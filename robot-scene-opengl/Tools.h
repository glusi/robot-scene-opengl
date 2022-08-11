#pragma once
#define _USE_MATH_DEFINES
#include <math.h> 
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "Constants.h"
#include "Materials.h"
#include <string>
#include "../third-party/imgui/imgui_impl_glut.h"
#include "../third-party/imgui/imgui_impl_opengl3.h"
#include "../third-party/imgui/imgui.h"
#define DEG2RAD(a) (a * (M_PI / 180.0f))
/**
 * This is a utility functions used in the whole project.
 */
static class Tools
{
public:
	/**
	 * Draws a cylinder.
	 * 
	 * \param radius - radius of cylinder
	 * \param halfLength - half length of cylinder
	 * \param slices - number of slices
	 */
	static void drawCylinder(float radius, float halfLength, int slices);
	/**
	 * rotates by angle.
	 * 
	 * \param angle - the angle to be rotated by
	 * \param rotation_type - Which axis is the rotation around
	 */
	static void rotate(float angle, ROTATION_TYPE rotation_type);
	/**
	 * assign a material by type.
	 * 
	 * \param material - the type of material to be assigned
	 */
	static void assignMaterial(materialStruct  material, float emmision);
	/**
	 * copy a color.
	 * 
	 * \param dst_color - destination color
	 * \param new_color - new color
	 */
	static void copyColor(float** dst_color, float* new_color);
	/**
	 * concats two char*.
	 * 
	 * \param one - the destination char*
	 * \param two - the new char*
	 * \return 
	 */
	static std::string concatStrings(const char* one, const char* two);
	/**
	 * Aligns for certain width in ImGui line. Used to create buttons in the middle of line.
	 * 
	 * \param width
	 * \param alignment
	 */
	static void AlignForWidth(float width, float alignment = 0.5f);
	/**
	 * Draws a cube by the cube predefined structure.
	 * 
	 */
	static void drawBox();
	/**
	 * Creates a cube by the cube predefined structure of given size.
	 * Used for textured box like objects, because this way it has normals and can be textured.
	 * 
	 * \param size
	 */
	static void APIENTRY glutSolidCube(GLdouble size);
	
};

