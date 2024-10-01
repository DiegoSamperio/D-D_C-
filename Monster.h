#ifndef PROYECTOESTRUCTURADATOS_MONSTER_H
#define PROYECTOESTRUCTURADATOS_MONSTER_H

#include <iostream>
using namespace std;

// Monster class representing a creature in the game
class Monster {
private:
    string name; // Monster's name
    float cr; // Challenge rating
    string type; // Monster's type (e.g., beast, undead)
    string size; // Monster's size (e.g., small, large)
    int ac; // Armor class
    int hp; // Hit points (health)
    string align; // Alignment (e.g., good, evil)

public:
    // Constructor with parameters to initialize the monster's attributes
    Monster(string name, float cr, string type, string size, int ac, int hp, string align);

    // Default constructor
    Monster();

    void print() const; // Prints the monster's details
    string getName(); // Returns the monster's name
    float getCr(); // Returns the monster's challenge rating
    string getType(); // Returns the monster's type
    string getSize(); // Returns the monster's size
    int getAc(); // Returns the monster's armor class
    int getHp(); // Returns the monster's hit points
    string getAlign(); // Returns the monster's alignment

    void setName(string name); // Sets the monster's name
    void setCr(float cr); // Sets the monster's challenge rating
    void setType(string type); // Sets the monster's type
    void setSize(string size); // Sets the monster's size
    void setAc(int ac); // Sets the monster's armor class
    void setHp(int hp); // Sets the monster's hit points
    void setAlign(string align); // Sets the monster's alignment

    // Overloading the << operator to print monster details
    friend ostream& operator<<(ostream& os, const Monster& p) {
        os << "Name: " << p.name << ", Challenge rating: " << p.cr << ", Type: " << p.type
           << ", Size: " << p.size << ", Armor class: " << p.ac << ", Hit points: " << p.hp
           << ", Alignment: " << p.align << endl;
        return os;
    }

    // Overloading the == operator to compare monsters by their name
    bool operator==(Monster p) {
        return this->name == p.name;
    }
};

#endif
