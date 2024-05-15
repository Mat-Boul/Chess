

#include "ChessGame.h"

ChessGame::ChessGame(const std::string &fen)
{
    std::string pieces_fen = fen.substr(0,fen.find(' '));
    int current_index = 0;
    for (auto &pieces : pieces_fen)
    {
        if (std::isalpha(pieces))
        {
            if(this->m_BoardStates.find(pieces) == this->m_BoardStates.end())
            {
                this->m_BoardStates.insert(std::make_pair(pieces, Bitboard(pieces, {current_index})));
            }else
            {
                this->m_BoardStates.at(pieces).setPiece(current_index);
            }
            current_index++;
        }
        if(std::isdigit(pieces))
        {
            current_index += int(pieces)-48;
        }
    }


}

const std::unordered_map<char,Bitboard> &ChessGame::getBoardStates() const
{
    return this->m_BoardStates;
}

void ChessGame::printGameState()
{
    int num_of_boards=0;
    for (auto &boards : this->m_BoardStates)
    {
        std::cout<<boards.first<<std::endl;
        boards.second.printBoard();
        std::vector<int> index = boards.second.getPieceIndexes();
        for(auto &indexes:index)
        {
            std::cout<<std::endl <<indexes<<std::endl;
        }
        std::cout<<std::endl;
        num_of_boards++;
    }
    std::cout<<"Number of boards : " << num_of_boards << std::endl;
}
