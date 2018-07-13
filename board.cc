#include <iostream>
#include <vector>
#include <cmath>
#include "board.h"

using namespace std;

Board::Board()
: SIDE_SIZE(11), pieces(11, vector<int>(11, 0)), columns(0),
winner(0), ADJ_DIR(2, vector<int>(8, 0)), humFirst(false),
Dark(11, vector<int>(11, 0)), Light(11, vector<int>(11, 0))
{
    columns.push_back("a");
    columns.push_back("b");
    columns.push_back("c");
    columns.push_back("d");
    columns.push_back("e");
    columns.push_back("f");
    columns.push_back("g");
    columns.push_back("h");
    columns.push_back("i");
    columns.push_back("j");
    columns.push_back("k");
    columns.push_back("l");
    columns.push_back("m");
    columns.push_back("n");
    columns.push_back("o");
    columns.push_back("p");
    columns.push_back("q");
    columns.push_back("r");
    columns.push_back("s");
    columns.push_back("t");
    columns.push_back("u");
    columns.push_back("v");
    columns.push_back("w");
    columns.push_back("x");
    columns.push_back("y");
    columns.push_back("z");
    
    ADJ_DIR.at(0).at(0)  = -1;
    ADJ_DIR.at(0).at(1) = 1;
    ADJ_DIR.at(0).at(4)= 1;
    ADJ_DIR.at(0).at(5) = -1;
    ADJ_DIR.at(0).at(6) = -1;
    ADJ_DIR.at(0).at(7) = 1;
    ADJ_DIR.at(1).at(0) = -1;
    ADJ_DIR.at(1).at(1) = 1;
    ADJ_DIR.at(1).at(2) = -1;
    ADJ_DIR.at(1).at(3) = 1;
    ADJ_DIR.at(1).at(4) = -1;
    ADJ_DIR.at(1).at(5) = 1;
}

Board::Board(int size)
: SIDE_SIZE(size), pieces(size, vector<int>(size, 0)), columns(0),
winner(0), ADJ_DIR(2, vector<int>(8, 0)), humFirst(false),
Dark(size, vector<int>(size, 0)), Light(size, vector<int>(size, 0))
{
    columns.push_back("a");
    columns.push_back("b");
    columns.push_back("c");
    columns.push_back("d");
    columns.push_back("e");
    columns.push_back("f");
    columns.push_back("g");
    columns.push_back("h");
    columns.push_back("i");
    columns.push_back("j");
    columns.push_back("k");
    columns.push_back("l");
    columns.push_back("m");
    columns.push_back("n");
    columns.push_back("o");
    columns.push_back("p");
    columns.push_back("q");
    columns.push_back("r");
    columns.push_back("s");
    columns.push_back("t");
    columns.push_back("u");
    columns.push_back("v");
    columns.push_back("w");
    columns.push_back("x");
    columns.push_back("y");
    columns.push_back("z");
    
    ADJ_DIR.at(0).at(0)  = -1;
    ADJ_DIR.at(0).at(1) = 1;
    ADJ_DIR.at(0).at(4)= 1;
    ADJ_DIR.at(0).at(5) = -1;
    ADJ_DIR.at(0).at(6) = -1;
    ADJ_DIR.at(0).at(7) = 1;
    ADJ_DIR.at(1).at(0) = -1;
    ADJ_DIR.at(1).at(1) = 1;
    ADJ_DIR.at(1).at(2) = -1;
    ADJ_DIR.at(1).at(3) = 1;
    ADJ_DIR.at(1).at(4) = -1;
    ADJ_DIR.at(1).at(5) = 1;
}

