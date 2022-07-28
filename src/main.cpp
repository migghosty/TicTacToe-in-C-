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
		std::cin >> pos;
	}

	return pos-1;
}



int main() {
	char board[9];
	for (int i=0; i < 9; i++) {
		board[i] = (char)(i+'1');
	}
	int player = 1;

	while (true) {
		printBoard(board);
		board[getPlayerPosition(player, board)] = (player == 1) ? 'x' : 'o';
		player = (player == 1) ? 2 : 1;
	}


	return 0;
}
