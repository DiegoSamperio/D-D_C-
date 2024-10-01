#ifndef PROYECTOESTRUCTURADATOSGAME_H
#define PROYECTOESTRUCTURADATOSGAME_H

#include <sstream>
#include "LinkedList.h"
#include "Node.h"
#include "Monster.h"
#include "Dado.h"
#include "Skill.h"
#include "Map.h"
#include "Dugeon.h"
#include "Spell.h"
#include "Player.h"

using namespace std;

class Game {
private:
    LinkedList<Skill> skills; // List of skills available in the game
    int choice; // Stores the player's current choice
    string currentRace; // Stores the player's selected race
    bool raza_elegida, juegoCurso; // Flags for race selection and ongoing game state
    string nametag; // Player's name
    vector<int> miVector; // Stores excluded dice rolls
    Map mapita; // Map of the game
    Player jugador; // Player object representing the user
    Dado dadito; // Dice object for rolling dice

public:
    Game(Map mapi); // Constructor to initialize the game with a map
    ~Game(); // Destructor to clean up resources
    void showSkillMenu(Dugeon &currentDungeon); // Displays the skill menu during the game
    void applySkill(Node<Skill>* skillNode, Dugeon &currentDungeon); // Applies the selected skill to the current dungeon
    void playerTurn(Dugeon &currentDungeon); // Handles the player's turn in a dungeon
    void showGameMenu(Dugeon &currentDungeon, int dado); // Displays the game menu for actions
    void Jugando(); // Main game loop
    void endGame(); // Ends the game and displays results
};

#endif
