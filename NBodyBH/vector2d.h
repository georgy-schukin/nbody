#pragma once

#include <cmath>

/**
  * @brief Pair of two real values: x and y
  */
class Vector2D
{
public:
    double x;
    double y;

public:
    Vector2D() : x(0.0), y(0.0) {}
    Vector2D(const double &val) : x(val), y(val) {}
    Vector2D(const double &xx, const double &yy) : x(xx), y(yy) {}
    ~Vector2D() {}

    void set(const double &xx, const double &yy) {
        x = xx;
        y = yy;
    }

    void operator=(const double &val) {
        x = val;
        y = val;
    }

    void operator+=(const Vector2D &v) {
        x += v.x;
        y += v.y;
    }

    void operator-=(const Vector2D &v) {
        x -= v.x;
        y -= v.y;
    }

    void operator/=(const double &val) {
        x /= val;
        y /= val;
    }

    Vector2D operator*(const double &val) const {
        return Vector2D(x*val, y*val);
    }

    bool operator==(const Vector2D &v) const {
        static const double EPS = 1e-10;
        return (fabs(x - v.x) < EPS && fabs(y - v.y) < EPS);
    }
};
