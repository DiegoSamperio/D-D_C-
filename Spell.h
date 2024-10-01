#ifndef PROYECTOESTRUCTURADATOS_SPELL_H
#define PROYECTOESTRUCTURADATOS_SPELL_H

#include <string>
#include <iostream>

using namespace std;

// Spell class representing magical spells in the game
class Spell {

private:
    string name; // Spell's name
    string info; // Description of the spell
    bool type; // Type of spell (e.g., offensive, defensive)
    int value; // Value or strength of the spell

public:
    // Constructor with parameters to initialize the spell's attributes
    Spell(string name, string info, bool type, int value);

    Spell(); // Default constructor

    void print() const; // Prints the spell's details

    // Overloading the << operator to print the spell's details
    friend ostream& operator<<(ostream& os, const Spell& p) {
        os << "Name: " << p.name << ", Description: " << p.info 
           << ", Type: " << p.type << ", Value: " << p.value << endl;
        return os;
    }

    // Overloading the == operator to compare spells by their name
    bool operator==(Spell p) {
        return this->name == p.name;
    }
};

#endif //PROYECTOESTRUCTURADATOS_SPELL_H