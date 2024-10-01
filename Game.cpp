#include "Game.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor: Initializes the game with a map and handles player race selection
Game::Game(Map mapi) : raza_elegida(false), juegoCurso(true) {
    mapita = mapi;

    // Display welcome message and prompt for player name
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------BIENVENIDO AL JUEGO DE D & G-----------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "Ingresa tu nombre: ";
    cin >> nametag;

    // Loop for selecting the player's race
    while (!raza_elegida) {
        cout << "Si estas listo para esta aventura por favor ingresa el numero de la raza que quieres ser:" << endl;
        cout << "        1. Elfo" << endl;
        cout << "        2. Humano" << endl;
        cout << "        3. Enano" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                currentRace = "elf";
                jugador = Player("elf", nametag);
                jugador.setElfSkills(); // Set elf skills
                raza_elegida = true;
                break;
            case 2:
                currentRace = "human";
                jugador = Player("human", nametag);
                jugador.setHumanSkills(); // Set human skills
                raza_elegida = true;
                break;
            case 3:
                currentRace = "dwarf";
                jugador = Player("dwarf", nametag);
                jugador.setDwarfSkills(); // Set dwarf skills
                raza_elegida = true;
                break;
            default:
                cout << "Opcion no valida. Intentelo de nuevo." << endl;
        }
    }
    cout << "Que comience la caza!" << endl;
    Jugando(); // Start the game
}

// Main game loop: Handles player actions and interactions with dungeons
void Game::Jugando() {
    while (jugador.getLifeP() > 0 && juegoCurso) {
        int dungeonRoll = dadito.lanzarDadoConExclusion(dadito, miVector); // Roll a 20-sided dice
        Dugeon currentDungeon = mapita.getCalabozos().findAtPos(dungeonRoll)->getData(); // Get dungeon based on dice roll
        cout << "Lanzas un dado de 20 caras, obtienes un " << dungeonRoll << "." << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "Ahora visitas ese calabozo ...." << endl;

        // Check if the monster in the dungeon is still alive
        if (currentDungeon.getMonstruo().getHp() > 0) {
            // Start combat
            cout << "                        Enfrentas a" << endl;
            currentDungeon.getMonstruo().print();

            showGameMenu(currentDungeon, dungeonRoll); // Show combat menu
            jugador.setEscudo(false); // Deactivate player's shield after combat

        } else {
            cout << "Este calabozo está vacio, continua tu aventura." << endl;
        }

        // Healing phase: Roll an 8-sided dice for healing
        int healingRoll = dadito.tirar(8);
        jugador.setLifeP(jugador.getLifeP() + healingRoll); // Heal the player
        cout << "Tiras un dado de 8 caras para curacion y obtienes un " << healingRoll << ". Tu vida ahora es "
             << jugador.getLifeP() << "." << endl;
        jugador.setEscudo(false); // Deactivate shield after healing
    }
}

// Destructor: Cleans up resources if needed
Game::~Game() {
    // Clean up if necessary
}

// Displays the game menu with options during combat
void Game::showGameMenu(Dugeon &currentDungeon, int dado) {
    while (jugador.getLifeP() > 0 && currentDungeon.getMonstruo().getHp() > 0) {
        cout << "Ingrese el numero de su eleccion: " << endl;
        cout << "        1. Tirar dado" << endl;
        cout << "        2. Usar habilidad" << endl;
        cout << "        3. Abandonar partida" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                playerTurn(currentDungeon); // Player's attack turn
                break;
            case 2:
                showSkillMenu(currentDungeon); // Show skills to use
                break;
            case 3:
                cout << "Abandonar partida. Programa terminado." << endl;
                endGame(); // End the game
                juegoCurso = false;
                currentDungeon.getMonstruo().setHp(0); // Exit the game
                return;
            default:
                cout << "Opcion no valida. Intentelo de nuevo." << endl;
                showGameMenu(currentDungeon, dado); // Show the menu again if the input is invalid
                break;
        }
    }

    if (jugador.getLifeP() > 0) {
        // Player wins the battle
        jugador.getDerrotados().addNode(currentDungeon.getMonstruo());
        cout << "Has derrotado al monstruo!" << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        miVector.push_back(dado); // Add dungeon number to exclusion list
        jugador.setEscudo(false); // Deactivate shield
    } else {
        cout << "Has sido derrotado!" << endl;
        endGame(); // End the game if the player dies
    }
}

