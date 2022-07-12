#pragma once
#include "Tools.h"
#include <string>
#include <fstream>
#include <stdint.h>
#include "stb_image.h"
#include <iostream>
class Texture
{
	std::string file_name;
	unsigned char* Image_data;
	GLuint texName;
	GLsizei width;
	GLsizei height;
public: 
	void loadTexture();
	void mapTexture(float x, float y, float tile_size_x, float tile_size_y);
	Texture(std::string name);
	Texture();
};