Board::Board(int size, bool hum)
: SIDE_SIZE(size), pieces(size, vector<int>(size, 0)), columns(0),
winner(0), ADJ_DIR(2, vector<int>(8, 0)), humFirst(hum),
Dark(size, vector<int>(size, 0)), Light(size, vector<int>(size, 0))
{
    columns.push_back("a");
    columns.push_back("b");
    columns.push_back("c");
    columns.push_back("d");
    columns.push_back("e");
    columns.push_back("f");
    columns.push_back("g");
    columns.push_back("h");
    columns.push_back("i");
    columns.push_back("j");
    columns.push_back("k");
    columns.push_back("l");
    columns.push_back("m");
    columns.push_back("n");
    columns.push_back("o");
    columns.push_back("p");
    columns.push_back("q");
    columns.push_back("r");
    columns.push_back("s");
    columns.push_back("t");
    columns.push_back("u");
    columns.push_back("v");
    columns.push_back("w");
    columns.push_back("x");
    columns.push_back("y");
    columns.push_back("z");
    
    ADJ_DIR.at(0).at(0)  = -1;
    ADJ_DIR.at(0).at(1) = 1;
    ADJ_DIR.at(0).at(4)= 1;
    ADJ_DIR.at(0).at(5) = -1;
    ADJ_DIR.at(0).at(6) = -1;
    ADJ_DIR.at(0).at(7) = 1;
    ADJ_DIR.at(1).at(0) = -1;
    ADJ_DIR.at(1).at(1) = 1;
    ADJ_DIR.at(1).at(2) = -1;
    ADJ_DIR.at(1).at(3) = 1;
    ADJ_DIR.at(1).at(4) = -1;
    ADJ_DIR.at(1).at(5) = 1;
}

//Exactly what it says on the tin
void Board::printBoard()
{
    //Print out column labels
    cout << "    ";
    
    for(int c = 0; c < getSideSize(); ++c)
    {
        cout << " ";
        cout << columns.at(c);
        if(c < getSideSize() - 1)
        {
            cout << "  ";
        }
    }
    cout << endl;
    printBorder();
    
    //Print out rows
    for(int row = 0; row < getSideSize(); ++row)
    {
        if(row < 9)
        {
            cout << " ";
        }
        
        cout << row + 1 << " |" ;
        //Print out cells
        for(int col = 0; col < getSideSize(); ++col)
        {
            cout << " ";
            //if piece is -1, output B; if piece is -2, output L; else, print " "
            if(pieces.at(row).at(col) == -1)
            {
                cout << "D";
            }
            else if(pieces.at(row).at(col) == -2)
            {
                cout << "L";
            }
            else
            {
                cout << " ";
            }
            cout << " |";
        }
        cout << endl;
        printBorder();
    }
}

bool Board::addMove(int col, int row, int player)
{
    if(!isValidMove(col, row))
    {
        return false;
    }
    pieces.at(row).at(col) = player;
    Dark.at(row).at(col) = player;
    Light.at(row).at(col) = player;
    
    bool won = checkWinner(player);
    if(won)
    {
        winner = player;
    }
    
    //set heuristics
    for(int i = 0; i < NUM_OF_DIRECTIONS; ++i)
    {
        int dCol = col + ADJ_DIR.at(0).at(i);
        int dRow = row + ADJ_DIR.at(1).at(i);
        
        while(isValidPos(dCol, dRow) && pieces.at(dRow).at(dCol) == player)
        {
            dCol += ADJ_DIR.at(0).at(i);
            dRow += ADJ_DIR.at(1).at(i);
        }
        
        if(player == -1)
        {
            setDarkVal(dCol, dRow, getDarkVal(dCol, dRow));
        }
        else
        {
            setLightVal(dCol, dRow, getLightVal(dCol, dRow));
        }
    }
    return true;
}

