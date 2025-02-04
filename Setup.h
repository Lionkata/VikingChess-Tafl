#pragma once

using namespace std;

void printWelcome()
{
	cout << "Welcome to Viking Chess" << endl;
	cout << endl;
}

void chooseSize(int& size)
{
	cout << "Choose board size" << endl;
	cout << "1. 7x7" << endl;
	cout << "2. 9x9" << endl;
	cout << "3. 11x11" << endl;
	cout << "4. 13x13" << endl;
	int option;
	while (true)
	{
		cout << "Option: ";
		cin >> option;
		if (option < 1 || option > 4)
		{
			cout << "Invalid input!" << endl;
			cout << endl;
		}
		else
		{
			break;
		}
	}
	cout << endl;

	switch (option)
	{
	case 1: size = 7; break;
	case 2: size = 9; break;
	case 3: size = 11; break;
	case 4: size = 13; break;
	}
}

void initializeBoard(char** const board, int size)
{
	for (int i = 0; i < size; i++)
	{
		board[i] = new char[size];
		for (int j = 0; j < size; j++)
		{
			board[i][j] = BLANK_SYMBOL;
		}
	}
}

void placeKing(char** const board, int size)
{
	int king = size / 2;
	board[king][king] = KING_SYMBOL;
}
void placeAttackers(char** board, int size)
{
	int king = size / 2;

	for (int i = 0; i < size; i++)
	{
		if (i == 0 || i == size - 1)
		{
			board[i][king] = ATTACKER_SYMBOL;
			board[king][i] = ATTACKER_SYMBOL;
		}
		else if (i == king)
		{
			board[0][i] = ATTACKER_SYMBOL;
			board[size - 1][i] = ATTACKER_SYMBOL;
		}
		if (i == 1 || i == size - 2)
		{
			board[i][king] = ATTACKER_SYMBOL;
			board[king][i] = ATTACKER_SYMBOL;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (i > 2 && i < size - 3)
		{
			board[0][i] = ATTACKER_SYMBOL;
			board[size - 1][i] = ATTACKER_SYMBOL;
			board[i][0] = ATTACKER_SYMBOL;
			board[i][size - 1] = ATTACKER_SYMBOL;
		}
	}
}
void placeThrones(char** board, int size)
{
	board[0][0] = THRONE_SYMBOL;
	board[0][size - 1] = THRONE_SYMBOL;
	board[size - 1][0] = THRONE_SYMBOL;
	board[size - 1][size - 1] = THRONE_SYMBOL;
}
void placeDefenders(char** board, int size)
{
	int king = size / 2;

	board[king - 1][king] = DEFENDER_SYMBOL;
	board[king + 1][king] = DEFENDER_SYMBOL;
	board[king][king - 1] = DEFENDER_SYMBOL;
	board[king][king + 1] = DEFENDER_SYMBOL;

	if (size >= 9)
	{
		board[king][king - 2] = DEFENDER_SYMBOL;
		board[king][king + 2] = DEFENDER_SYMBOL;
		board[king - 2][king] = DEFENDER_SYMBOL;
		board[king + 2][king] = DEFENDER_SYMBOL;
	}

	if (size >= 11)
	{
		board[king - 1][king - 1] = DEFENDER_SYMBOL;
		board[king + 1][king + 1] = DEFENDER_SYMBOL;
		board[king - 1][king + 1] = DEFENDER_SYMBOL;
		board[king + 1][king - 1] = DEFENDER_SYMBOL;
	}

	if (size == 13)
	{
		board[king - 3][king] = DEFENDER_SYMBOL;
		board[king][king + 3] = DEFENDER_SYMBOL;
		board[king + 3][king] = DEFENDER_SYMBOL;
		board[king][king - 3] = DEFENDER_SYMBOL;
	}
}
void placePiecesOnBoard(char** board, int size)
{
	placeKing(board, size);
	placeAttackers(board, size);
	placeThrones(board, size);
	placeDefenders(board, size);
}

void printBoard(const char* const* const board, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << board[i][j] << ' ';
			if (j == size - 1)
			{
				cout << "| " << i + 1;
			}
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++)
	{
		cout << "--";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << (char)('a' + i) << ' ';
	}
	cout << endl;
	cout << endl;
}
void printPlayer(bool attacker)
{
	if (attacker)
	{
		cout << "Player1 - Attacker" << endl;
	}
	else
	{
		cout << "Player2 - Deffender" << endl;
	}
}
