#pragma once

#include "body.h"
#include "domain2d.h"
#include <vector>

class NBodyCalc {
protected:
	std::vector<Body> bodies;	
	Domain2D domain;

protected:
	void computeForces();
	void updateBodies(const double &dt);

public:
	NBodyCalc() {}
	~NBodyCalc() {}

	virtual void initBodies(const int &num, const Domain2D &domain);
	virtual void compute(const double &dt);	

	const std::vector<Body>& getBodies() const {
		return bodies;
	}
};
