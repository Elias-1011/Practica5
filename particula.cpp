#include "particula.h"
#include <cmath>
#include <fstream>

Particula::Particula(int _id, double xIn, double yIn, double velIn, int _angIn, float _g){
    id = _id, posX = xIn, posY = yIn, timeX = 0, timeY = 0, ang = _angIn, g = _g, colX = true;
    velX = velIn * cos(ang * (M_PI / 180));
    velY = velIn * sin(ang * (M_PI / 180));
}

void Particula::actualizarPosicion(double dt, double ancho, double alto, ofstream &archivo){
    double newPosX = posX + (velX * timeX * dir);
    double newPosY = posY - (velY * timeY) + (g * timeY * timeY * 0.5);

    archivo << newPosX << " " << newPosY << " " << velX << " " << velY << "\n";

    if(newPosX >= ancho){
        colX = true;
        actualizarValores(newPosX, newPosY);
    }

    if (newPosY >= alto) {
        newPosY = alto;
        colX = false;
        actualizarValores(newPosX, newPosY);

        // Reducir energía del rebote
        velY *= 0.7;
        if (fabs(velY) < 1.0)
            velY = 0;
    }

    // Actualizar tiempo
    timeX += dt;
    timeY += dt;
}

void Particula::actualizarValores(double xIn, double yIn){
    if(colX){
        dir *= -1;
        posX = xIn;
    }
    posX = xIn;
    posY = yIn;
    ang = -atan2(velY, velX) * 180 / M_PI;
}

bool Particula::estaQuieto() const{
    return (velY == 0);
}
