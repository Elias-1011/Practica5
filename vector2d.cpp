#include "vector2d.h"

vector2D::vector2D(double x, double y) : x(x), y(y) {}

vector2D vector2D::operator+(const vector2D& v) const {
    return vector2D(x + v.x, y + v.y);
}

vector2D vector2D::operator*(double escalar) const {
    return vector2D(x * escalar, y * escalar);
}

vector2D vector2D::operator -(const vector2D& v) const{
    return vector2D (
        x - v.x,
        y - v.y
        );
}

double vector2D::modulo() const {
    return std::sqrt(x * x + y * y);
}

double vector2D::productoPunto(const vector2D &v) const{
    return x*v.x + y*v.y;
}

vector2D vector2D::normalizar() const{
    double magnitud = modulo();

    if (magnitud ==0){
        return vector2D(0,0);
    }

    return vector2D (x/magnitud, y/magnitud);
}

double vector2D::distancia(const vector2D &v) const{
    return (*this - v).modulo();
}
