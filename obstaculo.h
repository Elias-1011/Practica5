#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "vector2d.h"
#include "particula.h"


class obstaculo{

private:
    vector2D esquina; // esquina superior izquierda
    double ancho;
    double alto;
    double epsilon; // coeficiente de restitucion

public:

    obstaculo(double x, double y, double ancho, double alto, double epsilon);

    bool colisionConParticula(particula& p);
    double getEpsilon() const { return epsilon; }

    // Getters
    vector2D getEsquina() const { return esquina; }
    double getAncho() const { return ancho; }
    double getAlto() const { return alto; }


};

#endif // OBSTACULO_H
