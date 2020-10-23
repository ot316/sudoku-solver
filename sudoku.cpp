#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in) {
    cout << "Failed!" << '\n';
  }
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3)) {
    cout << "  +===========+===========+===========+" << '\n';
  } else {
    cout << "  +---+---+---+---+---+---+---+---+---+" << '\n';
  }
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << '\n';
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) {
    cout << (char) ('1'+r) << "   ";
  }
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */

/*========================= QUESTION 1 =============================
check if board is complete function */
bool is_complete(char board[9][9])
{
	// Iterate through rows
	for (int row_index = 0; row_index < 9; row_index++)
	{
		// Iterate through columns
		for (int col_index = 0; col_index < 9; col_index++)
		{
			if (!isdigit(board[row_index][col_index]))
				return false;
		}
	}
	return true;
}
/* End of function Definition */


/*========================= QUESTION 2 =============================
check if a move is valid */
bool make_move(const char* position, const char digit, char board[9][9])
{
	// test input is within range
	if (position[0] < 'A' || position[0] > ('A' + 9))
		return false;
	if (position[1] < '1' || position[1] > '9')
		return false;
	
	// convert characters to integers indexed from 0
	int guess = (int)(digit - 48);
	int col_guess = (int)(position[0] - 65); 
	int row_guess = (int)(position[1] - 49); A
	int i, j;
	cout << "guessing " << col_guess+1 << " " << row_guess+1 << endl;	
	// check if the board is filled at the given coordinates
	if (board[row_guess][col_guess] != '.')
		return false;
	
	// check if digit appears in row
	for (i = 0; i < 9; i++)
	{
		if (board[col_guess][i] == digit)
			return false;
	}

	// check if digit appears in column
	for (i = 0; i < 9; i++)
	{
		if (board[i][row_guess] == digit)
			return false;
	}

	/* check if digit appears in the box without re-checking columns or rows.
	check up and to the left */
	for (i = 1; i <= (row_guess % 3); i++)
	{
		for (j = 1; j <= (col_guess % 3); j++)
		{
			cout << "checked up left " << col_guess -j + 1 << ',' << row_guess - i + 1 << endl;
			if (board[col_guess - j][row_guess - i] == digit)
				return false;
		}
	}

	// check down and to the left
	for (i = 1; i <= (row_guess % 3); i++)
	{
		for (j = 1; j <= (2 - (col_guess % 3)); j++)
		{
			cout << "checked down right " << col_guess + j + 1 << ',' << row_guess - i + 1 << endl;
			if (board[col_guess + j][row_guess - i] == digit)
				return false;
		}
	}

	//check up and to the right 
	for (i = 1; i <= (2 - (row_guess % 3)); i++)
	{
		for (j = 1; j <= (col_guess % 3); j++)
		{
			cout << "checked up right " << col_guess - j + 1 << ',' << row_guess + i + 1 << endl;
			if (board[col_guess - j][row_guess + i] == digit)
				return false;
		}
	}
	
	// check down and to the right
	for (i = 1; i <= (2 - (row_guess % 3)); i++)
	{
		for (j = 1; j <= (2 - (col_guess % 3)); j++)
		{
			cout << "checked down right " << col_guess + j + 1 << ',' << row_guess + i + 1 << endl;
			if (board[col_guess + j][row_guess + i] == guess)
				return false;
		}
	}

	// if all checks have passed return true
	board[col_guess][row_guess] = digit;
	return true;
}
/* End of function Definition */


/*========================= QUESTION 3 =============================*/
/* save board as filename */
bool save_board()
{
	return false;
}
	/* End of function Definition */


/*========================= QUESTION 4 =============================*/
/* solve board and return completed board */
bool solve_board()
{
	return false;
}
/* End of function Definition */

