#pragma once

#include "mygl.h"

class Texture {
private:
	GLuint texture_id;	
	int width;
	int height;	

private:
	void clear();

public:
	Texture() : texture_id(-1) {}
	Texture(const char *filename) : texture_id(-1) {
		load(filename);
	}
	~Texture() {
		clear();
	}

	void load(const char *filename);

	void bind();
	void unbind();
};
