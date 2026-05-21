#ifndef PARTICULA_H
#define PARTICULA_H

#include <fstream>

using namespace std;

class Particula{
private:
    int id;
    double posX, posY;
    double velX, velY;
    double timeX, timeY;
    double masa;
    double ang;
    float g;
    int dir;
    bool colX;

public:
    Particula(int _id, double xIn, double yIn, double velIn, int angIn, float _g);
    void actualizarPosicion(double dt, double ancho, double alto, ofstream &archivo);
    void actualizarValores(double xIn, double yIn);
    bool estaQuieto() const;
};

#endif // PARTICULA_H
