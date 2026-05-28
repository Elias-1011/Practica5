#include <iostream>
#include "simulador.h"

using namespace std;

int main()
{
    simulador sim (
        0.01, 500, 400
        );

    sim.agregarObstaculo(
        100, 100,
        50, 50,
        0.7
        );

    sim.agregarObstaculo(
        300, 80,
        40, 70,
        0.8
        );

    sim.agregarObstaculo(
        150, 250,
        60, 40,
        0.6
        );

    sim.agregarObstaculo(
        350, 2550,
        50, 50,
        0.75
        );

    sim.agregarParticula(
        1,
        50, 50,
        40, 25,
        2,
        5
        );

    sim.agregarParticula(
        2,
        450, 100,
        -35, 30,
        3,
        5
        );

    sim.agregarParticula(
        3,
        100, 350,
        45, -20,
        2.5,
        5
        );

    sim.agregarParticula(
        4,
        400, 300,
        -30, 25,
        1.5,
        5
        );

    sim.ejecutar(20, "simulacion.txt");

    return 0;
}
