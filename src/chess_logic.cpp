//chess_logic.cpp
//Quinton Graham
//Implements the chess logic functions.

#include "chess_logic.hpp"

//Function to check if a move is valid
bool is_valid_move(const unsigned char board[8][8], int current_x, int current_y, int new_x, int new_y)
{
    unsigned char player = board[current_x][current_y] & 0x60;
    unsigned char piece  = board[current_x][current_y] & 0x0f;
    unsigned char moved  = board[current_x][current_y] & 0x10;

    //check if destination location is an ally piece
    if(board[new_x][new_y] & 0x60 == player)
    {
        return false;
    }

    //check if the move is valid for the piece being moved
    switch(piece)
    {
        case PAWN:
            break;
        case ROOK:
            break;
        case BISHOP:
            break;
        case KNIGHT:
            break;
        case QUEEN:
            break;
        case KING:
            break;
        default:
            /* -- location for future implementation of custom pieces -- */
            break;
    }

    

    //check if new location will put the current player in check
    

    return true;
}

//Function to see if a position is directly horizontal
bool is_horizontal(int current_x, int current_y, int new_x, int new_y)
{
    if(current_y == new_y)
    {
        return true;
    }
    return false;
}

//Function to see if a position is directly vertical
bool is_vertical(int current_x, int current_y, int new_x, int new_y)
{
    if(current_x == new_x)
    {
        return true;
    }
    return false;
}

//Function to see if a position is directly diagonal
bool is_diagonal(int current_x, int current_y, int new_x, int new_y)
{
    int dif_x = current_x - new_x;
    int dif_y = current_y - new_y;
    
    if(dif_x < 0)
    {
        dif_x = dif_x - dif_x - dif_x;
    }
    if(dif_y < 0)
    {
        dif_y = dif_y - dif_y - dif_y;
    }

    if(dif_x == dif_y)
    {
        return true;
    }
    return false;
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
