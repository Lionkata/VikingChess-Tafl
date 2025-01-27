#include <iostream>
#include <string>

using namespace std;

char BLANK_SYMBOL = '*';
char THRONE_SYMBOL = 'X';
char KING_SYMBOL = 'K';
char DEFENDER_SYMBOL = 'D';
char ATTACKER_SYMBOL = 'A';


void printWelcome()
{
    cout << "Welcome in Viking Chess game." << endl;
}
void chooseBoardSize(int &boardSize)
{
    cout << "Choose board size!" << endl;
    cout << "1. 7x7" << endl;
    cout << "2. 9x9" << endl;
    cout << "3. 11x11" << endl;
    cout << "4. 13x13" << endl;
    cout << "Option: ";
    int option;
    while (true)
    {
        cin >> option;
        if (option < 1 || option > 4)
        {
            cout << "Invalid input!" << endl;
        }
        else
        {
            break;
        }

    }
    switch (option)
    {
        case 1: boardSize = 7; break;
        case 2: boardSize = 9; break;
        case 3: boardSize = 11; break;
        case 4: boardSize = 13; break;
    }
}
void initializeBoard(char** const board, int boardSize) 
{
    for (int i = 0; i < boardSize; i++)
    {
        board[i] = new char[boardSize];
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = BLANK_SYMBOL;
        }
    }
}
void putFiguresOnBoard(char ** const board, int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = '  *';
        }
    }
   
    //king
    int king = boardSize / 2;
    board[king][king] = KING_SYMBOL;

    //ATTACKER_SYMBOL
    for (int i = 0; i < boardSize; i++) 
    {
        if (i == 0 || i == boardSize - 1) 
        {
            board[i][king] = ATTACKER_SYMBOL;
            board[king][i] = ATTACKER_SYMBOL;
        }
        else if (i == king) 
        {
            board[0][i] = ATTACKER_SYMBOL;
            board[boardSize - 1][i] = ATTACKER_SYMBOL;
        }
        if (i == 1 || i == boardSize - 2)
        {
            board[i][king] = ATTACKER_SYMBOL;
            board[king][i] = ATTACKER_SYMBOL;
        }
    }
    for (int i = 0; i < boardSize; i++)
    {
        if (i >2 && i < boardSize - 3)
        {
            board[0][i] = ATTACKER_SYMBOL;        
            board[boardSize - 1][i] = ATTACKER_SYMBOL; 
            board[i][0] = ATTACKER_SYMBOL;       
            board[i][boardSize - 1] = ATTACKER_SYMBOL; 
        }
    }

    //throne
    board[0][0] = THRONE_SYMBOL;
    board[0][boardSize - 1] = THRONE_SYMBOL;
    board[boardSize - 1][0] = THRONE_SYMBOL;
    board[boardSize - 1][boardSize - 1] = THRONE_SYMBOL;

    //DEFENDER_SYMBOL
    board[king - 1][king] = DEFENDER_SYMBOL;
    board[king + 1][king] = DEFENDER_SYMBOL;
    board[king][king - 1] = DEFENDER_SYMBOL;
    board[king][king + 1] = DEFENDER_SYMBOL;

    if (boardSize >= 9) 
    {
        board[king][king - 2] = DEFENDER_SYMBOL;
        board[king][king + 2] = DEFENDER_SYMBOL;
        board[king - 2][king] = DEFENDER_SYMBOL;
        board[king + 2][king] = DEFENDER_SYMBOL;
    }

    if (boardSize >= 11) 
    {
        board[king -1][king - 1] = DEFENDER_SYMBOL;
        board[king + 1][king + 1] = DEFENDER_SYMBOL;
        board[king - 1][king + 1] = DEFENDER_SYMBOL;
        board[king + 1][king - 1] = DEFENDER_SYMBOL;
        board[king - 2][king] = DEFENDER_SYMBOL;
        board[king + 2][king] = DEFENDER_SYMBOL;
        board[king][king - 2] = DEFENDER_SYMBOL;
        board[king][king + 2] = DEFENDER_SYMBOL;
    }

    if (boardSize == 13) 
    {
        board[king - 3][king] = DEFENDER_SYMBOL;
        board[king][king + 3] = DEFENDER_SYMBOL;
        board[king + 3][king] = DEFENDER_SYMBOL;
        board[king][king - 3] = DEFENDER_SYMBOL;
    }
}
void printBoard(char** const board, int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            cout << board[i][j] << ' ';
            if (j == boardSize - 1)
            {
                cout << "| " << i + 1;
            }
        }
        cout << endl;
    }
    for (int i = 0; i < boardSize; i++)
    {
        cout << "--";
    }
    cout << endl;
    for (int i = 0; i < boardSize; i++)
    {
        cout << (char)('a' + i) << ' ';
    }
    cout << endl;
}

