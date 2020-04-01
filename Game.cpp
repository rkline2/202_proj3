/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 3, Spring 2020
** Author:  Rooklyn Kline
** Date:    4/02/20
** Section: 02
** E-mail:  rkline2@umbc.edu
**
** This file contains all of the functions that are relevant to
** the Pokemon game. It loads and stores all of the Pokemons  
** in the main list, battles the user and returns the winner of the game 
** to the proj3.cpp file.
**
***********************************************/
#include "Game.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Game Constructor
    // Sets m_filename to the given parameter filename 
    // Sets m_list, m_userPocket and m_enemyPocket as a new list 
Game::Game(string fileName) {
    m_filename = fileName;
    m_list = new PokemonList;
    m_userPocket = new PokemonList;
    m_enemyPocket = new PokemonList;
}


// Game Destructor
    // Removes all linked lists in the game
Game::~Game() {
    delete m_list;
    delete m_userPocket;
    delete m_enemyPocket;

    m_list = nullptr;
    m_userPocket = nullptr;
    m_enemyPocket = nullptr;
}

// LoadFile
    // Given the filename, populates m_list with pokemon
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
            
            // gets the name
            getline(pokemon, item, ',');
            name = item;

            // gets the type 
            getline(pokemon, item, ',');
            type = item;

            // gets the strength 
            getline(pokemon, item);
            strongTo = item;
            Pokemon* temp = new Pokemon(index, name, type, strongTo);
            m_list->InsertEnd(temp);
            index++;
        }
    } while (item.size());
    pokemon.close();
}

// ChooseTeam
    // Lets the user choose which Pokemon they want
    // CPU's list is randomly populated with the remaining Pokemon
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
    // fills the CPU's list with random Pokemon
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

// Menu
    // Gives the player three options to choose from
    // Returns the user's choice  
int Game::Menu() {
    int usrChoice = 0;
    cout << "Menu:" << endl;
    cout << "1. Attack" << endl << "2. Swap" << endl << "3. Forfeit" << endl;
    cout << "---------------------------" << endl;
    cin >> usrChoice;
    cout << "---------------------------" << endl;
    return usrChoice;
}


// Battle
    // Manages the battle between m_userPocket and m_enemyPocket
    // Returns result of battle back to Start (1=user win, 2=cpu win)
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
                if (m_userPocket->GetHead() == NULL) {
                    gameResult = CPU_WIN;
                }
                else {
                    m_userPocket->SwapPokemon(m_userPocket);
                }
            }
            else if (attackResult == CPU_POKI_DEAD) {
                cout << cpuPoki.GetName() << " is knocked out!" << endl;

                // checks if m_enemyPocket is empty
                if (m_enemyPocket->GetHead() == NULL) {
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

// Start
    // Returns result of battle back to main
int Game::Start() {
    LoadFile();
    ChooseTeam();
    return Battle();
}

