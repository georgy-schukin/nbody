#include "texture.h"

void Texture::load(const char *filename) {
	clear();

	/*FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename);
	FIBITMAP *bitmap = FreeImage_Load(format, filename); 	
	FIBITMAP *bitmap32 = FreeImage_ConvertTo32Bits(bitmap);	
 
	width = FreeImage_GetWidth(bitmap32);
	height = FreeImage_GetHeight(bitmap32);	
	const int scan_width = FreeImage_GetPitch(bitmap32);

	bits = new BYTE[height * scan_width];

	FreeImage_ConvertToRawBits(bits, bitmap32, scan_width, 32, FI_RGBA_RED_MASK, FI_RGBA_GREEN_MASK, FI_RGBA_BLUE_MASK, TRUE);
 		
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_BGRA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, bits);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	FreeImage_Unload(bitmap);
	FreeImage_Unload(bitmap32);*/
	unsigned char *image = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
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
