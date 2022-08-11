#pragma once
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "Constants.h"
#include "stb_image.h"
#include <iostream>


class Texture
{
	//An array of texture ids
	GLuint textures[NUM_OF_TEXTURES];
	// width of help image.
	int help_image_width = 0;
	// height of help image.
	int help_image_height = 0;
	//Help image texture id
	GLuint help_image_texture = 0;
	/**
	 * loads a texture into the project to be used later on objects.
	 * 
	 * \param texture - id of texture
	 * \param texture_path - path to the texture
	 */
	void loadTexture(unsigned int texture, const char* texture_path);
public:
	/**
	 * Constructs Texture object.
	 * Generates NUM_OF_TEXTURES textures and then loads all the textures
	 * 
	 */
	Texture();
	/**
	 * Bind a wanted texture to be applied on an object.
	 * 
	 * \param texture - which texture to bind
	 */
	void bindTexture(TEXTURE_TYPE texture);
	/**
	 * Loads the help page texture png and returns it and its size, to be used in the Menu popup
	 * 
	 * \param filename
	 * \param out_texture
	 * \param out_width
	 * \param out_height
	 * \return 
	 */
	bool LoadHelpTexture(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	/**
	 * getter for help image width.
	 * 
	 * \return help image width
	 */
	int getHelpImageWidth();
	/**
	 * getter for help image height.
	 *
	 * \return help image height
	 */
	int getHelpImageHeight();
	/**
	 * getter for help image texture.
	 *
	 * \return help image texture
	 */
	GLuint getHelpImageTexture();
};

