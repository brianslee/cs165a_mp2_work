//Include guard
#ifndef AI_H_
#define AI_H_

#include <iostream>
#include <vector>
#include <climits>
#include "board.h"

using namespace std;

struct position
{
    int row;
    int col;
    int value;
    position() : row(0), col(0), value(0) {}
    position(int x, int y, int value) : row(y), col(x), value(value) {}
};

struct sortValues
{
    inline bool operator() (const position& p1, const position& p2)
    {
        return (p1.value > p2.value);
    }
};

class AI
{
    public:
    //Constructor(s)
    AI();
    AI(int playNum);
    
    //Public function
    string move(Board board); //Generate the best possible move
    
    private:
    int piece; //Indicates if AI is dark or light player
    int other;
    const static int DEPTH = 10; //Depth of the minimax search
    const static int BREADTH = 25; //Breadth of the search
    //Helper functions
    //The minimax with alpha-beta pruning
    int minimax(Board board, position move, int depth, int alpha, int beta, bool max);
    vector<position> getMoves(Board board); //Gets the possible moves from this board
    string convert(int col, int row); //Converts the coordinates into the appropriate string
};
#endif