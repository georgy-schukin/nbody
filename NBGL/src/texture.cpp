#include "texture.h"

void Texture::load(const char *filename) {
	clear();

	unsigned char *image = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    //glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	SOIL_free_image_data(image);
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, texture_id);	
}

void Texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::clear() {
	if (texture_id != -1)
		glDeleteTextures(1, &texture_id);	
	texture_id = 0;	
}
