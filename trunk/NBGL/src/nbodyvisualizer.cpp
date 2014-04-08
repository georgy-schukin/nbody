#include "nbodyvisualizer.h"

void NBodyVisualizer::init(const Body *bodies, const int &num) {	
	particles.init(bodies, num);
	space.load("textures/space.png");
}

void NBodyVisualizer::update(const Body *bodies, const int &num) {    
	particles.update(bodies, num);
}

void NBodyVisualizer::draw() {		        
    const GLfloat vertex_coord[] = {(GLfloat)area.left, (GLfloat)area.bottom,
                                    (GLfloat)area.right, (GLfloat)area.bottom,
                                    (GLfloat)area.right, (GLfloat)area.top,
                                    (GLfloat)area.left, (GLfloat)area.top};
    static const GLfloat tex_coord[] = {0, 1, 1, 1, 1, 0, 0, 0};
    static const GLubyte indices[] = {0, 1, 2, 3};

    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, vertex_coord);
    glTexCoordPointer(2, GL_FLOAT, 0, tex_coord);

    glColor3f(0.5f, 0.5f, 0.5f);

    space.bind();

    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, indices);

	space.unbind();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D);

    particles.draw();
}
