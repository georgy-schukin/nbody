#include "nbodytreecalc.h"
#include <omp.h>

void NBodyTreeCalc::compute(const double &dt) {	
	computeForcesWithTree();
	updateBodies(dt);
}	

void NBodyTreeCalc::computeForcesWithTree() {	
	QuadTree tree(bodies.data(), bodies.size(), domain);

	#pragma omp parallel
    for (size_t i = 0; i < bodies.size(); i++) {     
        bodies[i].force = tree.computeForce(&bodies[i], 1.0);		
    }
}
