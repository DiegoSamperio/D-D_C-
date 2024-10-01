#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Monster.h"
#include "Spell.h"
#include "Map.h"
#include "Game.h"

using namespace std;

int main() {
    // Open the CSV file containing monster data
    ifstream archivo_monsters("C:\\Users\\santi\\CLionProjects\\ProyectoEstructuraDatos\\monsters_patched.csv");
    
    // Open the CSV file containing spell data
    ifstream archivo_spells("C:\\Users\\santi\\CLionProjects\\ProyectoEstructuraDatos\\Spells.csv");

    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Check if the monster file opened successfully
    if (!archivo_monsters.is_open()) {
        cerr << "Error opening monsters_patched.csv." << endl;
        return 1;
    }

    // Check if the spell file opened successfully
    if (!archivo_spells.is_open()) {
        cerr << "Error opening Spells.csv." << endl;
        return 1;
    }

    LinkedList<Monster> Monsterlist; // Linked list to store monsters
    LinkedList<Spell> Spelllist; // Linked list to store spells

    string linea;
    char delimitador = ',';

    // Read monsters from the file
    getline(archivo_monsters, linea); // Discard the header row

    while (getline(archivo_monsters, linea)) {
        stringstream stream(linea);

        string name, cr, type, size, ac, hp, align;

        getline(stream, name, delimitador);
        getline(stream, cr, delimitador);
        getline(stream, type, delimitador);
        getline(stream, size, delimitador);
        getline(stream, ac, delimitador);
        getline(stream, hp, delimitador);
        getline(stream, align, delimitador);

        // Convert the string values to their appropriate types
        float crx = stof(cr); // Convert Challenge Rating to float
        int acx = stoi(ac); // Convert Armor Class to integer
        int hpx = stoi(hp); // Convert Hit Points to integer

        // Add a new Monster object to the list
        Monsterlist.addNode(Monster(name, crx, type, size, acx, hpx, align));
    }

    archivo_monsters.close(); // Close the monster file

    string lineaa;
    getline(archivo_spells, lineaa); // Discard the header row for spells

    // Read spells from the file
    while (getline(archivo_spells, lineaa)) {
        stringstream streeam(lineaa);

        string name, info, type, value;

        getline(streeam, name, delimitador);
        getline(streeam, info, delimitador);
        getline(streeam, type, delimitador);
        getline(streeam, value, delimitador);
        int valor = stoi(value); // Convert value to integer
        bool tipo = (type == "1"); // Convert type to boolean (true if "1", false if "0")

        // Add a new Spell object to the list
        Spelllist.addNode(Spell(name, info, tipo, valor));
    }

    archivo_spells.close(); // Close the spell file

    // Create the map with the list of monsters and spells
    Map mapita(20, Monsterlist, Spelllist);

    // Start the game with the created map
    Game juego(mapita);
}
