#include "Pokemon.h"
#include <iostream>
using namespace std;

// Name: Pokemon
    // Desc - Default Constructor
    // Preconditions - None
    // Postconditions - Creates Pokemon with default values
Pokemon::Pokemon(){
    m_index = 0;
    m_health = 0;
    m_name = "";
    m_type = "";
    m_strong = "";
}

// Name: Pokemon(int, string, string, string)
    // Desc - Overloaded Constructor
    // Preconditions - Have index, name, type, and what the Pokemon is strong against
    // Postconditions - Creates Pokemon using passed values
Pokemon::Pokemon(int index, string name, string type, string strength) {
    m_index = index; 
    m_name = name;
    m_type = type;
    m_strong = strength;
    m_health = MAX_HEALTH;
}

// Name: GetNext
    // Desc - Returns pointer to the next pokemon
    // Preconditions - Pokemon exists
    // Postconditions - Returns pointer to next pokemon in linked list
// may be issues here not sure 
Pokemon* Pokemon::GetNext() { return m_next; }

// Name: GetName
    // Desc - Returns Name
    // Preconditions - Pokemon exists
    // Postconditions - Returns name of Pokemon
string Pokemon::GetName() { return m_name; }

// Name: GetIndex
    // Desc - Returns index
    // Preconditions - Pokemon exists
    // Postconditions - Returns index of Pokemon
int Pokemon::GetIndex() { return m_index; }

// Name: GetType
    // Desc - Returns type
    // Preconditions - Pokemon exists
    // Postconditions - Returns type of Pokemon
string Pokemon::GetType() { return m_type; }

// Name: GetHealth
    // Desc - Returns health
    // Preconditions - Pokemon exists
    // Postconditions - Returns health of Pokemon
int Pokemon::GetHealth() { return m_health; }

// Name: GetStrong
    // Desc - Returns type of Pokemon this Pokemon is strong against
    // Preconditions - Pokemon exists
    // Postconditions - Returns type of Pokemon this Pokemon is strong against
string Pokemon::GetStrong() { return m_strong; }

// Name: SetHealth
    // Desc - Sets health of pokemon
    // Preconditions - Pokemon exists
    // Postconditions - Updates health of Pokemon
void Pokemon::SetHealth(int newHealth) { m_health = newHealth; }

// Name: SetNext
    // Desc - Sets the pointer to the next Pokemon in the list
    // Preconditions - Pokemon exists
    // Postconditions - Sets the pointer to the next Pokemon
void Pokemon::SetNext(Pokemon* current) { m_next = current; }

// Name: Overloaded << Operator
    // Desc - Allows us to cout a Pokemon object
    // Preconditions - Pokemon exists
    // Postconditions - When a Pokemon object is cout, shows name, health, and type


ostream& operator<<(ostream& output, Pokemon& P) {
    return output << P.GetName() << " (" << P.GetType() 
        << ": " << P.GetHealth() << " health)";
}

/* string m_name; //Name of Pokemon
    int m_index; //Index of Pokemon
    string m_type; //Type of Pokemon
    string m_strong; //Type of Pokemon this Pokemon is strong against (5 damage)
    int m_health; //Health of Pokemon
    Pokemon* m_next = nullptr; //Pointer to next Pokemon in list*/
