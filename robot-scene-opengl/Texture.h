#pragma once
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "Constants.h"
#include "stb_image.h"
#include <iostream>


class Texture
{
	GLuint textures[NUM_OF_TEXTURES];
	void loadTexture(unsigned int texture, const char* texture_path);
	int help_image_width = 0;
	int help_image_height = 0;
	GLuint help_image_texture = 0;
public:
	Texture();
	void bindTexture(TEXTURE_TYPE texture);
	GLuint getTextureId(TEXTURE_TYPE texture);
	bool LoadHelpTexture(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	int getHelpImageWidth();
	int getHelpImageHeight();
	GLuint getgetHelpImageTexture();
};

