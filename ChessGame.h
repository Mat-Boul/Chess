

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
            void make_move(int source_index , int destination_index);
            char get_piece_from_index(int index);
            //debug
            void printGameState();
        private:
            std::unordered_map<char,Bitboard> m_BoardStates;
        };
#endif //CHESS_CHESSGAME_H
