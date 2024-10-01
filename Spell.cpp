#include "Spell.h"

// Constructor: Initializes a spell with the given name, description, type, and value
Spell::Spell(string name, string info, bool type, int value) 
    : name(name), info(info), type(type), value(value) {}

// Default constructor: Initializes a spell with default values
Spell::Spell() {}

// Prints the spell's details (name and description)
void Spell::print() const {
    cout << "Spell: " << name << " (Description: " << info << ")" << endl;
}