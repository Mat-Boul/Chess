
#include <bitset>
#include <vector>
#include <iostream>
class Bitboard{


public:
    Bitboard(char piece, const std::vector<int>& indexes);
    const std::bitset<64>& getBoard() const;
    char getPiece() const;

    //debug fonctions
    void printBoard();

private:
    char m_Piece;
    std::bitset<64> m_Board;
};