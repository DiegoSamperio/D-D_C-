#include "Monster.h"

// Constructor: Initializes a monster with the given attributes
Monster::Monster(string name, float cr, string type, string size, int ac, int hp, string align) {
    this->name = name;
    this->cr = cr;
    this->type = type;
    this->size = size;
    this->ac = ac;
    this->hp = hp;
    this->align = align;
}

// Default constructor: Initializes a monster with default values
Monster::Monster() {
    this->name = "";
    this->cr = 0;
    this->type = "";
    this->size = "";
    this->ac = 0;
    this->hp = 0;
    this->align = "";
}

// Prints the monster's details (name, type, size, and hit points)
void Monster::print() const {
    cout << "                               Monster: " << name << " (Type: " << type 
         << " | Size: " << size << " | HP: " << hp << ")" << endl;
}

// Getter and setter methods for each attribute of the monster
string Monster::getName() {
    return name;
}

void Monster::setName(string nombre) {
    Monster::name = nombre;
}

float Monster::getCr() {
    return cr;
}

void Monster::setCr(float cr) {
    Monster::cr = cr;
}

string Monster::getType() {
    return type;
}

void Monster::setType(string type) {
    Monster::type = type;
}

string Monster::getSize() {
    return size;
}

void Monster::setSize(string size) {
    Monster::size = size;
}

int Monster::getAc() {
    return ac;
}

void Monster::setAc(int ac) {
    Monster::ac = ac;
}

int Monster::getHp() {
    return hp;
}

void Monster::setHp(int hp) {
    this->hp = hp;
}

string Monster::getAlign() {
    return align;
}

void Monster::setAlign(string align) {
    Monster::align = align;
}
