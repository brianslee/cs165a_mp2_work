#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include "ai.h"
#include "board.h"

using namespace std;

AI::AI()
{
    piece = -2;
    other = -1;
}

AI::AI(int playNum)
{
    piece = playNum;
    if(playNum == -2)
    {
        other = -1;
    }
    else
    {
        other = -2;
    }
}

//Outputs pest possible move according to minimax search
string AI::move(Board board)
{
    vector<position> posMoves = getMoves(board);
    
    int max = INT_MIN;
    position best;
    
    for(int i = 0; i < posMoves.size(); ++i)
    {
        int value = minimax(board, posMoves.at(i), DEPTH, INT_MIN, INT_MAX, true);
        
        if(value > max)
        {
            max = value;
            best = posMoves.at(i);
        }
    }
    
    string output = convert(best.col, best.row);
    return output;
}

//Recursive Minimax with Alpha-Beta Pruning
int AI::minimax(Board board, position move, int depth, int alpha, int beta, bool max)
{
    if(depth == 0)
    {
        return board.getHeuristic();
    }
    else if(board.getWinner() != 0)
    {
        return -depth * board.getHeuristic();
    }
    
    Board child = board;
    if(max)
    {
        child.addMove(move.col, move.row, piece);
    }
    else
    {
        child.addMove(move.col, move.row, other);
    }
    
    vector<position> posMoves = getMoves(child);
    if(max)
    {
        int bestVal = INT_MIN;
        
        if(BREADTH < posMoves.size())
        {
            for(int i = 0; i < BREADTH; ++i)
            {
                int compare = minimax(child, posMoves.at(i), depth - 1, alpha, beta, false);
                if(compare > bestVal)
                {
                    bestVal = compare;
                }
                
                if(bestVal > alpha)
                {
                    alpha = bestVal;
                }
                if(beta <= alpha)
                {
                    break;
                }
                
                return bestVal;
            }
        }
        else
        {
            for(int i = 0; i < posMoves.size(); ++i)
            {
                int compare = minimax(child, posMoves.at(i), depth - 1, alpha, beta, false);
                if(compare > bestVal)
                {
                    bestVal = compare;
                }
                
                if(bestVal > alpha)
                {
                    alpha = bestVal;
                }
                if(beta <= alpha)
                {
                    break;
                }
                
                return bestVal;
            }
        }
    }
    else
    {
        int bestVal = INT_MAX;
        if(BREADTH < posMoves.size())
        {
            for(int j = 0; j < BREADTH; ++j)
            {
                int compare = minimax(child, posMoves.at(j), depth - 1, alpha, beta, true);
                if(compare < bestVal)
                {
                    bestVal = compare;
                }
                
                if(bestVal < beta)
                {
                    beta = bestVal;
                }
                
                if(beta <= alpha)
                {
                    break;
                }
                
                return bestVal;
            }
        }
        else
        {
            for(int j = 0; j < posMoves.size(); ++j)
            {
                int compare = minimax(child, posMoves.at(j), depth - 1, alpha, beta, true);
                if(compare < bestVal)
                {
                    bestVal = compare;
                }
                
                if(bestVal < beta)
                {
                    beta = bestVal;
                }
                
                if(beta <= alpha)
                {
                    break;
                }
                
                return bestVal;
            }
        }
    }
}

//Gets all possible moves from the current board and puts them in a vector as positions
vector<position> AI::getMoves(Board board)
{
    vector<position> moves(0);
    
    for(int c = 0; c < board.getSideSize(); ++c)
    {
        for(int r = 0; r < board.getSideSize(); ++r)
        {
            if(piece == -1)
            {
                if(board.getLightVal(c, r) >= 0 && board.isValidMove(c, r))
                {
                    position temp(c, r, board.getPointHeuristic(c, r));
                    moves.push_back(temp);
                }
            }
            else
            {
                if(board.getDarkVal(c, r) >= 0 && board.isValidMove(c, r))
                {
                    position temp(c, r, board.getPointHeuristic(c, r));
                    moves.push_back(temp);
                }
            }
        }
    }
    sort(moves.begin(), moves.end(), sortValues());
    return moves;
}

//Takes the integer coordinates and converts it into a string position set
string AI::convert(int col, int row)
{
    char c = (char)col + 'a';
    string output(1, c);
    output += to_string(row + 1);
    return output;
}