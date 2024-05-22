

#include "ChessGame.h"

ChessGame::ChessGame(const std::string &fen)
{
    std::vector<char> piece = {'r','b','n','k','q','p','R','B','N','K','Q','P'};
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

    for (char &pie : piece)
    {
        std::vector<Bitboard> moves(64);
        for (int i = 0 ; i <64 ; i++)
        {
            Bitboard curr(pie, {i});
            switch(pie)
            {
                case 'P':
                    curr >>= 8;
                    moves[i] = curr;
                    break;
                case 'p':
                    curr <<= 8;
                    moves[i] = curr;
                    break;
                case 'R':
                case 'r':
                    moves[i]= curr.get_slides(i);
                    break;
                case 'B':
                case 'b':
                    moves[i] = curr.get_diagonals(i);
                    break;
                case 'Q':
                case 'q':
                    moves[i] = curr.get_diagonals(i) | curr.get_slides(i);
                    break;
                case 'N':
                case 'n':
                    curr = curr.get_Ls(i);
                    std::cout << " INDEX : " << i <<std::endl;
                    curr.printBoard();
                    std::cout<<std::endl;
                    break;
                default:
                    break;


            }
        }
        this->m_Precomp.insert(std::make_pair(pie,moves));
    }
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
    return ' ';
}

void ChessGame::make_move(int source_index, int destination_index)
{
    if (source_index == destination_index)
    {
        return;
    }
    char piece = get_piece_from_index(source_index);
    if (this->m_BoardStates.find(piece) == this->m_BoardStates.end())
    {
        return;
    }
    bool condition = this->m_Precomp.at(piece)[source_index].test(destination_index) && (this->m_BoardStates.at('0').test(destination_index));
    if (condition) {
        this->m_BoardStates.at(piece).removePiece(source_index);
        this->m_BoardStates.at(piece).setPiece(destination_index);

        this->m_BoardStates.at('0').setPiece(source_index);
        this->m_BoardStates.at('0').removePiece(destination_index);
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
