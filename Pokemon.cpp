/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 3, Spring 2020
** Author:  Rooklyn Kline
** Date:    4/02/20
** Section: 02
** E-mail:  rkline2@umbc.edu
**
** This file contains functions that 
** sets and gets the Pokemons' attributes. These are not 
** limited to the name, type, index, health, etc.
** It also contains the insertion operator overload that is  
** used to print a Pokemon object in the game.
**
***********************************************/
#include "Pokemon.h"
#include <iostream>
using namespace std;

// Name: Pokemon Constructor
    // Creates Pokemon with default values
Pokemon::Pokemon(){
    m_index = 0;
    m_health = 0;
    m_name = "";
    m_type = "";
    m_strong = "";
}

// Pokemon(int, string, string, string)
    // Given the index, name, type and strength, creates a Pokemon using passed values
Pokemon::Pokemon(int index, string name, string type, string strength) {
    m_index = index; 
    m_name = name;
    m_type = type;
    m_strong = strength;
    m_health = MAX_HEALTH;
}

// GetNext
    // Returns pointer to next pokemon in linked list 
Pokemon* Pokemon::GetNext() { return m_next; }

// GetName
    // Returns name of Pokemon
string Pokemon::GetName() { return m_name; }

// GetIndex
    // Returns index of Pokemon
int Pokemon::GetIndex() { return m_index; }

// GetType
    // Returns type of Pokemon
string Pokemon::GetType() { return m_type; }

// GetHealth
    // Returns health of Pokemon
int Pokemon::GetHealth() { return m_health; }

// GetStrong
    // Returns type of Pokemon this Pokemon is strong against
string Pokemon::GetStrong() { return m_strong; }

// SetHealth
    // Given the new health value, updates health of Pokemon
void Pokemon::SetHealth(int newHealth) { m_health = newHealth; }

// SetNext
    // Given the current pointer, sets the pointer to the next Pokemon
void Pokemon::SetNext(Pokemon* current) { m_next = current; }

// Overloaded << Operator
    // A Pokemon object shows name, health, and type
ostream& operator<<(ostream& output, Pokemon& P) {
    return output << P.GetName() << " (" << P.GetType() 
        << ": " << P.GetHealth() << " health)";
}
