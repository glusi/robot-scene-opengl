#pragma once
#include <GL/glut.h>
#include <GL\freeglut.h>
#include "Constants.h"
#include "stb_image.h"
#include <iostream>
class Texture
{
	GLuint textures[2];
	void loadTexture(unsigned int texture, const char* texture_path);
public:
	Texture();
	void bindTexture(TEXTURE_TYPE texture);
};

