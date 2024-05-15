#include <iostream>
#include "ChessGame.h"
int main() {
    std::string fen  = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    ChessGame test(fen);
    test.printGameState();
    return 0;
}
