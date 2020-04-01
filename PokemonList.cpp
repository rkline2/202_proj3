/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 3, Spring 2020
** Author:  Rooklyn Kline
** Date:    4/02/20
** Section: 02
** E-mail:  rkline2@umbc.edu
**
** This file contains functions that modify the 
** Pokemon List for both the user and the CPU. 
** Some of these modifications include inserting, 
** removing, transfering a Pokemon from a linked list.
** The file also contains the attack function which 
** modifies the Pokemon's hp.
**
***********************************************/
#include "PokemonList.h"
#include <iostream>
using namespace std;

// PokemonList Constructor
    // Creates an empty PokemonList (linked list)
PokemonList::PokemonList() {
    m_head = nullptr;
    m_size = 0;
}

// ~PokemonList Destructor
    // Clears out a PokemonList (linked list)
PokemonList::~PokemonList() {
    Pokemon* curr = m_head;
    while (curr != NULL) {
        Pokemon* temp = curr->GetNext();
        delete curr;
        curr = temp;
    }
}

// InsertEnd
    // Postconditions - Given the passed Pokemon, the Pokemon appears at the end of the list
void PokemonList::InsertEnd(Pokemon* newPokemon){
    Pokemon* curr = m_head;

    if (curr == nullptr){
        m_head = newPokemon;
        m_size++;
    }
    else {
        while (curr->GetNext() != NULL) {
            curr = curr->GetNext();
        }
        curr->SetNext(newPokemon);
        newPokemon->SetNext(nullptr);
        m_size++;
    }
    
}

// Display
    // Displays Pokemon's attributes 
void PokemonList::Display(){
    Pokemon* tp = m_head;
    while (tp != NULL) {
       
        int index = tp->GetIndex();
        string name = tp->GetName();
        string type = tp->GetType();
        int health = tp->GetHealth();
        int nameSize = name.size();
        int typeSize = type.size();
        
        cout << "Index: " << setw(NUM_SPACE) << index << " ";
        cout << "Name: "<< tp->GetName();
        // for-loop here for space
        for (int i = 0; i <= (MAX_NAMESP - nameSize); i++) {
            cout << " ";
        }
        cout << "Type: " << tp->GetType();
        // for-loop here for space
        for (int i = 0; i <= (MAX_TYPESP - typeSize); i++) {
            cout << " ";
        }
        cout << "Health: " << tp->GetHealth();
        cout << endl;
        tp = tp->GetNext();
    }
}

// Transfer
    // Given the index and Pokemon list, adds new Pokemon 
    // to the destination list and removes it from the source
void PokemonList::Transfer(int askIndex, PokemonList* userPkt){
    Pokemon* curr = m_head;
    Pokemon* newPoki;
    while (curr->GetIndex() != askIndex) {
        curr = curr->GetNext();
    }
    newPoki = new Pokemon(curr->GetIndex(), curr->GetName(), curr->GetType(), curr->GetStrong());
    userPkt->InsertEnd(newPoki);
    // removes the pokemon from m_list
    Remove(askIndex);
}

// Remove 
    // Given the index, removes Pokemon from linked list
void PokemonList::Remove(int pokiIndex){
    Pokemon* curr = m_head;
    Pokemon* prev = m_head;
    // if the Pokemon is at the beginning of the list
    if(curr->GetIndex() == pokiIndex){
        m_head = m_head->GetNext();
        delete curr; 
    }
    else {
        // sorts through the linked list
        while (curr->GetIndex() != pokiIndex) {
            prev = curr;
            curr = curr->GetNext();
        }
        // if the Pokemon is at the end of the list
        if (curr->GetNext() == NULL) {
            prev->SetNext(nullptr);
            delete curr;
        }
        else {
            prev->SetNext(curr->GetNext());
            delete curr;
        }
        
    }
}

// GetSize
    // Returns the size of the linked list
int PokemonList::GetSize() { return m_size; }

// GetHead
    // Returns the Pokemon at the head of the linked list
Pokemon* PokemonList::GetHead() { return m_head; }

// Attack
    // Given the enemy list, does damage to the user Pokemon and enemy Pokemon
    // and updates their health. Returns 2 if enemy Pokemon is less than 0
    // Returns 1 if user's health is less than 0 else returns 0.
