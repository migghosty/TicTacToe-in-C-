#include <iostream>
#include <string>

void printBoard(char arr[]) {
	for (int i=0; i < 3; i++) {
		for (int j=0; j < 3; j++) {
			std::cout << " " << arr[i*3+j] << " ";
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

int main() {

	char board[9];
	for (int i=0; i < 9; i++) {
		board[i] = (char)(i+'1');
	}

	printBoard(board);

	return 0;
}
