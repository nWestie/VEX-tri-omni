#pragma once
#include <string>

class Vec2D {
public:
    double x{0};
    double y{0};
    // rotates the vector 'angle' radians
    Vec2D(double x, double y):x{x},y{y}{};

    Vec2D rotate(double angle);
    double angleTo(Vec2D b);
    double magnitude();
    double dotProd(Vec2D other);
    // overloads to allow adding 2 vectors with "+" like normal
    Vec2D operator+(const Vec2D &other);
    Vec2D operator-(const Vec2D &other);
    Vec2D operator*(const double &other);
    Vec2D operator/(const double &other);
    Vec2D &operator+=(const Vec2D &other);
    Vec2D &operator-=(const Vec2D &other);
    Vec2D &operator*=(const Vec2D &other);
    
    // void print(){
    //     Serial.print("<");
    //     Serial.print(x);
    //     Serial.print(", ");
    //     Serial.print(y);
    //     Serial.println(">");
    // }
    // std::string toString();
    
};
