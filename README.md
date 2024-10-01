# Dungeons & Dragons Game in C++

## Overview
This project is a C++ implementation of a Dungeons & Dragons-inspired game where players can choose from three races: Elf, Human, or Dwarf. Each race has unique abilities, and the player will explore dungeons, encounter monsters, and use various skills to defeat them.

The game offers a text-based interactive experience, where the player can:
- Select a race and customize the character
- Roll dice to enter random dungeons
- Fight different monsters
- Use unique race-based skills such as healing, damage, and shield abilities
- Defeat monsters and track progress

## Features
- **Race Selection**: Choose between Elf, Human, or Dwarf, each with unique skills.
- **Dungeon Exploration**: Randomly generated dungeons based on dice rolls.
- **Combat System**: Turn-based combat where players can roll dice and use skills.
- **Skill System**: Each race has different abilities for healing, damaging enemies, or protecting with shields.
- **Monster Defeating**: Monsters have different stats and can be defeated to progress through the game.

## Getting Started
### Prerequisites
- C++ compiler (e.g., g++, clang)
- Command-line interface (CLI) to run the game

### How to Play
1. Clone this repository:
    ```bash
    git clone https://github.com/DiegoSamperio/dungeons-dragons-cpp.git
    ```
2. Navigate to the project directory:
    ```bash
    cd dungeons-dragons-cpp
    ```
3. Compile the game using your C++ compiler:
    ```bash
    g++ main.cpp -o game
    ```
4. Run the game:
    ```bash
    ./game
    ```

### Gameplay Instructions
1. Enter your character's name.
2. Choose a race: Elf, Human, or Dwarf.
3. Roll dice to enter random dungeons.
4. Fight monsters using dice rolls and skills.
5. Heal, protect yourself, or deal damage using race-specific skills.
6. Defeat monsters and continue exploring dungeons until your health runs out.

## File Structure
- **Game.h / Game.cpp**: Handles game initialization, combat, and player interactions.
- **Player.h / Player.cpp**: Manages player attributes, skills, and actions.
- **Monster.h / Monster.cpp**: Defines the monsters and their characteristics.
- **Skill.h / Skill.cpp**: Manages the skills for each race.
- **Dugeon.h / Dugeon.cpp**: Represents the dungeons in the game.
- **Map.h / Map.cpp**: Handles the map generation and dungeon assignments.
- **LinkedList.h / LinkedList.cpp**: Implements a linked list to manage the game objects.
- **Node.h / Node.cpp**: Defines the node structure for the linked list.

## Future Enhancements
- Add more races with unique abilities.
- Implement a graphical interface.
- Introduce more monsters and spells to increase variety.
- Add multiplayer functionality.

## Last Modification
This project was last modified on **December 1, 2023**.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Credits
Developed by Diego Samperio and Santiago Calderón as part of a C++ programming project.
