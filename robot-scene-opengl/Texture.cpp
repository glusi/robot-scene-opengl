#include "Texture.h"



void Texture::loadTexture(unsigned int texture, const char* texture_path)
{
    
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char* data = stbi_load(texture_path, &width, &height, &nrChannels, 3);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
}


Texture::Texture()
{
    
    glGenTextures(2, textures);
    loadTexture(textures[0], FLOOR_TEXTURE_PATH);
    loadTexture(textures[1], TABLE_TEXTURE_PATH);
}

void Texture::bindTexture(TEXTURE_TYPE texture)
{
    switch (texture)
    {
    case TEXTURE_FLOOR: glBindTexture(GL_TEXTURE_2D, textures[0]); break;
    case TEXTURE_TABLE: glBindTexture(GL_TEXTURE_2D, textures[1]); break;
    default:
        break;
    }
    
}

