void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);

/* Function to check if the board is complete */
bool is_complete(char board[9][9]);

/* check if a move is valid */
bool make_move(const char* position, const char digit, char board[9][9]);

/* save board as filename */
bool save_board(const char* filename, char board[9][9]);

/* solve board and return completed board */
bool solve_board(char board[9][9]);

/* helper function to find the coordinates of the first empty square */
bool find_empty(char position[2], char board[9][9]);

void set_zero(char position[2], char board[9][9]);