void printRules()
{
    cout << "Rules of Viking Chess game!" << endl;
    cout << "1. The attacking side moves first. " << endl;
    cout << "2.All pieces move like the rook in Chess – in a straight line for as many" ;
        cout << "empty squares as the player chooses." << endl;
    cout << "3. Pieces cannot hop over other pieces and cannot move diagonally." << endl;
    cout << "4. Capturing only happens when a piece is moved so that a single opposing ";
        cout << "piece ends up trapped between two of the players pieces.A captured " ;
        cout << "piece is immediately removed from the board. "  << endl;
    cout << "5. The King is unarmed and cannot capture." << endl;
    cout << "6. A piece that is next to the corner square can be captured by a single opposing piece. " << endl;
    cout << "7. The piece is moved so thatthe opposing piece is trapped between the corner and " ;
        cout << "the piece moved - the corner square acts as the second capturing piece."<< endl;
    cout << "8. A piece can safely move to a square between two of the opponent's pieces without being captured." << endl;
    cout << "9. The King is harder to capture because opposing pieces must surround him on all four sides or," ;
        cout << "if the King is at the edge of the board, on the 3 sides available. "<< endl;
    cout << "10. Only the King is allowed into the corner squares – and, of course, such a move wins the game." << endl;
    cout << endl;
}
void printHelp()
{
    cout << "Move - <the coordinates of the current figure> <coordinates of the next move>." << endl;
    cout << "Back - returns the last move played." << endl;
    cout << "Rule - brings back the rules of the game." << endl;
    cout << "Info - returns whose turn it is." << endl;
    cout << "Quit - break the game." << endl;
    cout << endl;
}



bool areFigureCoordinatesValid(char** const board, int boardSize, int row, int colmn, bool playerAttack)
{
    if (row > boardSize || colmn > boardSize || row < 1 || colmn < 1)
    {
        return false;
    }
    if (board[row][colmn] == ATTACKER_SYMBOL && playerAttack)
    {
        return true;
    }
    else if ((board[row][colmn] == DEFENDER_SYMBOL || board[row][colmn] == KING_SYMBOL) && !playerAttack)
    {
        return true;
    }
    return false;
}
bool areMoveCoordinatesValid(char** const board, int boardSize, int row1, int colmn1, int row2, int colmn2, bool playerAttack)
{
    if (row2 > boardSize || colmn2 > boardSize || row2 < 1 || colmn2 < 1)
    {
        return false;
    }

    if (playerAttack)
    {
        if (board[row2][colmn2] != BLANK_SYMBOL)
        {
            return false;
        }
        else if (row2 != row1 && colmn1 != colmn2)
        {
            return false;
        }

        if (row1 == row2 && colmn1 > colmn2)
        {
            for (int i = colmn1; i > colmn2; i--)
            {
                if (board[row2][i])
                {
                    return false;
                }
            }
        }
        if (row1 == row2 && colmn1 < colmn2)
        {
            for (int i = colmn1; i < colmn2; i++)
            {
                if (board[row2][i])
                {
                    return false;
                }
            }
        }
        if (row1 == row2 && colmn1 > colmn2)
        {
            for (int i = colmn1; i > colmn2; i--)
            {
                if (board[row2][i])
                {
                    return false;
                }
            }
        }
        if (row1 == row2 && colmn1 > colmn2)
        {
            for (int i = colmn1; i > colmn2; i--)
            {
                if (board[row2][i])
                {
                    return false;
                }
            }
        }
    }
    return 0;
}

void move()
{

}

void chooseAction(char** const board, int boardSize, bool playerAttack)
{
    string action;
    cout << "Your next move! (move, help, rules, quit, info, back, quit): ";
    
    while (true)
    {
        cin >> action;
        if (action == "move") 
        {
            int row1, colmn1, row2, colmn2;
            cout << "Figure coordinates: "; 
            while (true)
            {
                cin >> row1 >> colmn1;
                if (!areFigureCoordinatesValid(board, boardSize, row1, colmn1, playerAttack))
                {
                    cout << "Invalid coordinates!" << endl;
                }
                else
                {
                    break;
                }
            }
            cout << endl;
            cout << "Move to: ";
            while (true)
            {
                cin >> row2 >> colmn2;
                if (!areMoveCoordinatesValid(board, boardSize, row2, colmn2, playerAttack))
                {
                    cout << "Invalid coordinates!" << endl;
                }
                else
                {
                    break;
                }
            }
            move();
            break;
        }
        else if (action == "help") {
            printHelp();
        }
        else if (action == "rules" || action == "rule") {
            printRules(); 
        }
        
        else if (action == "info") {
          // whoIsTurn();
        }
        else if (action == "back") {
           // lastMoveList();
        }
        else if (action == "quit") {
            break;
        }
        else {
            cout << "Try again!";
        }
        cout << "Your next move! (move, help, rules, quit, info, back, quit): ";
    } 
}

void switchPlayers(bool &playerAttack)
{
    if (playerAttack)
    {
        playerAttack = false;
    }
    else
    {
        playerAttack = true;
    }
}

bool isGameOver(char** const board, int boardSize)
{
    int kingRow = -1, kingCol = -1;
    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardSize; j++) 
        {
            if (board[i][j] == KING_SYMBOL) 
            {
                kingRow = i;
                kingCol = j;
                break;
            }
        }
    }
    return (kingRow == 0 && kingCol == 0) ||
           (kingRow == 0 && kingCol == boardSize - 1) ||
           (kingRow == boardSize - 1 && kingCol == 0) ||
           (kingRow == boardSize - 1 && kingCol == boardSize - 1);
   
}

int main()
{
    printWelcome();

    int boardSize = 0;
    chooseBoardSize(boardSize);

    char** board = new char*[boardSize];
    initializeBoard(board, boardSize);
    putFiguresOnBoard(board, boardSize);

    bool playerAttack = true;
    while (isGameOver(board, boardSize))
    {
        printBoard(board, boardSize);
        chooseAction(board, boardSize, playerAttack);

        switchPlayers(playerAttack);
    }



    
}