//definitions.hpp
//Quinton Graham
//Holds definitions for the project

#ifndef CHESS_DEFINITIONS_HPP
#define CHESS_DEFINITIONS_HPP

//Piece definitions
#define PIECE_MASK  0x0f
#define PAWN        0x01
#define ROOK        0x02
#define BISHOP      0x03
#define KNIGHT      0x04
#define QUEEN       0x05
#define KING        0x06
#define EMPTY_PIECE 0x00

//Definition for flag of if piece was moved (Used for castling and pawns)
#define MOVED       0x10

//Definitions for player 1 and player 2
#define PLAYER_MASK     0x60
#define PLAYER_1        0x20
#define PLAYER_WHITE    0x20
#define PLAYER_2        0x40
#define PLAYER_BLACK    0x40

#endif //CHESS_DEFINITIONS_HPP
