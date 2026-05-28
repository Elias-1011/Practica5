#ifndef CAJA_H
#define CAJA_H

#include "particula.h"

class caja
{
private:
    double ancho;
    double alto;
public:
    caja(double ancho, double alto);

    double getAncho() const;
    double getAlto() const;

    bool colisionPared(const particula& p) const;

    void manejarColisionPared(particula& p);
};

#endif // CAJA_H
