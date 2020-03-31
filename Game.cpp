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
    m_list = new PokemonList;
    m_userPocket = new PokemonList;
    m_enemyPocket = new PokemonList;
}


// Name: Game Destructor
    // Desc - Calls destructor for all linked lists in game
    // Preconditions - Linked lists populated
    // Postconditions - m_list, userPocket, and enemyPocket are all destructed
Game::~Game() {
    delete m_list;
    delete m_userPocket;
    delete m_enemyPocket;

    m_list = nullptr;
    m_userPocket = nullptr;
    m_enemyPocket = nullptr;
}

// Name: LoadFile
    // Desc - Opens file and reads in each Pokemon. Each Pokemon dynamically allocated
    // and put into m_list
    // Preconditions - Input file passed and populated with Pokemon
    // Postconditions - m_list populated with Pokemon
void Game::LoadFile() {
    int index = 1;
    string name = "";
    string type = "";
    string item = "";
    string strongTo = "";
    ifstream pokemon;
    pokemon.open(m_filename);
    do
    {
        // ignore the index 
        getline(pokemon, item, ',');
        if (item.size() > 0) {
            
            // name
            getline(pokemon, item, ',');
            name = item;

            // type 
            getline(pokemon, item, ',');
            type = item;

            // strength 
            getline(pokemon, item);
            strongTo = item;
            Pokemon* temp = new Pokemon(index, name, type, strongTo);
            m_list->InsertEnd(temp);
            index++;
        }
    } while (item.size());
    pokemon.close();
}

// Name: ChooseTeam
    // Desc - Allows user to choose team and populates m_userPocket
    // Preconditions - m_list populated with Pokemon
    // Postconditions - m_userPocket populated with Pokemon to battle
void Game::ChooseTeam() {
    int usrNumLeft = 5;
    int cpuNumleft = 5;
    int askIndex = 0;

    while (usrNumLeft > 0) {
        cout << "Here is a list of Pokemon you can choose from" << endl;
        cout << "---------------------------" << endl;
        m_list->Display();
        cout << "Pick a pokemon by enter the index (" << usrNumLeft << " left):" << endl;
        cin >> askIndex;
        if (m_list->Exist(askIndex) && (askIndex > 0 && askIndex <= NUM_POKI)) {
            m_list->Transfer(askIndex, m_userPocket);
            usrNumLeft--;
        }
    }
    while (cpuNumleft > 0) {
        int randIndex = (rand() % NUM_POKI) + 1;
        if (m_list->Exist(randIndex)) {
            m_list->Transfer(randIndex, m_enemyPocket);
            cpuNumleft--;
        }
    }
    cout << "---------------------------" << endl;
    cout << "Print player pocket" << endl;
    m_userPocket->Display();
    cout << "---------------------------" << endl;
    cout << "Print cpu pocket" << endl;
    m_enemyPocket->Display();
}

// Name: Menu
    // Desc - Displays menu and returns choice
    // Preconditions - m_list, m_userPocket, and m_enemyPocket all populated
    // Postconditions - Returns choice
int Game::Menu() {
    int usrChoice = 0;
    cout << "Menu:" << endl;
    cout << "1. Attack" << endl << "2. Swap" << endl << "3. Forfeit" << endl;
    cout << "---------------------------" << endl;
    cin >> usrChoice;

    return usrChoice;
}


// Name: Battle
    // Desc - Manages the battle between m_userPocket and m_enemyPocket.
    // Displays both the m_userPocket and m_enemyPocket
    // For each round, makes sure each team has Pokemon. Makes Pokemon in head fight.
    // Indicates if the round yields user win, enemy win, and if a pokemon was switched
    // Fights continue until there are no remaining Pokemon in one of the lists
    // Preconditions - m_userPocket and m_enemyPocket must all be > 0 and populated
    // Postconditions - Returns result of battle back to Start (1=user win, 2=cpu win)
int Game::Battle() {
    int round = 1, gameResult = 0;
    do
    {
        int usrChoice = 0;
        Pokemon cpuPoki = *m_enemyPocket->GetHead();
        Pokemon usrPoki = *m_userPocket->GetHead();

        cout << "---------------------------" << endl;
        cout << "Round " << round << ":" << endl;
        cout << "CPU's Pokemon: " << cpuPoki << endl;
        cout << "Your Pokemon: " << usrPoki << endl;
        cout << "---------------------------" << endl;
        usrChoice = Menu();
        switch (usrChoice)
        {
        case ATTACK: {
            int attackResult = m_userPocket->Attack(m_enemyPocket);
            if (attackResult == USR_POKI_DEAD) {
                cout << "Oh no! " << usrPoki.GetName() << " is knocked out!" << endl;
                m_userPocket->Remove(usrPoki.GetIndex());

                // checks if m_userPocket is empty 
                if (m_userPocket == NULL) {
                    gameResult = CPU_WIN;
                }
                else {
                    m_userPocket->SwapPokemon(m_userPocket);
                }
            }
            else if (attackResult == CPU_POKI_DEAD) {
                cout << cpuPoki.GetName() << " is knocked out!" << endl;

                // checks if m_enemyPocket is empty
                if (m_enemyPocket == NULL) {
                    gameResult = USR_WIN;
                }
                else {
                    m_enemyPocket->Remove(cpuPoki.GetIndex());
                }
            }
        }
                   round++;
                   break;

        case SWAP: {
            m_userPocket->SwapPokemon(m_userPocket);
        }
                 round++;
                 break;
        case FORFEIT:
            gameResult = CPU_WIN;
            break;
        default:
            gameResult = 0;
            break;
        }
    } while (gameResult == 0);
    return gameResult;
}

// Name: Start
    // Desc - Loads input file, allows user to choose their team, randomly populates the
    // m_enemyPocket with remaining Pokemon and returns the result of the battle
    // Preconditions - m_list, m_userPocket, and m_enemyPocket must all be PokemonLists
    // Postconditions - Returns result of battle back to main
int Game::Start() {
    LoadFile();
    ChooseTeam();
    return Battle();
}

/*private:
    PokemonList* m_list; //Master list of all Pokemon in game
    PokemonList* m_userPocket; //Users list of Pokemon
    PokemonList* m_enemyPocket; //CPU's list of Pokemon
    string m_filename; //Name of the file passed from main*/
