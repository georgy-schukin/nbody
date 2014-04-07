#pragma once

#include "nbodycalc.h"
#include "quadtree.h"

class NBodyTreeCalc : public NBodyCalc {
protected:
	void computeForcesWithTree();

public:
	NBodyTreeCalc() {}
	~NBodyTreeCalc() {}
		
	virtual void compute(const double &dt);
};