#include "body.h"
#include <cmath>
#include <cstdlib>

void Body::init(const Domain2D &domain) {
    static const double PI = 3.14159;
    const double angle = double(rand() % 360) * PI / 180.0;
    const double radius = (domain.width() / 2.0) * double(rand() % 1000) / 1000.0;
    //coordinate.x = domain.left + domain.width() * double(rand() % 1000) / 1000.0;
    //coordinate.y = domain.bottom + domain.height() * double(rand() % 1000) / 1000.0;
    coordinate.x = domain.left + domain.width() / 2.0 + radius*cos(angle);
    coordinate.y = domain.bottom + domain.height() / 2.0 + radius*sin(angle);
    velocity.x = double(rand() % 2000 - 1000) / 100.0;
    velocity.y = double(rand() % 2000 - 1000) / 100.0;
    mass = double(rand() % 1000 + 10000) / 10.0; // avoid zero mass
}

Vector2D Body::computeForce(const Body &other) const {
    static const double G = 6.673e-11;

    const double dx = other.coordinate.x - coordinate.x;
    const double dy = other.coordinate.y - coordinate.y;
    const double dist = sqrt(dx*dx + dy*dy) + 1e-12; // avoid zero distance
    const double temp = G*other.mass*mass/(dist*dist*dist);

    return Vector2D(temp*dx, temp*dy);
}

void Body::update(const double &dt) {
    coordinate.x += dt*velocity.x; // update coordinate
    coordinate.y += dt*velocity.y;
    velocity.x += dt*force.x/mass; // update velocity
    velocity.y += dt*force.y/mass;
}
