#include "particlesystem.h"

void ParticleSystem::init(const Body *bodies, const int &num) {	
	num_of_particles = num;

	coords.reset(new GLfloat[2*num_of_particles]);	
	indices.reset(new GLuint[num_of_particles]);

	fillCoords(coords.get(), bodies, num);

	glGenBuffers(1, &coord_buffer);	

	glBindBuffer(GL_ARRAY_BUFFER, coord_buffer);
	glBufferData(GL_ARRAY_BUFFER, 2*num_of_particles*sizeof(GLfloat), coords.get(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint *ind = indices.get();
	for (int i = 0; i < num_of_particles; i++)
		ind[i] = i;

	glGenBuffers(1, &indices_buffer);	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_of_particles*sizeof(GLuint), indices.get(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	sprite.load("textures/circle_t.png");	
}

void ParticleSystem::update(const Body *bodies, const int &num) {
	fillCoords(coords.get(), bodies, num);

	glBindBuffer(GL_ARRAY_BUFFER, coord_buffer);
	glBufferSubData(GL_ARRAY_BUFFER, 0, 2*num_of_particles*sizeof(GLfloat), coords.get());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ParticleSystem::fillCoords(GLfloat *buf, const Body *bodies, const int &num) {
	for (int i = 0; i < num; i++) {
		buf[2*i] = (GLfloat)bodies[i].coordinate.x;
		buf[2*i + 1] = (GLfloat)bodies[i].coordinate.y;
	}
}

void ParticleSystem::draw() {	
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(5.0f);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SPRITE);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);

	sprite.bind();

	glBindBuffer(GL_ARRAY_BUFFER, coord_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer);
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(2, GL_FLOAT, 0, 0); 			
	glDrawElements(GL_POINTS, num_of_particles, GL_UNSIGNED_INT, 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);	

	sprite.unbind();

	glDisable(GL_BLEND);
	glDisable(GL_POINT_SPRITE);
	glDisable(GL_TEXTURE_2D);
}

void ParticleSystem::clear() {
/*	if (coord_buffer)
		glDeleteBuffers(1, &coord_buffer);
	if (indices_buffer)
		glDeleteBuffers(1, &indices_buffer);*/
	coord_buffer = 0;
	indices_buffer = 0;	
}
