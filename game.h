//Include Guards
#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include "board.h"
#include "ai.h"

using namespace std;

class Game
{
    public:
    //Constructors
    Game();
    Game(int size, bool humFirst);
    
    //Public functions
    void play();//Handles the gameplay
    
    private:
    //Private member variables
    Board game; //Game board
    AI com; //Computer
    int currPlayer; //Current player of the game
    int humNum; //Number of the human player
    int comNum; //Number of the ai
    int winner; //The game's winner
    string moveMade; //Last move to be inputted
    
    //Private helper function
    bool inputMove(string input, int player); //Reformats string to put move on board
    void print(); //prints game board
    void endGame(); //Ends the game
};
#endif