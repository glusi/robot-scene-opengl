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
        delete[] data;
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
    loadTexture(textures[4], WALL_TEXTURE_PATH);
    loadTexture(textures[5], FABRIC_TEXTURE_PATH);
    loadTexture(textures[6], WINDOW_TEXTURE_PATH);
    bool ret = LoadHelpTexture(HELP_TEXTURE_PATH, &help_image_texture, &help_image_width, &help_image_height);
    //
}

void Texture::bindTexture(TEXTURE_TYPE texture)
{
    switch (texture)
    {
    case TEXTURE_FLOOR: glBindTexture(GL_TEXTURE_2D, textures[0]); break;
    case TEXTURE_TABLE: glBindTexture(GL_TEXTURE_2D, textures[1]); break;
    case TEXTURE_BACKGROUND: glBindTexture(GL_TEXTURE_2D, textures[2]); break;
    case TEXTURE_TV: glBindTexture(GL_TEXTURE_2D, textures[3]); break;
    case TEXTURE_WALL: glBindTexture(GL_TEXTURE_2D, textures[4]); break;
    case TEXTURE_FABRIC: glBindTexture(GL_TEXTURE_2D, textures[5]); break;
    case TEXTURE_WINDOW: glBindTexture(GL_TEXTURE_2D, textures[6]); break;
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
    case TEXTURE_WALL: res = textures[4]; break;
    case TEXTURE_FABRIC: res = textures[5]; break;
    case TEXTURE_WINDOW: res = textures[6]; break;
    default:
        res = -1;
        break;
    }
    return res;
}

bool Texture::LoadHelpTexture(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); // Same

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}

int Texture::getHelpImageWidth()
{
    return help_image_width;
}

int Texture::getHelpImageHeight()
{
    return help_image_height;
}

GLuint Texture::getgetHelpImageTexture()
{
    return help_image_texture;
}

