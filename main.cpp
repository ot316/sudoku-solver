#include <iostream>
#include <cstdio>
#include "sudoku.h"
#include <fstream>

using namespace std;

int main() {

	char board[9][9];

	/* This section illustrates the use of the pre-supplied helper functions. */
	cout << "============= Pre-supplied functions =============" << "\n\n";

	cout << "Calling load_board():" << '\n';
	load_board("easy.dat", board);

	cout << '\n' << "Displaying Sudoku board with display_board():" << '\n';
	display_board(board);
	cout << "Done!" << "\n\n";

	cout << "=================== Question 1 ===================" << "\n\n";

	load_board("easy.dat", board);
	cout << "Board is ";
	if (!is_complete(board)) {
		cout << "NOT ";
	}
	cout << "complete." << "\n\n";

	load_board("easy-solution.dat", board);
	cout << "Board is ";
	if (!is_complete(board)) {
		cout << "NOT ";
	}
	cout << "complete." << "\n\n";

	cout << "=================== Question 2 ===================" << "\n\n";

	load_board("easy.dat", board);

	// Should be OK
	cout << "Putting '1' into I8 is ";
	if (!make_move("I8", '1', board)) {
		cout << "NOT ";
	}
	cout << "a valid move. The board is:" << '\n';
	display_board(board);

	/* write more tests
	checking each number for random positions to compare visually, board must be reopened to prevent persistent changes */
	for (char i = '1'; i <= '9'; i++) {
		load_board("easy.dat", board);
		cout << "Putting " << i << " into I7 is ";
		if (!make_move("I7", i, board)) {
			cout << "NOT ";
		}
		cout << "a valid move." << endl;
	}

	cout << "=================== Question 3 ===================" << "\n\n";

	load_board("easy.dat", board);
	if (save_board("easy-copy.dat", board)) {
		cout << "Save board to 'easy-copy.dat' successful." << '\n';
	} else {
		cout << "Save board failed." << '\n';
	}
	cout << '\n';

	cout << "=================== Question 4 ===================" << "\n\n";

	load_board("easy.dat", board);
	if (solve_board(board)) {
		cout << "The 'easy' board has a solution:" << '\n';
		display_board(board);
	} else {
		cout << "A solution cannot be found." << '\n';
	}
	cout << '\n';

	load_board("medium.dat", board);
	if (solve_board(board)) {
		cout << "The 'medium' board has a solution:" << '\n';
		display_board(board);
	} else {
		cout << "A solution cannot be found." << '\n';
	}
	cout << '\n';

	/* write more tests
	   solve all 50 puzzles given in lots_of_puzzles.dat file */

	ifstream in("lots_of_puzzles.dat");
	if (!in) {
		cout << "Failed!" << '\n';
	}

	char buffer[512];
	in.getline(buffer,512);

	for (int i = 1; i <= 50; i++) {	
		int row = 0;
		in.getline(buffer,512);
		while (in && row < 9) {
			for (int n=0; n<9; n++) {
				board[row][n] = buffer[n];
			}
			in.getline(buffer,512);
			row++;
		}

		if (solve_board(board)) {
			cout << "\nPuzzle number '" << i << "' has a solution:" << '\n';
			display_board(board);
		} else {
			cout << "\nA solution cannot be found to puzzle number " << i << ".\n";
			display_board(board);
		}
	}

	cout << "=================== Question 5 ===================" << "\n\n";

	/* write more tests
	check the 3 mystery functions */

	load_board("mystery1.dat", board);
	if (solve_board(board)) {
		cout << "The 'mystery1.dat' board has a solution:" << '\n';
		display_board(board);
	} else {
		cout << "A solution cannot be found." << '\n';
	}
	cout << '\n';

	load_board("mystery2.dat", board);
	if (solve_board(board)) {
		cout << "The 'mystery2.dat' board has a solution:" << '\n';
		display_board(board);
	} else {
		cout << "A solution cannot be found." << '\n';
	}
	cout << '\n';

	load_board("mystery3.dat", board);
	if (solve_board(board)) {
		cout << "The 'mystery3.dat' board has a solution:" << '\n';
		display_board(board);
	} else {
		cout << "A solution cannot be found." << '\n';
	}
	cout << '\n';

	return 0; 
}

