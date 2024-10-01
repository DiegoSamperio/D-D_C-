#ifndef PROYECTOESTRUCTURADATOS_SKILL_H
#define PROYECTOESTRUCTURADATOS_SKILL_H

#include <string>
#include <iostream>
#include "Node.h"
using namespace std;

// Skill class representing abilities the player can use in the game
class Skill {
private:
    string Name; // Skill name
    string Info; // Description of the skill
    string race; // Race associated with the skill
    int value; // Value of the skill (e.g., damage, healing)
    int type; // Type of the skill (e.g., healing, damage, shield)
    int Duration; // Duration of the skill (if applicable)
    int status; // Status of the skill (e.g., active/inactive)

public:
    int getStatus(); // Returns the status of the skill
    void setStatus(int status); // Sets the status of the skill
    string getName(); // Returns the name of the skill
    string getInfo(); // Returns the description of the skill
    string getRace() const; // Returns the race associated with the skill
    int getDuration(); // Returns the duration of the skill
    int getValue(); // Returns the value of the skill
    int getType(); // Returns the type of the skill (e.g., healing, damage)

    // Constructor with full parameters
    Skill(string name, string info, int duration, int value, int type, int status);

    // Constructor for specific race and skill combinations
    Skill(string raza, string nombre, string descripcion, string type, int value);

    Skill(); // Default constructor

    // Overloading the << operator to print skill details
    friend ostream& operator<<(ostream& os, const Skill& p) {
        if (p.type == 1) {
            os << "       [1] Skill " << p.Name << ", Info: " << p.Info 
               << ", Value: " << p.value << ", Type: " << "Healing" << endl;
        } else if (p.type == 2) {
            os << "       [2] Skill " << p.Name << ", Info: " << p.Info 
               << ", Value: " << p.value << ", Type: " << "Damage" << endl;
        } else {
            os << "       [3] Skill " << p.Name << ", Info: " << p.Info 
               << ", Value: " << p.value << ", Type: " << "Shield" << endl;
        }
        return os;
    }

    // Overloading the == operator to compare skills by their name
    bool operator==(Skill p) {
        return this->Name == p.Name;
    }
};

#endif