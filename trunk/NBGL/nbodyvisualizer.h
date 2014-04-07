#pragma once

#include "particlesystem.h"
#include "texture.h"
#include "body.h"
#include "domain2d.h"

class NBodyVisualizer {
private:
	ParticleSystem particles;
	Texture space;
	Domain2D area;

public:
	NBodyVisualizer() {}
	~NBodyVisualizer() {}

	void setArea(const Domain2D &area) {
		this->area = area;
	}

	void init(const Body *bodies, const int &num);
	void update(const Body *bodies, const int &num);
	void draw();
};
