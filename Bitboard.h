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
        Bitboard();
        Bitboard(char piece, const std::vector<int>& indexes);
        Bitboard(const Bitboard& other);
        const std::bitset<64>& getBoard() const;
        std::vector<int> getPieceIndexes() const;
        char getPiece() const;
        void setPiece(int index);
        void removePiece(int index);
        bool test(int index);
        Bitboard& operator&=(const Bitboard& other);
        Bitboard& operator|=(const Bitboard& other);
        Bitboard& operator<<=(int pos);
        Bitboard& operator>>=(int pos);
        Bitboard operator>>(int pos);
        Bitboard operator<<(int pos);
        Bitboard& operator~();

        //debug fonctions
        void printBoard();

    private:
        char m_Piece;
        std::bitset<64> m_Board;
};

#endif //CHESS_BITBOARD_H