int PokemonList::Attack(PokemonList*cpuPoki) {
    Pokemon* cpuHead = cpuPoki->GetHead();
    int cpuHealth = cpuHead->GetHealth();
    int usrHealth = m_head->GetHealth();

    cout << m_head->GetName() << " attacks " << cpuHead->GetName() << "!" << endl;

    // If usr poki is strong against cpu poki and cpu poki is strong against usr poki 
    if (m_head->GetStrong() == cpuHead->GetType() && 
        cpuHead->GetStrong() == m_head->GetType()) {
        cout << "It's super effective!" << endl;

        // Changes the CPU's Pokemon health 
        cpuHead->SetHealth(cpuHealth - STRONG_DAMAGE);

        // Does nothing if the CPU's Poki is K.O.
        if (cpuHead->GetHealth() <= 0) {}
        
        else {
            cout << cpuHead->GetName() << " attacks ";
            cout << m_head->GetName() << "!" << endl;

            cout << "It's super effective!" << endl;

            // Changes the user's Pokemon health 
            m_head->SetHealth(usrHealth - STRONG_DAMAGE);
        }
    
    }

    // If usr poki is only strong against cpu poki
    else if (m_head->GetStrong() == cpuHead->GetType()) {
        cout << "It's super effective!" << endl;

        // Changes the CPU's Pokemon health 
        cpuHead->SetHealth(cpuHealth - STRONG_DAMAGE);

        // Does nothing if the CPU's Poki is K.O.
        if (cpuHead->GetHealth() <= 0) {}

        else {
            cout << cpuHead->GetName() << " attacks ";
            cout << m_head->GetName() << "!" << endl;

            // Changes the user's Pokemon health 
            m_head->SetHealth(usrHealth - DAMAGE2USER);
        }
        
    }

    // If cpu poki is only strong against usr poki 
    else if (cpuHead->GetStrong() == m_head->GetType()) {

        // Changes the CPU's Pokemon health 
        cpuHead->SetHealth(cpuHealth - DAMAGE2ENEMY);

        // Does nothing if the CPU's Poki is K.O.
        if (cpuHead->GetHealth() <= 0) {}

        else {
            cout << cpuHead->GetName() << " attacks ";
            cout << m_head->GetName() << "!" << endl;
            cout << "It's super effective!" << endl;

            // Changes the user's Pokemon health 
            m_head->SetHealth(usrHealth - STRONG_DAMAGE);
        }
        
    }

    // Normal attack
    else {
        
        // Changes the CPU's Pokemon health 
        cpuHead->SetHealth(cpuHealth - DAMAGE2ENEMY);

        // Does nothing if the CPU's Poki is K.O.
        if (cpuHead->GetHealth() <= 0) {}
        
        else {
            cout << cpuHead->GetName() << " attacks ";
            cout << m_head->GetName() << "!" << endl;

            // Changes the user's Pokemon health 
            m_head->SetHealth(usrHealth - DAMAGE2USER);
        }
  
    }
    // userhealth is less than 0
    if (m_head->GetHealth() <= 0) { return USR_POKI_DEAD; }

    // enemy health is lass than 0
    else if (cpuHead->GetHealth() <= 0) { return CPU_POKI_DEAD; }
    
    // default return
    return 0; 
}

// SwapPokemon
    // Given the list, user selects a Pokemon and it is moved into the first position
void PokemonList::SwapPokemon(PokemonList*pokiList){
    int inputVal = 0;
    while (inputVal == 0) {
        cout << "Which Pokemon would you like to choose? (Enter the index#)" << endl;
        pokiList->Display();
        cin >> inputVal;
        if (pokiList->Exist(inputVal)) {
            // if the Pokemon is at the beginning of the list
            if (m_head->GetIndex() == inputVal) {
                cout << "Choice is head" << endl;
            }
            else {
                Pokemon* curr = m_head;
                Pokemon* prev = m_head;
                // sorts through the linked list
                while (inputVal != curr->GetIndex()) {
                    prev = curr;
                    curr = curr->GetNext();
                }
                // if the Pokemon is at the end of the list
                if (curr->GetNext() == nullptr) {
                    prev->SetNext(nullptr);
                    curr->SetNext(m_head);
                    m_head = curr;
                }
                else {
                    prev->SetNext(curr->GetNext());
                    curr->SetNext(m_head);
                    m_head = curr;
                }
            }
        }
        else { inputVal = 0; }
    }
}

// Exist
    // Given the index of the Pokemon, returns true if found else false
bool PokemonList::Exist(int usrIndex){
    Pokemon* curr = m_head;
    // if the Pokemon is at the beginning of the list
    if (curr->GetIndex() == usrIndex) {
        return true;
    }
    // sorts through the linked list
    while (curr != NULL) {
        if (usrIndex == curr->GetIndex()) {
            return true;
        }
        curr = curr->GetNext();
    }
    return false;
    
}
