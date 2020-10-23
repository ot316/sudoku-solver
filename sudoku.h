void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);

/* Function to check if the board is complete */
bool is_complete(char board[9][9]);

/* check if a move is valid */
bool make_move(const char* position, const char digit, char board[9][9]);

/* save board as filename */
bool save_board();

/* solve board and return completed board */
bool solve_board();
