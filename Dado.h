#ifndef PROYECTOESTRUCTURADATOS_DADO_H
#define PROYECTOESTRUCTURADATOS_DADO_H

#include <random>
using namespace std;

class Dado {
public:
    Dado(); // Constructor: Initializes the random number generator
    int tirar(int num); // Rolls the dice and returns a random number between 1 and 'num'
    int lanzarDadoConExclusion(Dado& dadito, vector<int>& exclusiones); // Rolls a dice with exclusions

private:
    mt19937 generador; // Mersenne Twister random number generator
};

#endif
