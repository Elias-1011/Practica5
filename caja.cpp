#include "caja.h"

caja::caja(double ancho, double alto) : ancho(ancho), alto(alto) {}

double caja::getAncho() const{return ancho;}

double caja::getAlto() const{return alto;}

bool caja::colisionPared(const particula &p) const{

    vector2D pos = p.getPosicion();
    double x = pos.getX();
    double y = pos.getY();

    double r = p.getRadio();

    return (x-r <=0 || x+r >= ancho || y-r <= 0 || y+r >= alto);
}

//Aplicar rebote
void caja::manejarColisionPared(particula &p){
    vector2D pos = p.getPosicion();
    vector2D vel = p.getVelocidad();

    double x = pos.getX();
    double y = pos.getY();

    double vx = vel.getX();
    double vy = vel.getY();
    double r = p.getRadio();

    //pared izq

    if(x-r <=0){
        x = r;
        vx = -vx;
    }

    //pared der

    if (x+r >= ancho){
        x= ancho - r;
        vx = -vx;
    }

    //pared inf

    if (y-r <=0){
        y=r;
        vy = -vy;
    }

    //pared sup

    if(y+r >= alto){
        y = alto - r;
        vy = -vy;
    }

    p.setPosicion(vector2D(x, y));
    p.setVelocidad(vector2D(vx, vy));
}
