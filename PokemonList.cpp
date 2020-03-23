#include "PokemonList.h"
#include <iostream>
using namespace std;

// Name: PokemonList
    // Desc - Default constructor for the PokemonList (linked list)
    // Preconditions - None
    // Postconditions - Creates an empty PokemonList (linked list)
PokemonList::PokemonList() {}

// Name: ~PokemonList
    // Desc - Destructor for the PokemonList (linked list)
    // Preconditions - None
    // Postconditions - Clears out a PokemonList (linked list)
PokemonList::~PokemonList(){}

// Name: InsertEnd
    // Desc - Inserts an already dynamically allocated Pokemon to end of linked list
    // Preconditions - PokemonList already created
    // Postconditions - The passed Pokemon appears at the end of the list
void PokemonList::InsertEnd(Pokemon*){}

// Name: Display
    // Desc - Iterates over PokemonList and displays each Pokemon formatted as in output
    // Preconditions - PokemonList already created and has Pokemon
    // Postconditions - Displayed Pokemon information
void PokemonList::Display(){}

// Name: Transfer
    // Desc - Searches for a Pokemon with a specific index. If found,
    // creates a new Pokemon and copies it into the PokemonList passed in
    // Preconditions - int is the index of the desired Pokemon and
    // PokemonList is the destination
    // Postconditions - Adds new Pokemon to the destination list and removes it from
    // the source
void PokemonList::Transfer(int, PokemonList*){}

// Name: Remove (int)
    // Desc - Searches for a Pokemon with a specific index. If found,
    // removes it from the linked list
    // Preconditions - int is the index of the desired Pokemon
    // Postconditions - Removes Pokemon from linked list
void PokemonList::Remove(int){}

// Name: GetSize
    // Desc - Returns the size of the linked list
    // Preconditions - PokemonList is populated with Pokemon
    // Postconditions - Returns the size of the linked list
//int PokemonList::GetSize(){}

// Name: GetHead
    // Desc - Returns the Pokemon at the head of the linked list
    // Preconditions - PokemonList is populated with Pokemon
    // Postconditions - Returns the Pokemon at the head of the linked list
//Pokemon* PokemonList::GetHead(){}

// Name: Attack(PokemonList)
    // Desc - Passes an enemy pocket to the user's pocket to attack
    // User always attacks the enemy Pokemon in this game
    // Preconditions - This list is populated and enemy list is populated
    // Postconditions - Does damage to the user Pokemon and enemy Pokemon
    // and updates their health. Returns 2 if enemy Pokemon is less than 0
    // Returns 2 if user's health is less than 0 else returns 0.
//int PokemonList::Attack(PokemonList*){}

// Name: SwapPokemon
    // Desc - Allows user to move a Pokemon from any position into the first position
    // Special cases: Empty list, Pokemon chosen at m_head or choice doesn't exist
    // Preconditions - Linked list is populated
    // Postconditions - User selects a Pokemon and it is moved into the first position
void PokemonList::SwapPokemon(){}

// Name: Exist(int)
    // Desc - Iterates through linked list looking for a specific index of a Pokemon
    // Preconditions - PokemonList is populated with Pokemon
    // Postconditions - Returns true if found else false
//bool PokemonList::Exist(int){}

/*private:
    Pokemon* m_head; //Node pointer pointing to first node in linked list
    int m_size; //Size of the linked list*/
