#include "game.h"
#include "board.h"
#include "ai.h"
#include <iostream>
#include <string>

using namespace std;

//Constructors
Game::Game() : game(Board()), humNum(-1), comNum(-2), com(AI(-2))
{
    moveMade = "--";
    currPlayer = -1;
    winner = 0;
}

Game::Game(int size, bool humFirst) : game(Board(size, humFirst))
{
    moveMade = "--";
    currPlayer = -1;
    winner = 0;
    if(humFirst)
    {
        humNum = -1;
        comNum = -2;
        com = AI(-2);
    }
    else
    {
        humNum = -2;
        comNum = -1;
        com = AI(-1);
    }
}

//Public function
/** Play
 *  Conducts gameplay, determines whose turn it is.
 *  Outputs game board and messages
 *  ends game.
 **/
 void Game::play()
 {
     bool isFull = false;
     //Output initial board
     print();
     
     while(winner == 0 && !isFull)
     {
         //Play through the game
         //Get input if the current player is a human
         if(currPlayer == humNum)
         {
             //If human is the dark player
             if(humNum == -1)
             {
                 cout << "Dark player (human) plays now. Input Move: ";
             }
             else
             {
                 cout << "Light player (human) plays now. Input move: ";
             }
             cin >> moveMade;
             bool valid = inputMove(moveMade, currPlayer);
             //In case of invalid input
             while(!valid)
             {
                 cout << "Invalid move. Please input a valid move: ";
                 cin >> moveMade;
                 valid = inputMove(moveMade, currPlayer);
             }
         }
         else //If it's the computer's turn, compute the best move
         {
             if(comNum == -1)
             {
                 cout << "Dark player (COM) plays now" << endl;
             }
             else
             {
                 cout << "Light player (COM) plays now" << endl;
             }
             
             //Determine AI's move
             cout << "Calculating best move..." << endl;
             moveMade = com.move(game);
             
             inputMove(moveMade, currPlayer);
         }
         //Print the board
         print();
         //Check if there is a winner
         game.checkWinner(currPlayer);
         winner = game.getWinner();
         isFull = game.checkIfFull();
         
         if(currPlayer == -1)
         {
             currPlayer = -2;
         }
         else
         {
             currPlayer = -1;
         }
     }
     
     endGame();
     if(isFull)
     {
         cout << "No legal moves left. Noone Wins." << endl;
     }
 }
 
//Private Helper Functions
//Print: Prints board and the last move made.
void Game::print()
{
  cout << endl;
  game.printBoard();
  cout << "Move played: " << moveMade << endl;
}

//Reformats string into the int values that are used as coordinates
//Inputs reformatted move into the board
bool Game::inputMove(string input, int player)
{
    bool done = false;
    string r = input.substr(1, 2);
    
    //convert strings to char and int
    int row = atoi(r.c_str());
    row -= 1;
    char c = input[0];
    
    //convert char to int
    int col = (int)c - (int)'a';
    
    //Invalid moves
    if(col >= game.getSideSize() || row >= game.getSideSize())
    {
        return false;
    }
    if(col < 0 || row < 0)
    {
        return false;
    }

    //input the move
    done = game.addMove(col, row, currPlayer);
    return done;
}

//Outputs Game has Ended Messages
void Game::endGame()
{
    if(winner == humNum)
    {
        cout << "Human Wins" << endl;
    }
    else
    {
        cout << "Computer Wins." << endl;
    }
}
