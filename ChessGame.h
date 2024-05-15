

#ifndef CHESS_CHESSGAME_H
#define CHESS_CHESSGAME_H


#include <string>
#include <unordered_map>

#include "Bitboard.h"
class ChessGame
        {
        public:
            ChessGame(const std::string& fen);
            const std::unordered_map<char,Bitboard>& getBoardStates() const;

            //debug
            void printGameState();
        private:
            std::unordered_map<char,Bitboard> m_BoardStates;
        };
#endif //CHESS_CHESSGAME_H
