#include "nbodyvisualizer.h"

void NBodyVisualizer::init(const Body *bodies, const int &num) {	
	particles.init(bodies, num);
	space.load("textures/space.png");
}

void NBodyVisualizer::update(const Body *bodies, const int &num) {    
	particles.update(bodies, num);
}

void NBodyVisualizer::draw() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glColor3f(0.5f, 0.5f, 0.5f);

	space.bind();

	glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glVertex2f((GLfloat)area.left, (GLfloat)area.bottom);
		glTexCoord2d(1, 1);
		glVertex2f((GLfloat)area.right, (GLfloat)area.bottom);
		glTexCoord2d(1, 0);
		glVertex2f((GLfloat)area.right, (GLfloat)area.top);
		glTexCoord2d(0, 0);
		glVertex2f((GLfloat)area.left, (GLfloat)area.top);
	glEnd();

	space.unbind();

	glDisable(GL_TEXTURE_2D);

	particles.draw();
}