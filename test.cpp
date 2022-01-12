//test.cpp
//Quinton Graham
//The main test file at this time until I have a different way to go about it

#include "definitions.hpp"
#include "chess_logic.hpp"
#include <iostream>

int main(int argc, char * argv[])

{
    unsigned char board[8][8];
    print_board_to_cmd_line(board);
    std::cout << std::endl;
    set_to_initial_board(board);
    print_board_to_cmd_line(board);
    return 0;
}
