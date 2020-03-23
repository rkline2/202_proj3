#include "Game.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Name: Game Constructor
    // Desc - Creates a new game and sets m_filename based on string passed
    // Additionally, makes m_list and userPoken = new PokemonLists
    // Preconditions - Input file passed and populated with Pokemon
    // Postconditions - m_filename, m_list, and userPocket created
Game::Game(string fileName) {
    m_filename = fileName;
    m_list;
    m_userPocket = new PokemonList;
}


// Name: Game Destructor
    // Desc - Calls destructor for all linked lists in game
    // Preconditions - Linked lists populated
    // Postconditions - m_list, userPocket, and enemyPocket are all destructed
Game::~Game(){}

// Name: LoadFile
    // Desc - Opens file and reads in each Pokemon. Each Pokemon dynamically allocated
    // and put into m_list
    // Preconditions - Input file passed and populated with Pokemon
    // Postconditions - m_list populated with Pokemon
void Game::LoadFile() {
    ifstream pokemon;
    pokemon.open(m_filename);
    pokemon.close();
  
}

// Name: ChooseTeam
    // Desc - Allows user to choose team and populates m_userPocket
    // Preconditions - m_list populated with Pokemon
    // Postconditions - m_userPocket populated with Pokemon to battle
void Game::ChooseTeam() {}

// Name: Menu
    // Desc - Displays menu and returns choice
    // Preconditions - m_list, m_userPocket, and m_enemyPocket all populated
    // Postconditions - Returns choice
//int Game::Menu() {}

// Name: Battle
    // Desc - Manages the battle between m_userPocket and m_enemyPocket.
    // Displays both the m_userPocket and m_enemyPocket
    // For each round, makes sure each team has Pokemon. Makes Pokemon in head fight.
    // Indicates if the round yields user win, enemy win, and if a pokemon was switched
    // Fights continue until there are no remaining Pokemon in one of the lists
    // Preconditions - m_userPocket and m_enemyPocket must all be > 0 and populated
    // Postconditions - Returns result of battle back to Start (1=user win, 2=cpu win)
//int Game::Battle() {}

// Name: Start
    // Desc - Loads input file, allows user to choose their team, randomly populates the
    // m_enemyPocket with remaining Pokemon and returns the result of the battle
    // Preconditions - m_list, m_userPocket, and m_enemyPocket must all be PokemonLists
    // Postconditions - Returns result of battle back to main
int Game::Start() {
    LoadFile();
    // temp return
    return 0;
}

/*private:
    PokemonList* m_list; //Master list of all Pokemon in game
    PokemonList* m_userPocket; //Users list of Pokemon
    PokemonList* m_enemyPocket; //CPU's list of Pokemon
    string m_filename; //Name of the file passed from main*/
