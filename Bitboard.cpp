
#include "Bitboard.h"
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

std::vector<int> Bitboard::getPieceIndexes() const
{
    std::vector<int> result;
    int current_index = 0;
    if (this->m_Board[0] == 1){result.push_back(0);}
    while(current_index!= this->m_Board.size())
    {
        current_index = this->m_Board._Find_next(current_index);
        if (current_index != this->m_Board.size()){result.push_back(current_index);}
    }
    return result;
}
void Bitboard::setPiece(int index)
{
    this->m_Board.set(index);
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
