#ifndef PARTICULA_H
#define PARTICULA_H

#include "vector2d.h"

class particula
{
private:

    int id;
    vector2D posicion;
    vector2D velocidad;

    double masa;
    double radio;
    bool activa;

public:
    particula(int id,
              vector2D posicion,
              vector2D velocidad,
              double masa,
              double radio);

    //Getters
    int getId() const;
    vector2D getPosicion() const;
    vector2D getVelocidad() const;
    double getMasa() const;
    double getRadio() const;
    bool estaActiva() const;

    //setters
    void setPosicion(vector2D nuevaPosicion);
    void setVelocidad(vector2D nuevaVelocidad);
    void setMasa(double nuevaMasa);
    void setRadio(double nuevoRadio);
    void setActiva(bool estado);


    void mover(double dt);
    vector2D calcularMomento() const;
    double energiaCinetica () const;
    double distancia(const particula& p) const;
    bool colisiona(const particula& p) const;

};

#endif // PARTICULA_H
