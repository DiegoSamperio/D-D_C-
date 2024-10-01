#include "Player.h"

// Constructor: Initializes the player with the given race and name
Player::Player(string raza, string nombre) : raza(raza), nombre(nombre) {}

// Returns the player's hit points
int Player::getHitP() {
    return hitP;
}

// Sets the player's hit points
void Player::setHitP(int hitP) {
    Player::hitP = hitP;
}

// Returns the player's life points (health)
int Player::getLifeP() {
    return lifeP;
}

// Sets the player's life points (health)
void Player::setLifeP(int lifeP) {
    Player::lifeP = lifeP;
}

// Returns the player's race
string Player::getRaza() {
    return raza;
}

// Sets the player's race
void Player::setRaza(string raza) {
    Player::raza = raza;
}

// Returns the player's name
string Player::getNombre() {
    return nombre;
}

// Sets the player's name
void Player::setNombre(string nombre) {
    Player::nombre = nombre;
}

// Returns the list of defeated monsters
LinkedList<Monster>& Player::getDerrotados() {
    return derrotados;
}

// Sets the list of defeated monsters
void Player::setDerrotados(LinkedList<Monster> derrotados) {
    Player::derrotados = derrotados;
}

// Destructor
Player::~Player() {}

// Default constructor
Player::Player() {}

// Sets the skills for an elf character
void Player::setElfSkills() {
    skills.addNode(Skill("elf", "renacimiento", "los elfos de morgana te dan su bendicion", "curacion", 20));
    skills.addNode(Skill("elf", "dragonite", "los elfos de parzival te dan su poder", "damage", 40));
    skills.addNode(Skill("elf", "principito", "los elfos del principe te dan su proteccion", "escudo", 20));
}

// Sets the skills for a human character
void Player::setHumanSkills() {
    skills.addNode(Skill("human", "cielo", "los humanos te dan su bondad", "curacion", 30));
    skills.addNode(Skill("human", "inferno", "los humanos te dan su maldad", "damage", 30));
    skills.addNode(Skill("human", "paz", "los humanos te dan su tranquilidad", "escudo", 20));
}

// Sets the skills for a dwarf character
void Player::setDwarfSkills() {
    skills.addNode(Skill("dwarf", "fortaleza", "los enanos te dan su fortaleza", "curacion", 30));
    skills.addNode(Skill("dwarf", "fuego", "los enanos te dan su fuerza", "damage", 40));
    skills.addNode(Skill("dwarf", "roca", "los enanos te dan su proteccion", "escudo", 20));
}

// Activates the player's shield
void Player::activarEscudo() {
    escudoActivado = true;
}

// Deactivates the player's shield
void Player::desactivarEscudo() {
    escudoActivado = false;
}

// Returns whether the shield is active
bool Player::isEscudoActivado() const {
    return escudoActivado;
}

// Sets the shield state
void Player::setEscudo(bool estado) {
    escudoActivado = estado;
}

// Returns the shield state
bool Player::getEscudo() const {
    return escudoActivado;
}

// Returns the player's skills
LinkedList<Skill> Player::getSkills() {
    return skills;
}