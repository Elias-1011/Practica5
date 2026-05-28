#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>


class vector2D{
private:
    double x;
    double y;

public:

    vector2D(double x=0, double y=0);

    vector2D operator+(const vector2D& v ) const;
    vector2D operator*(double escalar) const;
    vector2D operator-(const vector2D& v) const;

    double modulo() const;
    double productoPunto(const vector2D& v) const;
    vector2D normalizar() const;
    double distancia (const vector2D& v) const;

    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }

};

#endif // VECTOR2D_H
