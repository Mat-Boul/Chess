#include <iostream>
#include "Bitboard.hpp"
int main() {
    std::string fen  = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Bitboard Test('r', {1,2,3,4,5});
    Test.printBoard();
    return 0;
}
