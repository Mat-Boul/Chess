//
// Created by mathi on 5/15/2024.
//

#ifndef CHESS_BITBOARD_H
#define CHESS_BITBOARD_H

#include <bitset>
#include <vector>
#include <iostream>


class Bitboard{


    public:
        Bitboard(char piece, const std::vector<int>& indexes);
        const std::bitset<64>& getBoard() const;
        char getPiece() const;
        void setPiece(int index);

        //debug fonctions
        void printBoard();

    private:
        char m_Piece;
        std::bitset<64> m_Board;
};

#endif //CHESS_BITBOARD_H