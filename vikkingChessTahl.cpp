#include <iostream>

#include "Constants.h"
#include "Setup.h"
#include "Action.h"
#include "Move.h"
#include "EndGame.h"

using namespace std;

int main()
{
    printWelcome();

    int size = 0;
    chooseSize(size);

    char** board = new char* [size];
    initializeBoard(board, size);
    placePiecesOnBoard(board, size);

    char** lastMoveBoard = new char* [size];
    initializeBoard(lastMoveBoard, size);

    int moveCount = 0;
    bool attacker = true;
    bool quit = false;
    bool back = true;
    while (true)
    {
        chooseAction(board, lastMoveBoard, size, attacker, moveCount, quit, back);
        if (quit)
        {
            break;
        }
        saveLastMoveBoard(board, lastMoveBoard, size, back);
        moveAPiece(board, size, attacker);
        changePlayer(attacker);
        moveCount++;
        if (isGameOver(board, size))
        {
            break;
        }
    }

    deleteBoard(board, size);
    deleteBoard(lastMoveBoard, size);

    return 0;
}