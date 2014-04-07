#include "mygl.h"
#include "nbodycalc.h"
#include "nbodytreecalc.h"
#include "nbodyvisualizer.h"
#include <cstdio>
#include <omp.h>

NBodyTreeCalc calc;
NBodyVisualizer visualizer;

const Domain2D domain(-10, 10, -10, 10);
const int NUM_OF_BODIES = 10000;
//const int NUM_OF_THREADS = 4;


void Reshape(int width, int height)
{
	const float scale = 4.0f;
	const float aspect = float(width) / float (height);	

	const Domain2D area(aspect*scale*domain.left, aspect*scale*domain.right, scale*domain.bottom, scale*domain.top);
	const float max = area.width() > area.height() ? area.width() : area.height();
	const Domain2D v_area(-max/2.0, max/2.0, -max/2.0, max/2.0);	

	visualizer.setArea(v_area);

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(area.left, area.right, area.bottom, area.top);
	glMatrixMode(GL_MODELVIEW);
}

void Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	visualizer.draw();

	glFlush();  
}

void init() {
	calc.initBodies(NUM_OF_BODIES, domain);
	visualizer.init(calc.getBodies().data(), calc.getBodies().size());
}

void update() {
	calc.compute(0.01);
	visualizer.update(calc.getBodies().data(), calc.getBodies().size());
	Draw();	
}

int main(int argc, char *argv[]) {	
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow("N-Body simulation");

	glutReshapeFunc(Reshape);
	glutDisplayFunc(Draw);
	glutIdleFunc(update);		

	glShadeModel(GL_SMOOTH);      
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	GLenum err;
	if ((err = glewInit()) != GLEW_OK) {
		printf("GLEW init ERROR : %s\n", glewGetErrorString(err));
	}

	//omp_set_num_threads(NUM_OF_THREADS);

	init();

	glutMainLoop();
	
	return 0;
}
