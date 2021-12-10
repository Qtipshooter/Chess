//chess_logic.cpp
//Quinton Graham
//Implements the chess logic functions.

#include "definitions.hpp"
#include "chess_logic.hpp"

//Function to check if a move is valid
bool is_valid_move(const unsigned char board[8][8], int current_x, int current_y, int new_x, int new_y)
{
    //get variables for the tests
    unsigned char player = board[current_x][current_y] & 0x60;
    unsigned char piece  = board[current_x][current_y] & 0x0f;
    unsigned char moved  = board[current_x][current_y] & MOVED;

    //check if destination location is an ally piece
    if(board[new_x][new_y] & 0x60 == player)
    {
        return false;
    }

    //check if the move is valid for the piece being moved
    /* -- If we implement a way to customize current pieces, that check will be made before the normal checks -- */
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

//Function to check if a player is in check
bool is_check(const unsigned char board[8][8], unsigned char player)
{
    unsigned char king_loc = get_king(board, player);
    int king_x = (int) king_loc >> 4;
    int king_y = (int) king_loc & 0x0f;
    //return
}

//Function to check if a player is in checkmate
bool is_checkmate(const unsigned char board[8][8], unsigned char player)
{
    unsigned char king_loc = get_king(board, player);
    int king_x = (int) king_loc >> 4;
    int king_y = (int) king_loc & 0x0f;

    //check if the king itself can move
    for (int x = king_x - 1; x < king_x + 1; x++)
    {
        for (int y = king_y - 1; y < king_y + 1; y++)
        {
            if(x == king_x && y == king_y)
            {
                if(!is_check(board, player))
                {
                    return false;
                }
            }
            else
            {
                if(is_valid_move(board, king_x, king_y, x, y))
                {
                    return true;
                }
            }
        }
    }

    //check if any other piece can block check or capture the piece
    
    //return
}

//Function to see if a piece has a valid move
bool has_valid_move(const unsigned char board[8][8], int current_x, int current_y)
{
    //return
}

//Function to locate the King of a particular player
unsigned char get_king(const unsigned char board[8][8], unsigned char player)
{
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            if(board[x][y] & KING == KING)
            {
                return (x << 4) + y;
            }
        }
    }

    return 0x00;
}

//Function that returns a new proposed board layout
unsigned char*** get_proposed_board(const unsigned char board[8][8], int current_x, int current_y, int new_x, int new_y)
{
    //return
}
