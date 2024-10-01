#include "Skill.h"

// Full constructor: Initializes a skill with all attributes
Skill::Skill(string name, string info, int duration, int value, int type, int status)
        : Name(name), Info(info), Duration(duration), value(value), type(type), status(status) {}

// Constructor for specific race and skill combinations
Skill::Skill(string raza, string nombre, string descripcion, string type, int value)
        : Name(raza + "_" + nombre), Info(descripcion), value(value), status(1) {

    // Determine the type of the skill based on the provided string
    if (type == "curacion") {
        this->type = 1; // Healing type
    } else if (type == "damage") {
        this->type = 2; // Damage type
    } else if (type == "escudo") {
        this->type = 3; // Shield type
    } else {
        // Handle error or set default if type is not recognized
        this->type = 0;  // Could also throw an exception
    }
}

// Returns the name of the skill
string Skill::getName() {
    return Name;
}

// Returns the description of the skill
string Skill::getInfo() {
    return Info;
}

// Returns the duration of the skill (if applicable)
int Skill::getDuration() {
    return Duration;
}

// Returns the value of the skill (e.g., damage or healing amount)
int Skill::getValue() {
    return value;
}

// Returns the type of the skill (1: healing, 2: damage, 3: shield)
int Skill::getType() {
    return type;
}

// Returns the status of the skill (active/inactive)
int Skill::getStatus() {
    return status;
}

// Sets the status of the skill (active/inactive)
void Skill::setStatus(int status) {
    this->status = status;
}

// Returns the race associated with the skill
string Skill::getRace() const {
    return race;
}

// Default constructor: Initializes the skill with default values
Skill::Skill() {
    Name = "";
    Info = "";
    Duration = 0;
    value = 20;
    type = 0;
    status = 1;
}