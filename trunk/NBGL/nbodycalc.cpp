#include "nbodycalc.h"
#include <cstdlib>
#include <ctime>
#include <omp.h>

void NBodyCalc::initBodies(const int &num, const Domain2D &domain) {
	this->domain = domain;
	bodies.resize(num);
	srand(time(0));

	#pragma omp parallel shared(domain)
	for (size_t i = 0; i < bodies.size(); i++)
        bodies[i].init(domain);		
}

void NBodyCalc::compute(const double &dt) {
	computeForces();
	updateBodies(dt);
}	

void NBodyCalc::computeForces() {
	#pragma omp parallel
	for (size_t i = 0; i < bodies.size(); i++) {
		bodies[i].force = 0.0; // null force
	}
	#pragma omp parallel
    for (size_t i = 0; i < bodies.size(); i++) {     
        for (size_t j = 0; j < bodies.size(); j++) {
            const Vector2D force_ij = bodies[i].computeForce(bodies[j]);
            bodies[i].force += force_ij;
            //bodies[j].force -= force_ij; // Fij = -Fji
        }
    }
}

void NBodyCalc::updateBodies(const double &dt) {
	#pragma omp parallel shared(dt)
    for (size_t i = 0; i < bodies.size(); i++) {
        bodies[i].update(dt);
    }
}
