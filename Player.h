#ifndef PROYECTOESTRUCTURADATOS_PLAYER_H
#define PROYECTOESTRUCTURADATOS_PLAYER_H

#include "LinkedList.h"
#include "Monster.h"
#include <iostream>
#include "Skill.h"
using namespace std;

// Player class representing the user in the game
class Player {

private:
    int hitP = 10; // Player's hit points (attack power)
    int lifeP = 100; // Player's life points (health)
    string raza; // Player's selected race
    string nombre; // Player's name
    LinkedList<Monster> derrotados; // List of defeated monsters
    LinkedList<Skill> skills; // List of player's skills
    bool escudoActivado; // Flag indicating if the shield is active

public:
    Player(); // Default constructor

    // Constructor with race and name parameters
    Player(string raza, string nombre);

    virtual ~Player(); // Destructor

    int getHitP(); // Returns the player's hit points
    void setHitP(int hitP); // Sets the player's hit points

    int getLifeP(); // Returns the player's life points
    void setLifeP(int lifeP); // Sets the player's life points

    string getRaza(); // Returns the player's race
    void setRaza(string raza); // Sets the player's race

    string getNombre(); // Returns the player's name
    void setNombre(string nombre); // Sets the player's name

    LinkedList<Monster>& getDerrotados(); // Returns the list of defeated monsters
    void setDerrotados(LinkedList<Monster> derrotados); // Sets the list of defeated monsters

    LinkedList<Skill> getSkills(); // Returns the player's skills

    void setElfSkills(); // Sets the skills for an elf character
    void setHumanSkills(); // Sets the skills for a human character
    void setDwarfSkills(); // Sets the skills for a dwarf character

    void activarEscudo(); // Activates the player's shield
    void desactivarEscudo(); // Deactivates the player's shield

    bool isEscudoActivado() const; // Returns whether the shield is active
    void setEscudo(bool estado); // Sets the shield state
    bool getEscudo() const; // Returns the shield state
};

#endif