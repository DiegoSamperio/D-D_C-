#include "Map.h"

// Constructor: Creates a map with 'num' dungeons, randomly assigning monsters and spells to each dungeon
Map::Map(int num, LinkedList<Monster> disponibles, LinkedList<Spell> SpeDisponibles) {
    for (int i = 0; i < num; i++) {

        // Check if there are still monsters and spells available
        if (disponibles.size() > 0 && SpeDisponibles.size() > 0) {
            // Get a random monster from the available list
            int randomPositionM = rand() % disponibles.size();
            int randomPositionS = rand() % SpeDisponibles.size();

            Node<Monster>* randomMonsterNode = disponibles.findAtPos(randomPositionM);
            Monster randomMonster = randomMonsterNode->getData();

            Node<Spell>* randomSpellNode = SpeDisponibles.findAtPos(randomPositionS);
            Spell randomSpell = randomSpellNode->getData();

            // Remove the monster and spell from their respective lists
            disponibles.removeNodeAt(disponibles.findNode(randomMonster));
            SpeDisponibles.removeNodeAt(SpeDisponibles.findNode(randomSpell));

            // Create a dungeon with the random monster and spell, and add it to the list of dungeons
            Calabozos.addNode(Dugeon(i, randomMonster, randomSpell));
        } else {
            // Handle the case when there are no more monsters or spells available
            cout << "No more monsters available to assign to dungeons." << endl;
            break;
        }
    }
}

// Prints the entire map, showing each dungeon and its contents
void Map::printMap() {
    cout << "Game Map:" << endl;
    cout << "-----------------" << endl;
    Node<Dugeon>* current = Calabozos.getFirst();

    // Loop through all dungeons and print their details
    while (current) {
        current->getData().print();  // Call the print method of each dungeon
        cout << "-----------------" << endl;
        current = current->getNext();
    }
}

// Default constructor
Map::Map() {}

// Returns the list of dungeons (calabozos)
LinkedList<Dugeon> Map::getCalabozos() {
    return Calabozos;
}