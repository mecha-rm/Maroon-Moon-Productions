// Crew Member function definitions; This is NOT used in the final game.
// Originally, we planned to have crew members that the player could move around, and set to do specific tasks like fixing systems. These were ultimately cut from the final game.
#include "CrewMember.h"

// Default constructor
CrewMember::CrewMember() : CrewMember("Human", 'A') {}

// sets the species of the crew member. Make sure that all letters are lowercase.
CrewMember::CrewMember(std::string species, char room) : species(species) {}

//Setters
// The health of the crew member.
void CrewMember::setHealth(int health) { this->health = health; }
// The damage the crew member does.
void CrewMember::setDamage(int damage) { this->damage = damage; }
// Whether the crew member has oxygen or not. Rooms in FTL have oxygen levels that decrease in the prescence of hull breaches, which we intended to replicate.
void CrewMember::setOxygen(bool oxygen) { this->oxygen = oxygen; }
// The position of the crew member.
void CrewMember::setPosition(int position) { this->position = position; }
// The type of crew member; this refers to the job the crew member does on the ship (e.g. pilot, engine manager, laser manager, etc.) Almost any crew member can do any job.
void CrewMember::setCrewType(std::string crewType) { this->crewType = crewType; }
// Unique identification of the crew member.
void CrewMember::setID(int ID) { this->ID = ID; }
// The destination of the crew member when moving between rooms. This is set via a COORD, which holds both the 'x' and 'y' value.
void CrewMember::setDestination(COORD destination) { this->destination = destination; }
// The destination of the crew member when moving between rooms. This sets the 'x' and 'y' values indivdually.
void CrewMember::setDestination(int x, int y) { destination.X = x; destination.Y = y; }
// Setting the crew member's current location with a COORD (think of it like a Vec2 class).
void CrewMember::setCurrent(COORD current) { this->current = current; }
// Setting the crew member's current location with individual points.
void CrewMember::setCurrent(int x, int y) { current.X = x, current.Y = y; }

//Getters
// Returns the species of the crew member. Different species have different stats and perks.
std::string CrewMember::getSpecies() { return species; }
// The health of the crew member.
int CrewMember::getHealth() { return health; }
// The amount of damage the crew member does.
int CrewMember::getDamage() { return damage; }
// Whether the crew member has oxygen or not. 
bool CrewMember::getOxygen() { return oxygen; }
// The crew member's current position.
int CrewMember::getPosition() { return position; }
// The job the crew member serves on the ship.
std::string CrewMember::getCrewType() { return crewType; }
// Unique identification of the crew member.
int CrewMember::getID() { return ID; }
// The destination of the crew member when moving.
COORD CrewMember::getDestination() { return destination; }
// The current position of the crew member.
COORD CrewMember::getCurrent() { return current; }





