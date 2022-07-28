#include <iostream>
#include <string>

void printBoard(char board[]) {
	for (int i=0; i < 3; i++) {
		for (int j=0; j < 3; j++) {
			std::cout << " " << board[i*3+j] << " ";
			if (j != 2) {
				std::cout << "|";
			}
		}
		std::cout << std::endl;
		if (i != 2) {
			for (int k=0; k < 11; k++) {
				if (k == 3 || k == 7) {
					std::cout << "+";
				}
				else {
					std::cout << "-";
				}

			}
		}
		std::cout << std::endl;
	}
}

int getPlayerPosition(int player, char board[]) {
	int pos = 0;

	std::cout << "Player " << player << ", enter a number: ";
	std::cin >> pos;

	while (pos < 1 || pos > 9 || board[pos-1] != (char)(pos+'0')) {
		std::cout << "Invalid position" << std::endl;
		std::cout << "Player " << player << ", enter a number: ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> pos;

	}

	return pos-1;
}

int gameOver(char board[]) {
	// check rows
	if (board[0] == board[1] && board[0] == board[2])
		return 1;
	if (board[3] == board[4] && board[3] == board[5])
		return 1;
	if (board[6] == board[7] && board[6] == board[8])
		return 1;

	// check columns
	if (board[0] == board[3] && board[0] == board[6])
		return 1;
	if (board[1] == board[4] && board[1] == board[7])
		return 1;
	if (board[2] == board[5] && board[2] == board[8])
		return 1;

	// check diagonals
	if (board[0] == board[4] && board[0] == board[8])
		return 1;
	if (board[2] == board[4] && board[2] == board[6])
		return 1;

	// check for draw
	for (int i=0; i < 9; i++) {
		if (board[i] == (char)(i+'1')) {
			return 0;
		}
	}

	return -1;
}

int main() {
	char board[9];
	for (int i=0; i < 9; i++) {
		board[i] = (char)(i+'1');
	}
	int player = 1;

	while (!gameOver(board)) {
		printBoard(board);
		board[getPlayerPosition(player, board)] = (player == 1) ? 'x' : 'o';
		player = (player == 1) ? 2 : 1;
	}

	if (gameOver(board) == -1)
		std::cout << "It's a tie!" << std::endl;

	else
		std::cout << "Player " << ((player == 1) ? "2" : "1") << " wins!" << std::endl;
	return 0;
}