// Handles the player's turn to attack the monster
void Game::playerTurn(Dugeon &currentDungeon) {
    // Monster attacks
    if (!jugador.getEscudo()) {  // If the player's shield is not active
        int monsterAttack = dadito.tirar(10); // Monster's attack damage
        cout << setw(100) << right << "El monstruo ataca y te hace " << monsterAttack << " de danho." << endl;
        jugador.setLifeP(jugador.getLifeP() - monsterAttack); // Reduce player's life points
    } else {
        cout << setw(100) << right << "El escudo te protege del ataque del monstruo." << endl;
    }

    // Player attacks
    int playerAttack = dadito.tirar(10); // Player's attack damage
    cout << "Atacas al monstruo y le haces " << playerAttack << " de danho." << endl;
    currentDungeon.getMonstruo().setHp(currentDungeon.getMonstruo().getHp() - playerAttack); // Reduce monster's life points

    // Display remaining life points for both the player and the monster
    cout << "Tu vida restante: " << jugador.getLifeP() << endl;
    cout << setw(100) << right << "Vida restante del monstruo: " << currentDungeon.getMonstruo().getHp() << endl;
}

// Displays the skill menu for the player to choose a skill during combat
void Game::showSkillMenu(Dugeon &currentDungeon) {
    cout << "Selecciona una habilidad:" << endl;

    LinkedList<Skill> filteredSkills = jugador.getSkills(); // Get the player's available skills

    // Display the available skills
    filteredSkills.print();

    int skillChoice;
    cin >> skillChoice;

    if (skillChoice >= 1 && skillChoice <= filteredSkills.size()) {
        applySkill(filteredSkills.findAtPos(skillChoice - 1), currentDungeon); // Apply the selected skill
    } else {
        cout << "Opcion no valida. Intentalo de nuevo." << endl;
        showSkillMenu(currentDungeon); // Show the skill menu again if input is invalid
    }
}

// Applies the selected skill during combat
void Game::applySkill(Node<Skill>* skillNode, Dugeon &currentDungeon) {
    Skill skill = skillNode->getData();
    cout << "Has usado la habilidad: " << skill.getName() << " - " << skill.getInfo() << endl;

    switch (skill.getType()) {
        case 1:  // Healing skill
            jugador.setLifeP(jugador.getLifeP() + skill.getValue());
            cout << "Te has curado " << skill.getValue() << " puntos de vida." << endl;
            cout << "Vida: " << jugador.getLifeP() << endl;
            break;
        case 2:  // Damage skill
            currentDungeon.getMonstruo().setHp(currentDungeon.getMonstruo().getHp() - skill.getValue());
            cout << "Has infligido " << skill.getValue() << " puntos de danho al monstruo." << endl;
            cout << "Vida mounstro: " << currentDungeon.getMonstruo().getHp() << endl;
            break;
        case 3:  // Shield skill
            jugador.setEscudo(true);  // Activate player's shield
            cout << "Has activado un escudo. No recibirás daño en este calabozo." << endl;
            break;
        default:
            cout << "Habilidad no reconocida." << endl;
            break;
    }
}

// Ends the game and displays results
void Game::endGame() {
    cout << "Fin del juego! " << endl;

    if (jugador.getDerrotados().size() > 0) {
        cout << "Derrotaste a estos Mounstros: " << endl;
        jugador.getDerrotados().print(); // Print the list of defeated monsters
    } else {
        cout << "No pudiste derrotar a ningun mounstro." << endl;
    }
}