bool Board::checkIfFull()
{
    for(int r = 0; r < SIDE_SIZE; ++r)
    {
        for(int c = 0; c < SIDE_SIZE; ++c)
        {
            if(pieces.at(r).at(c) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

//Getter and Setter functions
int Board::getSideSize()
{
    return SIDE_SIZE;
}

int Board::getWinner()
{
    return winner;
}

int Board::getHeuristic()
{
    int heuristic = 0;
    for(int row = 0; row < SIDE_SIZE; ++row)
    {
        for(int col = 0; col < SIDE_SIZE; ++col)
        {
            if(humFirst)
            {
                if(Dark.at(row).at(col) >= 0)
                {
                    heuristic += (Light.at(row).at(col) - Dark.at(row).at(col));
                }
            }
            else
            {
                if(Light.at(row).at(col) >= 0)
                {
                    heuristic += (Dark.at(row).at(col) - Light.at(row).at(col));
                }
            }
        }
    }
    return heuristic;
}

int Board::getPointHeuristic(int col, int row)
{
    if(humFirst)
    {
        return Light.at(row).at(col) - Dark.at(row).at(col);
    }
    else
    {
        return Dark.at(row).at(col) - Light.at(row).at(col);
    }
}

//Get heuristic value for Dark Player of the current position
int Board::getDarkVal(int col, int row)
{
    int total = 0;
    for(int i = 0; i < NUM_OF_DIRECTIONS; i = i + 2)
    {
        int dCol = col + ADJ_DIR.at(0).at(i);
        int dRow = row + ADJ_DIR.at(1).at(i);
        int length1 = countPieces(-1, col, row, i);
        if(isValidPos(col, row) && pieces.at(row).at(col) == -1)
        {
            length1++;
        }
        
        int dCol2 = col + ADJ_DIR.at(0).at(i + 1);
        int dRow2 = row + ADJ_DIR.at(1).at(i + 1);
        int length2 = countPieces(-1, col, row, i + 1);
        
        int totLength = length1 + length2;
        
        if(totLength == 4)
        {
            totLength * 1000;
        }
        if(totLength == 3)
        {
            totLength * 100;
        }
        
        if(totLength != 0)
        {
            double temLength = (double)totLength;
            double temp = pow(BASE, temLength);
            total += (int)temp;
        }
    }
    //cout << total << endl;
    return total;
}

//Get heuristic value for Light Player of the current position
int Board::getLightVal(int col, int row)
{
    int total = 0;
    for(int i = 0; i < NUM_OF_DIRECTIONS; i = i + 2)
    {
        int dCol = col + ADJ_DIR.at(0).at(i);
        int dRow = row + ADJ_DIR.at(1).at(i);
        int length1 = countPieces(-2, col, row, i);
        if(isValidPos(col, row) && pieces.at(row).at(col) == -2)
        {
            length1++;
        }
        
        int dCol2 = col + ADJ_DIR.at(0).at(i + 1);
        int dRow2 = row + ADJ_DIR.at(1).at(i + 1);
        int length2 = countPieces(-2, col, row, i + 1);
        
        int totLength = length1 + length2;
        
        if(totLength == 4)
        {
            totLength * 1000;
        }
        if(totLength == 3)
        {
            totLength * 100;
        }
        
        if(totLength != 0)
        {
            double temLength = (double)totLength;
            double temp = pow(BASE, temLength);
            total += (int)temp;
        }
    }
    
    return total;
}

//Helper Functions
//Print the border in between rows
void Board::printBorder()
{
    //Prime the output
    cout << "   +";
    //For each column, print the ---+ border
    for(int c = 0; c < SIDE_SIZE; ++c)
    {
        cout << "---+";
    }
    cout << endl;
}

//Checks if position on board is valid
bool Board::isValidPos(int col, int row)
{
    return col >= 0 && row >= 0 && col < SIDE_SIZE && row < SIDE_SIZE;
}

//Checks if the move is valid
bool Board::isValidMove(int col, int row)
{
    return isValidPos(col, row) && (pieces.at(row).at(col) == 0);
}

//Checks if there is a winner
bool Board::checkWinner(int player)
{
    return checkVetical(player) || checkHorizontal(player) || diagonalDown(player) || diagonalUp(player);
}

//Counts number of adjacent pieces of a player from that position in a given direction
int Board::countPieces(int player, int col, int row, int index)
{
    int length = 0;
    int r = row;
    int c = col;
    if(isValidPos(c, r) && pieces.at(r).at(c) == player)
    {
        length++;
    }
    
    if(index == 1)
    {
        while(isValidPos(c - 1, r - 1) && pieces.at(r - 1).at(c-1) == player)
        {
            length++;
            r--;
            c--;
        }
    }
    else if(index == 2)
    {
        while(isValidPos(c - 1, r) && pieces.at(r).at(c - 1) == player)
        {
            length++;
            c--;
        }
    }
    else if(index == 3)
    {
        while(isValidPos(c - 1, r + 1) && pieces.at(r + 1).at(c - 1) == player)
        {
            length++;
            c--;
            r++;
        }
    }
    else if(index == 4)
    {
        while(isValidPos(c, r + 1) && pieces.at(r + 1).at(c) == player)
        {
            length++;
            r++;
        }
    }
    else if(index == 5)
    {
        while(isValidPos(c + 1, r + 1) && pieces.at(r + 1).at(c + 1) == player)
        {
            length++;
            c++;
            r++;
        }
    }
    else if(index == 6)
    {
        while(isValidPos(c + 1, r) && pieces.at(r).at(c + 1) == player)
        {
            length++;
            c++;
        }
    }
    else if(index == 7)
    {
        while(isValidPos(c + 1, r - 1) && pieces.at(r - 1).at(c + 1) == player)
        {
            length++;
            r--;
            c++;
        }
    }
    else
    {
        while(isValidPos(c, r - 1) && pieces.at(r - 1).at(c) == player)
        {
            length++;
            r--;
        }
    }
    
    return length * 2;
}

//Set heuristic value for Dark Player at current position
void Board::setDarkVal(int col, int row, int value)
{
    if(isValidPos(col, row))
    {
        Dark.at(row).at(col) = value;
    }
}

//Set heuristic value for Light Player at current position
void Board::setLightVal(int col, int row, int value)
{
    if(isValidPos(col, row))
    {
        Light.at(row).at(col) = value;
    }
}

bool Board::checkVetical(int player)
{
    for(int col = 0; col < SIDE_SIZE; ++col)
    {
        for(int row = 0; row < SIDE_SIZE - 5; ++row)
        {
            if(pieces.at(row).at(col) == player)
            {
                if(pieces.at(row + 1).at(col) == player)
                {
                    if(pieces.at(row + 2).at(col) == player)
                    {
                        if(pieces.at(row + 3).at(col) == player)
                        {
                            if(pieces.at(row + 4).at(col) == player)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Board::checkHorizontal(int player)
{
    for(int col = 0; col < SIDE_SIZE - 5; ++col)
    {
        for(int row = 0; row < SIDE_SIZE; ++row)
        {
            if(pieces.at(row).at(col) == player)
            {
                if(pieces.at(row).at(col + 1) == player)
                {
                    if(pieces.at(row).at(col + 2) == player)
                    {
                        if(pieces.at(row).at(col + 3) == player)
                        {
                            if(pieces.at(row).at(col + 4) == player)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Board::diagonalDown(int player)
{
    for(int col = 0; col < SIDE_SIZE - 5; ++col)
    {
        for(int row = 0; row < SIDE_SIZE -5; ++row)
        {
            if(pieces.at(row).at(col) == player)
            {
                if(pieces.at(row + 1).at(col + 1) == player)
                {
                    if(pieces.at(row + 2).at(col + 2) == player)
                    {
                        if(pieces.at(row + 3).at(col + 3) == player)
                        {
                            if(pieces.at(row + 4).at(col + 4) == player)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Board::diagonalUp(int player)
{
    for(int col = 4; col < SIDE_SIZE; ++col)
    {
        for(int row = 4; row < SIDE_SIZE; ++row)
        {
            if(pieces.at(row).at(col) == player)
            {
                if(pieces.at(row - 1).at(col - 1) == player)
                {
                    if(pieces.at(row - 2).at(col - 2) == player)
                    {
                        if(pieces.at(row - 3).at(col - 3) == player)
                        {
                            if(pieces.at(row - 4).at(col - 4) == player)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}