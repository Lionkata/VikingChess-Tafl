#pragma once

using namespace std;

int myMin(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int myMax(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
bool isPieceTrapped(const char* const* const board, int size, char pieceCol, int pieceRow)
{
	int pieceColIndex = pieceCol - 'a';
	int pieceRowIndex = pieceRow - 1;

	bool blockedLeft = (pieceColIndex == 0) || (board[pieceRowIndex][pieceColIndex - 1] != BLANK_SYMBOL);
	bool blockedRight = (pieceColIndex == size - 1) || (board[pieceRowIndex][pieceColIndex + 1] != BLANK_SYMBOL);
	bool blockedUp = (pieceRowIndex == 0) || (board[pieceRowIndex - 1][pieceColIndex] != BLANK_SYMBOL);
	bool blockedDown = (pieceRowIndex == size - 1) || (board[pieceRowIndex + 1][pieceColIndex] != BLANK_SYMBOL);

	return blockedLeft && blockedRight && blockedUp && blockedDown;
}
bool areValidPieceCoordinates(const char* const* const board, int size, bool attacker, char pieceCol, int pieceRow)
{
	int pieceRowIndex = pieceRow - 1;
	int pieceColIndex = pieceCol - 'a';

	if (pieceRowIndex < 0 || pieceRowIndex > size - 1)
	{
		cout << "Invalid input! Coordinates are out of bounds" << endl;
		return false;
	}
	else if (pieceColIndex < 0 || pieceColIndex > size - 1)
	{
		cout << "Invalid input! Coordinates are out of bounds" << endl;
		return false;
	}

	if (attacker && board[pieceRowIndex][pieceColIndex] == ATTACKER_SYMBOL)
	{
		if (isPieceTrapped(board, size, pieceCol, pieceRow))
		{
			cout << "Invalid input! This piece is trapped" << endl;
			return false;
		}
		return true;
	}
	else if (!attacker && (board[pieceRowIndex][pieceColIndex] == DEFENDER_SYMBOL || board[pieceRowIndex][pieceColIndex] == KING_SYMBOL))
	{
		if (isPieceTrapped(board, size, pieceCol, pieceRow))
		{
			cout << "Invalid input! This piece is trapped" << endl;
			return false;
		}
		return true;
	}

	cout << "Invalid input! You must select your own piece" << endl;
	return false;
}
bool areValidMoveCoordinates(const char* const* const board, int size, bool attacker, char moveCol, int moveRow, char pieceCol, int pieceRow)
{
	int moveRowIndex = moveRow - 1;
	int moveColIndex = moveCol - 'a';
	int pieceRowIndex = pieceRow - 1;
	int pieceColIndex = pieceCol - 'a';

	if (moveRowIndex < 0 || moveRowIndex >= size || moveColIndex < 0 || moveColIndex >= size)
	{
		cout << "Invalid input! Coordinates are out of bounds" << endl;
		cout << endl;
		return false;
	}

	if (board[moveRowIndex][moveColIndex] == THRONE_SYMBOL && board[pieceRowIndex][pieceColIndex] == KING_SYMBOL)
	{
		return true;
	}
	if (board[moveRowIndex][moveColIndex] != BLANK_SYMBOL)
	{
		cout << "Invalid input! Choose an empty position" << endl;
		cout << endl;
		return false;
	}

	if (pieceRowIndex != moveRowIndex && pieceColIndex != moveColIndex)
	{
		cout << "Invalid input! Pieces can only move in a straight line" << endl;
		cout << endl;
		return false;
	}

	if (pieceRowIndex == moveRowIndex)
	{
		int start = myMin(pieceColIndex, moveColIndex) + 1;
		int end = myMax(pieceColIndex, moveColIndex);
		for (int i = start; i < end; i++)
		{
			if (board[pieceRowIndex][i] != BLANK_SYMBOL)
			{
				cout << "Invalid input! Path is blocked" << endl;
				cout << endl;
				return false;
			}
		}
	}
	else if (pieceColIndex == moveColIndex)
	{
		int start = myMin(pieceRowIndex, moveRowIndex) + 1;
		int end = myMax(pieceRowIndex, moveRowIndex);
		for (int i = start; i < end; i++)
		{
			if (board[i][pieceColIndex] != BLANK_SYMBOL)
			{
				cout << "Invalid input! Path is blocked" << endl;
				cout << endl;
				return false;
			}
		}
	}

	return true;
}

void moveAPiece(char* const* const board, int size, bool attacker)

{
	char pieceCol, moveCol;
	int pieceRow, moveRow;
	while (true)
	{
		cout << "Piece coordinates: ";
		cin >> pieceCol >> pieceRow;
		if (areValidPieceCoordinates(board, size, attacker, pieceCol, pieceRow))
		{
			break;
		}
		cout << endl;
	}
	while (true)
	{
		cout << "Move coordinates: ";
		cin >> moveCol >> moveRow;
		if (areValidMoveCoordinates(board, size, attacker, moveCol, moveRow, pieceCol, pieceRow))
		{
			break;
		}
	}

	int pieceColIndex = pieceCol - 'a';
	int pieceRowIndex = pieceRow - 1;
	int moveColIndex = moveCol - 'a';
	int moveRowIndex = moveRow - 1;
	char movePieceSymbol = board[pieceRowIndex][pieceColIndex];
	board[pieceRowIndex][pieceColIndex] = BLANK_SYMBOL;
	board[moveRowIndex][moveColIndex] = movePieceSymbol;
}
