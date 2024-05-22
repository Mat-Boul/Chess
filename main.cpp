#include <iostream>
#include "ChessGame.h"
#include "GUI.h"
#include "Bitboard.h"
int main() {
    std::string fen  = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    ChessGame test(fen);
    GUI TESTUI = GUI(904,903,"TESTTEST",test);
    TESTUI.run();
    return 0;
}
