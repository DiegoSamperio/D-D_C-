#ifndef PROYECTOESTRUCTURADATOS_DUGEON_H
#define PROYECTOESTRUCTURADATOS_DUGEON_H

#include <string>
#include "Monster.h"
#include "Spell.h"

using namespace std;

class Dugeon {
private:
    int Name; // Dungeon identifier
    Monster monstruo; // Monster associated with the dungeon
    Spell spell; // Spell associated with the dungeon

public:
    int getName(); // Returns the dungeon's name/identifier

    void print(); // Prints dungeon details (name, monster, and spell)

    // Constructor that initializes dungeon with name, monster, and spell
    Dugeon(int name, Monster monstruo, Spell spell);

    // Default constructor
    Dugeon();

    void setName(int name); // Sets the dungeon's name/identifier

    Monster& getMonstruo(); // Returns the monster in the dungeon

    void setMonstruo(Monster monstruo); // Sets the monster for the dungeon

    Spell getSpell(); // Returns the spell in the dungeon

    void setSpell(Spell spell); // Sets the spell for the dungeon

    // Overloading the << operator to print dungeon details
    friend ostream& operator<<(ostream& os, const Dugeon& p) {
        os << "Dungeon #: " << p.Name << ", Monster: " << p.monstruo << endl;
        return os;
    }

    // Overloading the == operator to compare two dungeons by their name/identifier
    bool operator==(Dugeon p) {
        return this->Name == p.Name;
    }
};

#endif //PROYECTOESTRUCTURADATOS_DUGEON_H
