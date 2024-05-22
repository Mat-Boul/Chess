

#include "ChessGame.h"

ChessGame::ChessGame(const std::string &fen)
{
    std::string pieces_fen = fen.substr(0,fen.find(' '));
    int current_index = 0;
    Bitboard empty = Bitboard('e',{});
    for (auto &pieces : pieces_fen)
    {
        if (std::isalpha(pieces))
        {
            if(this->m_BoardStates.find(pieces) == this->m_BoardStates.end())
            {
                Bitboard curr = Bitboard(pieces,{current_index});
                this->m_BoardStates.insert(std::make_pair(pieces, curr));
            }else
            {
                this->m_BoardStates.at(pieces).setPiece(current_index);
            }
            empty |= this->m_BoardStates.at(pieces);
            current_index++;
        }
        if(std::isdigit(pieces))
        {
            current_index += int(pieces)-48;
        }
    }
    empty = ~empty;
    this->m_BoardStates.insert(std::make_pair('0',empty));
    this->m_BoardStates.at('0').printBoard();
}

char ChessGame::get_piece_from_index(int index)
{
    for(auto &board : this->m_BoardStates)
    {
        if (board.second.getBoard().test(index))
        {
            return board.first;
        }
    }
    return '\0';
}

void ChessGame::make_move(int source_index, int destination_index)
{

    char piece = get_piece_from_index(source_index);
    if (this->m_BoardStates.find(piece) == this->m_BoardStates.end())
    {
        return;
    }

    this->m_BoardStates.at(piece).removePiece(source_index);
    this->m_BoardStates.at(piece).setPiece(destination_index);

    this->m_BoardStates.at('0').setPiece(source_index);
    this->m_BoardStates.at('0').removePiece(destination_index);

    this->m_BoardStates.at('0').printBoard();


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
