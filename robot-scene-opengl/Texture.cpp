#include "Texture.h"


void Texture::loadTexture()
{
	/*FILE* f = nullptr;
	errno_t status = fopen_s(&f, file_name.c_str(), "rb");
	if (status != 0) {
		Image_data = nullptr;
		return;
	}

	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

											   // extract image height and width from header
	width = *(int*)&info[18];
	height = *(int*)&info[22];
	int size = 3 * width * height;
	unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
	fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
	fclose(f);
	int i;
	for (i = 0; i < size; i += 3)
	{
		unsigned char tmp = data[i];
		data[i] = data[i + 2];
		data[i + 2] = tmp;
	}*/
	/*FILE* f = nullptr;
	errno_t status = fopen_s(&f, file_name.c_str(), "rb");
	if (status != 0) {
		Image_data = nullptr;
		return;
	}
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
	std::ifstream inputfile(file_name, std::ios::binary);
	uint8_t headerbytes[54] = {};

	inputfile.read((char*)headerbytes, sizeof(headerbytes));
	uint32_t filesize = *(uint32_t*)(headerbytes + 2);
	uint32_t width = *(uint32_t*)(headerbytes + 18);
	uint32_t height = *(uint32_t*)(headerbytes + 22);
	int size = 3 * width * height;
	unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
	fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
	fclose(f);
	int i;
	for (i = 0; i < size; i += 3)
	{
		unsigned char tmp = data[i];
		data[i] = data[i + 2];
		data[i + 2] = tmp;
	}
	Image_data = data;*/
/*	int width, height, nrChannels;
	unsigned char* data = stbi_load(file_name.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	Image_data = data;
	stbi_image_free(data);*/
}

void Texture::mapTexture(float x, float y, float tile_size_x, float tile_size_y)
{
	GLfloat color[4] = { 1.0, 1.0, 1.0 , 1.0 };
	glColor4fv(color);
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f },
		shininess = 128.0f;

	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
	glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, texName);
	glBegin(GL_QUADS);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexCoord2f(0.0, 0.0); glVertex3f(x * tile_size_x, 0, y * tile_size_y);
	glTexCoord2f(0.0, 1.0); glVertex3f((x + 1) * tile_size_x, 0, y * tile_size_y);
	glTexCoord2f(1.0, 1.0); glVertex3f((x + 1) * tile_size_x, 0, (y + 1) * tile_size_y);
	glTexCoord2f(1.0, 0.0); glVertex3f(x * tile_size_x, 0, (y + 1) * tile_size_y);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
}

Texture::Texture(std::string name)
{
/*	file_name = name;
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, Image_data);*/
	// set the texture wrapping/filtering options (on the currently bound texture object)
/*	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//loadTexture();
	// load and generate the texture
	int width, height, nrChannels;
	unsigned char* data = stbi_load(file_name.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);*/
}

Texture::Texture()
{
	file_name = "";
}
