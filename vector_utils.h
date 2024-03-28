#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

#include <cmath>
#include <vector>
#include <utility>


struct Vector2D {
    double x, y;

    
    Vector2D(double x, double y) : x(x), y(y) {}
    double magnitude() const {
        return std::sqrt(x*x + y*y);
    }
};


double dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}


double cosineDistance(const Vector2D& v1, const Vector2D& v2) {
    double dot = dotProduct(v1, v2);
    double magV1 = v1.magnitude();
    double magV2 = v2.magnitude();
    return dot / (magV1 * magV2);
}

#endif 