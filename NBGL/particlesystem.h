#pragma once

#include <memory>
#include "mygl.h"
#include "body.h"
#include "texture.h"

class ParticleSystem {
private:
	GLuint coord_buffer, indices_buffer;
	std::auto_ptr<GLfloat> coords;
	std::auto_ptr<GLuint> indices;
	Texture sprite;
	int num_of_particles;

private:
	void fillCoords(GLfloat *buf, const Body *bodies, const int &num);	
	void clear();	

public:
	ParticleSystem() : num_of_particles(0), coord_buffer(0), indices_buffer(0) {}
	~ParticleSystem() {
		clear();
	}

	void init(const Body *bodies, const int &num);
	void update(const Body *bodies, const int &num);
	void draw();
};