#include <iostream>
#include <cstdlib>
#include "game.h"
#include "board.h"
#include "ai.h"

using namespace std;

int main(int argc, char *argv[])
{
    int size = 11;
    bool humFirst = true;
    cout << humFirst << endl;
    //Set variables from arguments
    for(int i = 1; i < argc; ++i)
    {
        if(string(argv[i]) == "-l")
        {
            humFirst = false;
        }
        if(string(argv[i]) == "-n")
        {
            size = atoi(argv[i + 1]);
        }
    }
    
    //Create game from variables
    Game play(size, humFirst);
    
    //Play game
    play.play();
    
    return 0;
}