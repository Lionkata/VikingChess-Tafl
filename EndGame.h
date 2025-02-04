#pragma once

bool isCorner(int row, int cols, int size)
{
	if (row == 0 && (cols == 0 || cols == size - 1))
	{
		return true;
	}
	else if (row == size - 1 && (cols == 0 || cols == size - 1))
	{
		return true;
	}
	return false;
}
bool isKingOnThrone(const char* const* const board, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == KING_SYMBOL && isCorner(i, j, size))
			{
				return true;
			}
		}
	}
	return false;
}
bool isKingTrapped(const char* const* const board, int size)
{
	int kingRowIndex;
	int kingColIndex;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == KING_SYMBOL)
			{
				kingRowIndex = i;
				kingColIndex = j;
			}
		}
	}

	bool blockedLeft = (kingColIndex == 0) || (board[kingRowIndex][kingColIndex - 1] == ATTACKER_SYMBOL);
	bool blockedRight = (kingColIndex == size - 1) || (board[kingRowIndex][kingColIndex + 1] == ATTACKER_SYMBOL);
	bool blockedUp = (kingRowIndex == 0) || (board[kingRowIndex - 1][kingColIndex] == ATTACKER_SYMBOL);
	bool blockedDown = (kingRowIndex == size - 1) || (board[kingRowIndex + 1][kingColIndex] == ATTACKER_SYMBOL);

	return blockedLeft && blockedRight && blockedUp && blockedDown;
}
bool isGameOver(const char* const* const board, int size)
{
	if (isKingOnThrone(board, size))
	{
		system("cls");
		cout << "Player2 wins" << endl;
		cout << endl;
		cout << "Game over" << endl;
		return true;
	}
	else if (isKingTrapped(board, size))
	{
		system("cls");
		cout << "Player1 wins" << endl;
		cout << endl;
		cout << "Game over" << endl;
		return true;
	}
	return false;
}

void deleteBoard(char**& board, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}
