#include "Dugeon.h"

// Returns the dungeon's name/identifier
int Dugeon::getName() {
    return Name;
}

// Sets the dungeon's name/identifier
void Dugeon::setName(int name) {
    Name = name;
}

// Returns the monster in the dungeon
Monster& Dugeon::getMonstruo() {
    return monstruo;
}

// Sets the monster for the dungeon
void Dugeon::setMonstruo(Monster monstruo) {
    Dugeon::monstruo = monstruo;
}

// Constructor that initializes the dungeon with a name, a monster, and a spell
Dugeon::Dugeon(int name, Monster monstruo, Spell spell) : Name(name), monstruo(monstruo), spell(spell) {}

// Default constructor initializing the dungeon with default values
Dugeon::Dugeon() {
    Name = 0;
    monstruo = Monster();
}

// Prints the dungeon's name, monster, and spell details
void Dugeon::print() {
    cout << "Dungeon: " << Name << ", ";
    monstruo.print();
    spell.print();
}

// Returns the spell in the dungeon
Spell Dugeon::getSpell() {
    return spell;
}

// Sets the spell for the dungeon
void Dugeon::setSpell(Spell spell) {
    Dugeon::spell = spell;
}