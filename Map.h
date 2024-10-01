#ifndef PROYECTOESTRUCTURADATOS_MAP_H
#define PROYECTOESTRUCTURADATOS_MAP_H

#include "Monster.h"
#include "Spell.h"
#include "LinkedList.h"
#include "Dugeon.h"

// Map class responsible for generating and managing dungeons
class Map {

private:
    LinkedList<Dugeon> Calabozos; // List of dungeons

public:
    Map(); // Default constructor

    // Constructor: Creates a map with a given number of dungeons, and randomly assigns monsters and spells
    Map(int num, LinkedList<Monster> disponibles, LinkedList<Spell> SpeDisponibles);

    void printMap(); // Prints the map showing all the dungeons

    LinkedList<Dugeon> getCalabozos(); // Returns the list of dungeons (calabozos)
};

#endif
