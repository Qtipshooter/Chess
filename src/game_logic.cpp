//game_logic.cpp
//Quinton Graham
//Implements the game logic functions.

//Function to check if a move is valid
bool is_valid_move(const unsigned char board[8][8], int current_x, int current_y, int new_x, int new_y)
{
    unsigned char player = board[current_x][current_y] & 0x60;
    unsigned char piece  = board[current_x][current_y] & 0x0f;

    //check if destination location is an ally piece
    if(board[new_x][new_y] & 0x60 == player)
    {
        return false;
    }

    //check if the move is valid for the piece being moved

    //check if new location will put the current player in check
    

    return true;
}

//Function to check if a player is in check
bool is_check(const unsigned char board[8][8], unsigned char player)
{
    //return
}

//Function to check if a player is in checkmate
bool is_checkmate(const unsigned char board[8][8], unsigned char player)
{
    //return
}

//Function that returns a new proposed board layout
unsigned char*** get_proposed_board(const unsigned char board[8][8], int current_x, int current_y, int new_x, int new_y)
{
    //return
}
