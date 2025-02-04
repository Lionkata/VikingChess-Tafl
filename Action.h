#pragma once

using namespace std;

void changePlayer(bool& attacker)
{
	attacker = !attacker;
}
void returnLastMove(char* const* const board, const char* const* const lastMoveBoard, int size, bool& attacker, int& moveCount, bool& back)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			board[i][j] = lastMoveBoard[i][j];
		}
	}
	back = false;
	moveCount--;
	changePlayer(attacker);

	system("cls");
	printBoard(board, size);
}
void saveLastMoveBoard(const char* const* const board, char* const* const lastMoveBoard, int size, bool& back)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			lastMoveBoard[i][j] = board[i][j];
		}
	}
	back = true;
}

void printRules()
{
	cout << "Viking Chess Rules" << endl;
	cout << "1. The attacking side moves first." << endl;
	cout << "2. All pieces move like a Chess rook—in straight lines over empty squares." << endl;
	cout << "3. Pieces cannot jump over others or move diagonally." << endl;
	cout << "4. A piece is captured if trapped between two opponent pieces and is removed immediately." << endl;
	cout << "5. The King cannot capture other pieces." << endl;
	cout << "6. A piece next to a corner square can be captured by a single opponent if trapped against the corner." << endl;
	cout << "7. A piece can safely move between two opponent pieces without being captured." << endl;
	cout << "8. The King is captured only when surrounded on all four sides, or three if at the board’s edge." << endl;
	cout << "9. Only the King can enter a corner square - this move wins the game." << endl;
	cout << endl;


}
void printHelp()
{
	cout << "Move - move a piece" << endl;
	cout << "Back - undoes the last move" << endl;
	cout << "Rules - shows the game rules" << endl;
	cout << "Info - shows the game info" << endl;
	cout << "Quit - ends the game" << endl;
	cout << endl;
}

void printMove(int moveCount)
{
	cout << "Moves played: " << moveCount << endl;
}
void printPiecesCount(const char* const* const board, int size, bool attacker)
{
	int allPiecesCount = 12 * ((size / 2) - 2);
	int attackPieces = 0;
	int defencePieces = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == ATTACKER_SYMBOL)
			{
				attackPieces++;
			}
			else if (board[i][j] == DEFENDER_SYMBOL)
			{
				defencePieces++;
			}
		}
	}

	cout << "Attack pieces: " << attackPieces << endl;
	cout << "Defence pieces: " << defencePieces << endl;
	cout << "Captured pieces: " << allPiecesCount - attackPieces - defencePieces << endl;
}
void printInfo(const char* const* const board, int size, bool attacker, int moveCount)
{
	printPlayer(attacker);
	printMove(moveCount);
	printPiecesCount(board, size, attacker);
	cout << endl;
}

void quitGame(bool attacker, bool& quit)
{
	quit = true;

	system("cls");
	if (attacker)
	{
		cout << "Player1 has quit the game" << endl;
	}
	else
	{
		cout << "Player2 has quit the game" << endl;
	}
	cout << endl;
	cout << "Game over" << endl;
}

bool isPrefix(const char* text1, const char* text2)
{
	while (*text2)
	{
		if (*text1 != *text2)
		{
			return false;
		}
		text1++;
		text2++;
	}
	return true;
}
void chooseAction(char* const* const board, const char* const* const lastMoveBoard, int size, bool& attacker, int& moveCount, bool& quit, bool& back)
{
	system("cls");
	printBoard(board, size);

	char action[INPUT_LINE_LENGTH];
	while (true)
	{
		printPlayer(attacker);
		cout << "Please enter: move, back, help, info, rules or quit" << endl;
		cout << "Action: ";
		cin >> action;
		cout << endl;
		if (isPrefix(action, "move"))
		{
			break;
		}
		else if (isPrefix(action, "back"))
		{
			if (moveCount == 0)
			{
				cout << "No moves have been played" << endl;
				cout << endl;
			}
			else if (!back)
			{
				cout << "You cannot undo a move more than once" << endl;
				cout << endl;
			}
			else
			{
				returnLastMove(board, lastMoveBoard, size, attacker, moveCount, back);
			}
		}
		else if (isPrefix(action, "info"))
		{
			printInfo(board, size, attacker, moveCount);
		}
		else if (isPrefix(action, "help"))
		{
			printHelp();
		}
		else if (isPrefix(action, "rules"))
		{
			printRules();
		}
		else if (isPrefix(action, "quit"))
		{
			quitGame(attacker, quit);
			break;
		}
		else
		{
			cout << "Invalid input!" << endl;
			cout << endl;
		}
	}
}
