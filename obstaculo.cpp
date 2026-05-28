#include "obstaculo.h"
#include <algorithm>
#include <cmath>

obstaculo::obstaculo(double x, double y, double ancho, double alto, double epsilon)
    : esquina(x, y), ancho(ancho), alto(alto), epsilon(epsilon) {}

bool obstaculo::colisionConParticula(particula& p) {

    // si esta inactiva

    if (!p.estaActiva()) return false;

    vector2D pos = p.getPosicion();
    double radio = p.getRadio();

    // limites del obstaculo

    double izquierda = esquina.getX();
    double derecha = esquina.getX() + ancho;
    double arriba = esquina.getY();
    double abajo = esquina.getY() + alto;

    // detectar colisiones

    double closestX = std::max(izquierda, std::min(pos.getX(), derecha));
    double closestY = std::max(arriba, std::min(pos.getY(), abajo));

    double dx = pos.getX() - closestX;
    double dy = pos.getY() - closestY;
    double distancia = std::sqrt(dx*dx + dy*dy);

    if (distancia >= radio) return false;

    // calcular normal del impacto

    vector2D normal;
    bool tocandoEsquina = (closestX == izquierda || closestX == derecha) &&
                          (closestY == arriba || closestY == abajo);

    if (tocandoEsquina) {
        normal = vector2D(dx, dy);
        if (normal.modulo() > 0) {
            normal = normal.normalizar();
        }
    } else if (closestX == izquierda || closestX == derecha) {
        normal = vector2D((closestX == izquierda) ? -1 : 1, 0);
    } else {
        normal = vector2D(0, (closestY == arriba) ? -1 : 1);
    }

    // separar particula

    double overlap = radio - distancia;
    vector2D correccion = normal * overlap;
    p.setPosicion(pos + correccion);

    vector2D vel = p.getVelocidad();
    double velocidadNormal = vel.productoPunto(normal);

    if (velocidadNormal < 0) {
        vector2D velParalela = vel - (normal * velocidadNormal);
        vector2D velNormalNueva = normal * (-velocidadNormal * epsilon);
        vector2D nuevaVel = velParalela + velNormalNueva;
        p.setVelocidad(nuevaVel);
    }

    return true;
}
