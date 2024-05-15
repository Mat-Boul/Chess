
#include "Bitboard.hpp"
Bitboard::Bitboard(char piece, const std::vector<int>& indexes):m_Piece(piece)
{
    for (auto &index : indexes)
    {
        m_Board.set(index);
    }

}

const std::bitset<64> &Bitboard::getBoard() const
{
    return this->m_Board;
}

char Bitboard::getPiece() const
{
    return this->m_Piece;
}


void Bitboard::printBoard()
{
    for(int i = 0 ; i < 64;i++)
    {
        if (i%8 ==0)
        {
            std::cout<<std::endl;

        }
        std::cout<<this->m_Board[i];
    }
}
