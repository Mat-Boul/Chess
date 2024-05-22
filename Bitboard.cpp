
#include "Bitboard.h"
Bitboard::Bitboard():m_Piece('\0'){}
Bitboard::Bitboard(char piece, const std::vector<int>& indexes):m_Piece(piece)
{
    for (auto &index : indexes)
    {
        m_Board.set(index);
    }

}
Bitboard::Bitboard(const Bitboard &other):m_Piece(other.m_Piece),m_Board(other.m_Board) {}

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

void Bitboard::removePiece(int index)
{
    this->m_Board.reset(index);
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

bool Bitboard::test(int index)
{
    return this->m_Board.test(index);
}

Bitboard Bitboard::get_slides(int index)
{
    Bitboard curr(*this);
    Bitboard Horizontal;
    Bitboard Vertical;
    int row = index/8;
    int col = index%8;
    for (int j = 0 ; j < 8 ; j++)
    {
        if (j <row)
        {
            Vertical |= curr >>8*(j+1);

        }
        else
        {
            Vertical |= curr<<8*(j-row);
        }
        if (j < col)
        {
            Horizontal |= curr >> 1*(j+1);
        }
        else
        {
            Horizontal |= curr << 1*(j-col);
        }
    }
    return curr |= Vertical | Horizontal;
}

Bitboard Bitboard::get_diagonals(int index)
{
    Bitboard curr(*this);
    Bitboard TL;
    Bitboard TR;

    int col = index%8;

    for (int i = 0 ; i < 8 ; i++)
    {
        if (i < col)
        {
            TL |= curr >> 9*(i+1);
            TR |= curr << 7*(i+1);
        }
        else
        {
            TL |= curr << 9*(i-col);
            TR |= curr >> 7*(i-col);
        }
    }



    return curr|= TL | TR;
}

Bitboard Bitboard::get_Ls(int index)
{
    Bitboard curr(*this);
    return curr;
}

Bitboard Bitboard::operator<<(int pos)
{
    Bitboard curr(*this);
    curr<<=pos;
    return curr;
}

Bitboard Bitboard::operator>>(int pos)
{
    Bitboard curr(*this);
    curr>>=pos;
    return curr;
}

Bitboard Bitboard::operator&(const Bitboard &other)
{
    Bitboard curr(*this);
    curr &=other;
    return curr;
}


Bitboard Bitboard::operator|(const Bitboard &other)
{
    Bitboard curr(*this);
    curr |= other;
    return curr;
}

Bitboard& Bitboard::operator&=(const Bitboard& other)
{
    this->m_Board &= other.m_Board;
    return *this;
}

Bitboard& Bitboard::operator|=(const Bitboard& other)
{
   this->m_Board |= other.m_Board;
   return *this;
}

Bitboard &Bitboard::operator~()
{
    this->m_Board.flip();
    return *this;
}

Bitboard &Bitboard::operator>>=(int pos)
{
    this->m_Board >>= pos;
    return *this;
}

Bitboard &Bitboard::operator<<=(int pos)
        {
    this->m_Board <<= pos;
    return *this;
        }
