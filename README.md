# Pokémon

## 1. Description
Your assignment is to build an application that can allow us to battle two linked lists of Pokémon.
  1.	The input file will hold some number of Pokémon with the following order: index (int), name (string), type (string), and strong (string).
  2.	All Pokémon should be inserted at the end of the linked list.
  3.	The m_list holds all of the Pokémon for the entire game. A pocket is a linked list representing a team. The m_userPocket holds the user’s Pokémon and the m_enemyPocket holds the enemy Pokémon.
  4.	The data file (proj3_data.txt) is loaded via command line argument (included in the provided makefile and proj3.cpp). 
 
**Input File Details:**<br>
149 (idex), Dragonite (name), Dragon (type), Electric (strong against)

  5.	When a Pokémon is added to either the m_userPocket or m_enemyPocket, it is permantently removed from m_list.
  6.	The user’s pocket will be populated by asking the user to choose Pokémon for their team. After the user has chosen their pocket, the enemy’s pocket will be randomly populated from the remaining Pokémon.
  7.	Initially, each Pokémon team (user and enemy) will have 5 Pokémon. As a Pokémon is defeated, it is removed from the team. The battle (and game) ends when there are no Pokémon left on one of the teams.
  8.	All user inputs will be assumed to be the correct data type. For example, if you ask the user for an integer, they will provide an integer.
  9.	Regardless of the sample output below, all user input must be validated. If you ask for a number between 1 and 5 with the user entering an 8, the user should be re-prompted.
  10.	The general game flow:
    a.	Game constructor – Initializes each of the game variables
    b.	Game Start - Loads File (populates m_list), Choose user team, and populates enemy team. Calls Battle.
    c.	Battle – Displays each of the teams initially. Manages each of the rounds of the battle. Allows user to attack, choose a new Pokémon to attack, or forfeit (automatically loses to enemy). Checks to see if either team still has members. The head of the m_userPocket and the m_enemyPocket always fight each other.
    d.	Upon exit, nothing is saved
    
## 2. Background
For this project, we are going to be designing a simple implementation of the famous Pokémon franchise. If you are not familiar with Pokémon, it is a
game where you act as a trainer of pocket monsters (Pokémon). You carefully choose the roster finding the perfect Pokémon to matchup against the computer.
Finally, after you build your roster of Pokémon, you can battle them against the computer!

For this project, each node in our linked list is going to be a Pokémon. Each Pokémon has a name, an index, a type, and a type that it is strong against. The name, type, and strong are all strings and the index are an integer.
Our linked list is going to be a little bit special because it is designed to hold and manage Pokémon. We can insert Pokémon into the linked list, we can remove Pokémon from a specific location in our linked list, we can Attack Pokémon, we can Swap Pokémon, and a variety of other things.
Finally, the game itself will allow us to battle our roster of Pokémon against a randomly assigned roster of enemy Pokémon. The skill in this game is to find a preferable roster that can defeat the enemies. Each Pokémon has a strength and identifying that strength is required to defeat the enemies – especially when the enemies are stronger than we are!

## 3. Overview
In this project you will:
  *	Implement a linked-list data structure<br>
  *	Use dynamic memory allocation to create new objects<br>
  *	Practice using C++ class syntax<br>
  *	Practice object-oriented thinking<br>
