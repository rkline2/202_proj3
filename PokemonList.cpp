#include "PokemonList.h"
#include <iostream>
using namespace std;

// Name: PokemonList
    // Desc - Default constructor for the PokemonList (linked list)
    // Preconditions - None
    // Postconditions - Creates an empty PokemonList (linked list)
PokemonList::PokemonList() {
    m_head = nullptr;
    m_size = 0;
}

// Name: ~PokemonList
    // Desc - Destructor for the PokemonList (linked list)
    // Preconditions - None
    // Postconditions - Clears out a PokemonList (linked list)
PokemonList::~PokemonList() {
    Pokemon* curr = m_head;
    while (curr != NULL) {
        Pokemon* temp = curr->GetNext();
        delete curr;
        curr = temp;
    }
}

// Name: InsertEnd
    // Desc - Inserts an already dynamically allocated Pokemon to end of linked list
    // Preconditions - PokemonList already created
    // Postconditions - The passed Pokemon appears at the end of the list
void PokemonList::InsertEnd(Pokemon* newPokemon){
    // still need to connect the nodes together stopped here
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

// Name: Display
    // Desc - Iterates over PokemonList and displays each Pokemon formatted as in output
    // Preconditions - PokemonList already created and has Pokemon
    // Postconditions - Displayed Pokemon information
void PokemonList::Display(){
    Pokemon* tp = m_head;
    // will need to use the special cout operator stopped here 
    while (tp != NULL) {
        int max_nameSp = 12;
        int max_typeSp = 10;

        int index = tp->GetIndex();
        string name = tp->GetName();
        string type = tp->GetType();
        int health = tp->GetHealth();
        
        cout << "Index: " << setw(NUM_SPACE) << index << " ";
        cout << "Name: "<< tp->GetName();
        // for-loop here
        for (int i = 0; i <= (max_nameSp - name.size()); i++) {
            cout << " ";
        }
        cout << "Type: " << tp->GetType();
        // for-loop here
        for (int i = 0; i <= max_typeSp - type.size(); i++) {
            cout << " ";
        }
        cout << "Health: " << tp->GetHealth();
        cout << endl;
        tp = tp->GetNext();
    }
}

// Name: Transfer
    // Desc - Searches for a Pokemon with a specific index. If found,
    // creates a new Pokemon and copies it into the PokemonList passed in
    // Preconditions - int is the index of the desired Pokemon and
    // PokemonList is the destination
    // Postconditions - Adds new Pokemon to the destination list and removes it from
    // the source
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

// Name: Remove (int)
    // Desc - Searches for a Pokemon with a specific index. If found,
    // removes it from the linked list
    // Preconditions - int is the index of the desired Pokemon
    // Postconditions - Removes Pokemon from linked list
void PokemonList::Remove(int pokiIndex){
    Pokemon* curr = m_head;
    Pokemon* prev = m_head;
    if(curr->GetIndex() == pokiIndex){
        m_head = m_head->GetNext();
        delete curr; 
    }
    else {
        while (curr->GetIndex() != pokiIndex) {
            prev = curr;
            curr = curr->GetNext();
        }
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

// Name: GetSize
    // Desc - Returns the size of the linked list
    // Preconditions - PokemonList is populated with Pokemon
    // Postconditions - Returns the size of the linked list
int PokemonList::GetSize() { return m_size; }

// Name: GetHead
    // Desc - Returns the Pokemon at the head of the linked list
    // Preconditions - PokemonList is populated with Pokemon
    // Postconditions - Returns the Pokemon at the head of the linked list
Pokemon* PokemonList::GetHead() { return m_head; }

// Name: Attack(PokemonList)
    // Desc - Passes an enemy pocket to the user's pocket to attack
    // User always attacks the enemy Pokemon in this game
    // Preconditions - This list is populated and enemy list is populated
    // Postconditions - Does damage to the user Pokemon and enemy Pokemon
    // and updates their health. Returns 2 if enemy Pokemon is less than 0
    // Returns 2 if user's health is less than 0 else returns 0.
int PokemonList::Attack(PokemonList*cpuPoki) {
    Pokemon* cpuHead = cpuPoki->GetHead();
    int cpuHealth = cpuHead->GetHealth();
    int usrHealth = m_head->GetHealth();

    cout << m_head->GetName() << " attacks " << cpuHead->GetName() << "!" << endl;
    // If usr poki is strong against cpu poki and cpu poki is strong against usr poki 
    if (m_head->GetStrong() == cpuHead->GetType() && 
        cpuHead->GetStrong() == m_head->GetType()) {
        cout << "It's super effective!" << endl;

        cout << cpuHead->GetName() << " attacks "; 
        cout << m_head->GetName() << "!" << endl;

        cout << "It's super effective!" << endl;

        cpuHead->SetHealth(cpuHealth - STRONG_DAMAGE);
        m_head->SetHealth(usrHealth - STRONG_DAMAGE);
    
    }

    // If usr poki is only strong against cpu poki
    else if (m_head->GetStrong() == cpuHead->GetType()) {
        cout << "It's super effective!" << endl;

        cout << cpuHead->GetName() << " attacks ";
        cout << m_head->GetName() << "!" << endl;

        cpuHead->SetHealth(cpuHealth - STRONG_DAMAGE);
        m_head->SetHealth(usrHealth - DAMAGE2USER);
    }

    // If cpu poki is only strong against usr poki 
    else if (cpuHead->GetStrong() == m_head->GetType()) {
        cout << cpuHead->GetName() << " attacks ";
        cout << m_head->GetName() << "!" << endl;
        cout << "It's super effective!" << endl;
        cpuHead->SetHealth(cpuHealth - DAMAGE2ENEMY);
        m_head->SetHealth(usrHealth - STRONG_DAMAGE);
    }

    // Normal attack
    else {
        cout << cpuHead->GetName() << " attacks ";
        cout << m_head->GetName() << "!" << endl;
        cpuHead->SetHealth(cpuHealth - DAMAGE2ENEMY);
        m_head->SetHealth(usrHealth - DAMAGE2USER);

    }
    // userhealth is less than 0
    if (m_head->GetHealth() <= 0) { return USR_POKI_DEAD; }

    // enemy health is lass than 0
    else if (cpuHead->GetHealth() <= 0) { return CPU_POKI_DEAD; }
    
    return 0; 
}

// Name: SwapPokemon
    // Desc - Allows user to move a Pokemon from any position into the first position
    // Special cases: Empty list, Pokemon chosen at m_head or choice doesn't exist
    // Preconditions - Linked list is populated
    // Postconditions - User selects a Pokemon and it is moved into the first position
void PokemonList::SwapPokemon(PokemonList*pokiList){
    int inputVal = 0;
    while (inputVal == 0) {
        cout << "Which Pokemon would you like to choose? (Enter the index#)" << endl;
        pokiList->Display();
        cin >> inputVal;
        if (pokiList->Exist(inputVal)) {
            if (m_head->GetIndex() == inputVal) {
                cout << "Choice is head" << endl;
            }
            else {
                Pokemon* curr = m_head;
                Pokemon* prev = m_head;
                while (inputVal != curr->GetIndex()) {
                    prev = curr;
                    curr = curr->GetNext();
                }
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

// Name: Exist(int)
    // Desc - Iterates through linked list looking for a specific index of a Pokemon
    // Preconditions - PokemonList is populated with Pokemon
    // Postconditions - Returns true if found else false
bool PokemonList::Exist(int usrIndex){
    Pokemon* curr = m_head;
    if (curr->GetIndex() == usrIndex) {
        return true;
    }
    while (curr != NULL) {
        if (usrIndex == curr->GetIndex()) {
            return true;
        }
        curr = curr->GetNext();
    }
    return false;
    
}

/*private:
    Pokemon* m_head; //Node pointer pointing to first node in linked list
    int m_size; //Size of the linked list*/
