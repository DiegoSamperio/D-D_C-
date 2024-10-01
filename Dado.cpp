#include <algorithm>
#include "Dado.h"

// Constructor: initializes the random number generator using a random device
Dado::Dado() : generador(random_device{}()) {}

// Rolls a dice with 'num' faces and returns a random number between 1 and 'num'
int Dado::tirar(int num) {
    uniform_int_distribution<int> distribution(1, num);
    return distribution(generador);
}

// Rolls a 20-sided dice, excluding certain numbers in the 'exclusiones' list.
// If the result is in the exclusion list, it rolls again until a valid number is rolled.
int Dado::lanzarDadoConExclusion(Dado& dadito, vector<int>& exclusiones) {
    int dungeonRoll;
    do {
        dungeonRoll = dadito.tirar(20); // Rolls the dice with 20 faces

        // Check if 'dungeonRoll' is in the 'exclusiones' list
        if (find(exclusiones.begin(), exclusiones.end(), dungeonRoll) != exclusiones.end()) {
            // If 'dungeonRoll' is in the list, roll again
            continue;
        }

        // If 'dungeonRoll' is not in the list, exit the loop
        break;
    } while (true);

    return dungeonRoll;
}