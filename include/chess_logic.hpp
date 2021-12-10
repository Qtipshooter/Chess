//game_logic.hpp
//Quinton Graham
//Handles the logic of the the game such as valid moves, check, mate, etc.

#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

/* informative functions */

//Function to check if a move is valid
bool is_valid_move(const unsigned char board[8][8], int current_x, int current_y, int new_x, int new_y);

//Function to check if a player is in check
bool is_check(const unsigned char board[8][8], unsigned char player);

//Function to check if a player is in checkmate
bool is_checkmate(const unsigned char board[8][8], unsigned char player);

//Function to see if a piece has a valid move
bool has_valid_move(const unsigned char board[8][8], int current_x, int current_y);

//Function to locate the King of a particular player
unsigned char get_king(const unsigned char board[8][8], unsigned char player);

//Function that returns a new proposed board layout
unsigned char*** get_proposed_board(const unsigned char board[8][8], int current_x, int current_y, int new_x, int new_y);

#endif // GAME_LOGIC_HPP
