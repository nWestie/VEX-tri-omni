#include "Vec2D.h"
#include <math.h>
#include <string>

Vec2D Vec2D::rotate(double angle) {
    // angle *= M_PI / 180;
    Vec2D rotated{x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle)};
    return rotated;
}

double Vec2D::angleTo(Vec2D b) {
    double angle = atan2(b.y, b.x) - atan2(y, x);
    if (angle > M_PI) {
        angle -= 2 * M_PI;
    } else if (angle <= -M_PI) {
        angle += 2 * M_PI;
    }
    return angle * 180 / M_PI;
}

double Vec2D::magnitude() { return sqrt(x * x + y * y); }
// overloads to allow adding 2 vectors with "+" like normal
Vec2D Vec2D::operator+(const Vec2D &other) { return Vec2D{x + other.x, y + other.y}; }
Vec2D Vec2D::operator-(const Vec2D &other) { return Vec2D{x - other.x, y - other.y}; }
Vec2D Vec2D::operator*(const double &other) { return Vec2D{(x * other), (y * other)}; }
Vec2D Vec2D::operator/(const double &other) { return Vec2D{(x / other), (y / other)}; }
Vec2D &Vec2D::operator+=(const Vec2D &other) {
    this->operator+(other);
    return *this;
}

double Vec2D::dotProd(Vec2D other) { return x * other.x + y * other.y; }

Vec2D &Vec2D::operator-=(const Vec2D &other) {
    this->operator-(other);
    return *this;
}

// std::string Vec2D::toString() {
//     return "<" + std::to_string(x) + ", " + std::to_string(y) + ">";
// }