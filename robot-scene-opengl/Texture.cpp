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
    
    glGenTextures(NUM_OF_TEXTURES, textures);
    loadTexture(textures[0], FLOOR_TEXTURE_PATH);
    loadTexture(textures[1], TABLE_TEXTURE_PATH);
    loadTexture(textures[2], BACKGROUND_TEXTURE_PATH);
    loadTexture(textures[3], TV_TEXTURE_PATH);
}

void Texture::bindTexture(TEXTURE_TYPE texture)
{
    switch (texture)
    {
    case TEXTURE_FLOOR: glBindTexture(GL_TEXTURE_2D, textures[0]); break;
    case TEXTURE_TABLE: glBindTexture(GL_TEXTURE_2D, textures[1]); break;
    case TEXTURE_BACKGROUND: glBindTexture(GL_TEXTURE_2D, textures[2]); break;
    case TEXTURE_TV: glBindTexture(GL_TEXTURE_2D, textures[3]); break;
    default:
        break;
    }
    
}

GLuint Texture::getTextureId(TEXTURE_TYPE texture)
{
    int res;
    switch (texture)
    {
    case TEXTURE_FLOOR: res = textures[0]; break;
    case TEXTURE_TABLE: res = textures[1]; break;
    case TEXTURE_BACKGROUND: res = textures[2]; break;
    case TEXTURE_TV: res = textures[3]; break;
    default:
        res = -1;
        break;
    }
    return res;
}

