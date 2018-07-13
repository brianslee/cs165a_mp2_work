//Include guard
#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
   Board Class 2.0
   Holds all members and functions for diplaying
   the board and adding game pieces to the board
*/

class Board
{
    public:
    //Constructers
    Board();
    Board(int size);
    Board(int size, bool hum);
    
    //Public functions
    void printBoard(); //Exactly what it says
    bool addMove(int col, int row, int player); //Adds player's move to the board
    bool isValidMove(int col, int row);
    bool checkIfFull();
    bool checkWinner(int player); //Checks in there is a winning row
    
    
    //get/set functions
    int getSideSize(); //Returns the size of the side of the board
    int getWinner(); //Returns the current winner
    int getHeuristic(); //Returns board heuristic for the AI
    int getPointHeuristic(int col, int row);//Returns heuristic of the point
    int getDarkVal(int col, int row); //Gets the heuristic value of the inputted position for the Dark player
    int getLightVal(int col, int row); //Gets the heuristic value of the inputted position for the Light player
    
    private:
    //Private member variables
    const int SIDE_SIZE; //Size of the board
    vector<vector<int>> pieces; // The pieces that are on the board
    vector<vector<int>> Dark; //The Dark heuristics of the board
    vector<vector<int>> Light; //The Light heuristcs of the board
    vector<string> columns; // The labels of the columns
    bool humFirst; //If the human is the first player
    
    //Determining heuristics
    const double BASE = 10.0; //Helper for determining heuristics
    
    //Determine winner
    int winner; //The value of the winning player
    const static int NUM_OF_DIRECTIONS = 8; // number of directions around a piece
    const static int FIVE = 5; //number of pieces which have to be in a row to win
    vector<vector<int>> ADJ_DIR; //x and y values of the adjacent squares
    
    //Helper functions
    void setTotVal(bool humanFirst); //Sets the heuristic value of the board
    void setDarkVal(int col, int row, int value); //Set the heuristic value for the Dark player
    void setLightVal(int col, int row, int value); //Set the heuristic value for the Dark player
    
    //Non-heuristic helpers
    int countPieces(int player, int col, int row, int index); //Counts the number of adjacent pieces in the given direction
    void printBorder();
    bool isValidPos(int col, int row);
    
    //Check winner functions
    bool checkVetical(int player);
    bool checkHorizontal(int player);
    bool diagonalDown(int player);
    bool diagonalUp(int player);
};
#endif