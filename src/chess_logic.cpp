//chess_logic.cpp
//Quinton Graham
//Implements the chess logic functions.

#include "definitions.hpp"
#include "chess_logic.hpp"

//Function to check if a move is valid
bool is_valid_move(const unsigned char board[8][8], int current_x, int current_y, int new_x, int new_y)
{
    //get variables for the tests
    unsigned char player = board[current_x][current_y] & PLAYER_MASK;
    unsigned char piece  = board[current_x][current_y] & PIECE_MASK;
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
            if(!is_horizontal(current_x, current_y, new_x, new_y) && !is_vertical(current_x, current_y, new_x, new_y))
            {
                return false;
            }
            if(is_blocked(board, current_x, current_y, new_x, new_y))
            {
                return false;
            }
            break;
        case BISHOP:
            if(!is_diagonal(current_x, current_y, new_x, new_y))
            {
                return false;
            }
            if(is_blocked(board, current_x, current_y, new_x, new_y))
            {
                return false;
            }
            break;
        case KNIGHT:
            if(!(get_diff(current_x, new_x) == 2 && get_diff(current_y, new_y) == 1)\
            || !(get_diff(current_x, new_x) == 1 && get_diff(current_y, new_y) == 2))
            {
                return false;
            }
            break;
        case QUEEN:
            if(!is_horizontal(current_x, current_y, new_x, new_y) && !is_vertical(current_x, current_y, new_x, new_y) && !is_diagonal(current_x, current_y, new_x, new_y))
            {
                return false;
            }
            if(is_blocked(board, current_x, current_y, new_x, new_y))
            {
                return false;
            }
            break;
        case KING:
            /* -- Check for castling here!!! -- */
            if(get_diff(current_x, new_x) > 1 || get_diff(current_y, new_y) > 1)
            {
                return false;
            }
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

//Function to check if a move is blocked by a piece
bool is_blocked(const unsigned char board[8][8], int current_x, int current_y, int new_x, int new_y)
{
    if(is_horizontal(current_x, current_y, new_x, new_y)) 
    {
        if(current_x < new_x) 
        {
            for (int x = current_x; x < new_x; x++) 
            {
                if(current_x == x) 
                {
                    continue;
                }
                else if(board[x][current_y] != 0x00) 
                {
                    return true;
                }
            }
        }
        else 
        {
            for (int x = current_x; x > new_x; x--) 
            {
                if(current_x == x) 
                {
                    continue;
                }
                else if(board[x][current_y] != 0x00) 
                {
                    return true;
                }
            }
        }
    }
    else if(is_vertical(current_x, current_y, new_x, new_y))
    {
        if(current_y < new_y) 
        {
            for (int y = current_y; y < new_y; y++) 
            {
                if(current_y == y) 
                {
                    continue;
                }
                else if(board[current_x][y] != 0x00) 
                {
                    return true;
                }
            }
        }
        else 
        {
            for (int y = current_y; y > new_y; y--) 
            {
                if(current_y == y) 
                {
                    continue;
                }
                else if(board[current_x][y] != 0x00) 
                {
                    return true;
                }
            }
        }
    }
    else //is_diagonal
    {
        bool asc_x = false;
        bool asc_y = false;
        if(current_x < new_x)
        {
            asc_x = true;
        }
        if(current_y < new_y)
        {
            asc_y = true;
        }
        
        if (asc_x && asc_y)
        {
            for (int x = current_x, int y = current_y; x < new_x; x++, y++)
            {
                if(current_x == x)
                {
                    continue;
                }
                if(board[x][y] != 0x00)
                {
                    return true;
                }
            }
            
        }
        else if (asc_x && !asc_y)
        {
            for (int x = current_x, int y = current_y; x < new_x; x++, y--)
            {
                if(current_x == x)
                {
                    continue;
                }
                if(board[x][y] != 0x00)
                {
                    return true;
                }
            }
            
        }
        else if (!asc_x && asc_y)
        {
            for (int x = current_x, int y = current_y; x > new_x; x--, y++)
            {
                if(current_x == x)
                {
                    continue;
                }
                if(board[x][y] != 0x00)
                {
                    return true;
                }
            }
            
        }
        else
        {
            for (int x = current_x, int y = current_y; x > new_x; x--, y--)
            {
                if(current_x == x)
                {
                    continue;
                }
                if(board[x][y] != 0x00)
                {
                    return true;
                }
            }
            
        }
        
    }
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

//Function to get the absolute value of the difference between two numbers
int get_diff(int num_1, int num_2)
{
    int diff = num_1 - num_2;
    if(diff < 0)
    {
        return diff - diff - diff;
    }
    return diff;
}

//Function that returns a new proposed board layout
unsigned char*** get_proposed_board(const unsigned char board[8][8], int current_x, int current_y, int new_x, int new_y)
{

    //return
}
