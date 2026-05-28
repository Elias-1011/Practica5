#include "particula.h"
#include <cmath>

particula::particula(int id,
                     vector2D posicion, vector2D velocidad,
                     double masa, double radio)
    : id(id), posicion(posicion), velocidad(velocidad), masa(masa), radio(radio), activa(true) {}

int particula::getId() const {return id;}

vector2D particula::getPosicion() const {return posicion;}
vector2D particula::getVelocidad() const {return velocidad;}
double particula::getMasa() const {return masa;}
double particula::getRadio() const {return radio;}
bool particula::estaActiva() const {return activa;}


void particula::setPosicion(vector2D nuevaPosicion){ posicion=nuevaPosicion; }
void particula::setVelocidad(vector2D nuevaVelocidad){ velocidad = nuevaVelocidad;}
void particula::setMasa(double nuevaMasa){ masa= nuevaMasa;}
void particula::setRadio(double nuevoRadio){ radio = nuevoRadio;}
void particula::setActiva(bool estado){ activa= estado;}

void particula::mover(double dt){
    posicion = posicion + (velocidad * dt);
}

vector2D particula::calcularMomento() const{
    return velocidad*masa;
}

double particula::energiaCinetica() const{

    double rapidez = velocidad.modulo();

    return 0.5*masa*rapidez*rapidez;
}

//Distancia entre particulas
double particula::distancia(const particula &p) const{
    return posicion.distancia(p.getPosicion());
}

//verificar colision
bool particula::colisiona(const particula &p) const{
    return distancia(p) <= (radio + p.getRadio());
}
