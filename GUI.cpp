
#include "GUI.h"
GUI::GUI(int width, int height, std::string title,ChessGame& game):m_MainWindow(sf::RenderWindow(sf::VideoMode(width,height),title)),m_Game(game)
{
    drawableObjects background;
    this->m_DrawableObjects.insert(std::make_pair('0',background));
    this->m_DrawableObjects.at('0').texture.loadFromFile("C:\\Dev\\Chess\\assets\\board.PNG");
    this->m_DrawableObjects.at('0').sprite.setTexture(this->m_DrawableObjects.at('0').texture);

    std::vector<std::string> pieces_identifiers = {"bishop","king","night","pawn","queen","rook"};

    for (std::string &ident : pieces_identifiers)
    {
        drawableObjects curr_obj;
        this->m_DrawableObjects.insert(std::make_pair(std::toupper(ident[0]),curr_obj));
        this->m_DrawableObjects.at(std::toupper(ident[0])).texture.loadFromFile("C:\\Dev\\Chess\\assets\\pieces\\black_"+ident+".png");
        this->m_DrawableObjects.at(std::toupper(ident[0])).texture.setSmooth(true);
        this->m_DrawableObjects.at(std::toupper(ident[0])).sprite.setTexture(this->m_DrawableObjects.at(std::toupper(ident[0])).texture);
        this->m_DrawableObjects.at(std::toupper(ident[0])).sprite.setScale(scale_pieces,scale_pieces);
    }
    for (std::string &ident : pieces_identifiers)
    {
        drawableObjects curr_obj;
        this->m_DrawableObjects.insert(std::make_pair(ident[0],curr_obj));
        this->m_DrawableObjects.at(ident[0]).texture.loadFromFile("C:\\Dev\\Chess\\assets\\pieces\\white_"+ident+".png");
        this->m_DrawableObjects.at(ident[0]).texture.setSmooth(true);
        this->m_DrawableObjects.at(ident[0]).sprite.setTexture(this->m_DrawableObjects.at(ident[0]).texture);
        this->m_DrawableObjects.at(ident[0]).sprite.setScale(scale_pieces,scale_pieces);
    }
}

int GUI::getIndexFromPosition(int x, int y)
{
    int row = y/113;
    int col = x/113;
    return row + col + 7*row;
}

sf::Vector2f GUI::getPositionFromIndex(int index)
{
    return sf::Vector2f ((index%8+1)*113-56-sprite_offset,(int(index/8)+1)*113-56-sprite_offset);
}

void GUI::drawSprites()
{
    this->m_MainWindow.clear();
    this->m_MainWindow.draw(this->m_DrawableObjects.at('0').sprite);
    for(auto &board : this->m_Game.getBoardStates())
    {
        for (auto &index: board.second.getPieceIndexes())
        {
            if (board.first != '0') {
                this->m_DrawableObjects.at(board.first).sprite.setPosition(getPositionFromIndex(index));
                this->m_MainWindow.draw(this->m_DrawableObjects.at(board.first).sprite);
            }
        }
    }

}

void GUI::run()
{
    int start_index = -1;
    bool left_clicked = false;
    while(this->m_MainWindow.isOpen())
    {
        sf::Event event;

        while (this->m_MainWindow.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    this->m_MainWindow.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button==sf::Mouse::Left)
                    {
                        start_index = getIndexFromPosition(event.mouseButton.x,event.mouseButton.y);
                        left_clicked=true;
                    }
                    break;
                case sf::Event::MouseButtonReleased:
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (left_clicked && start_index !=-1)
                        {
                            this->m_Game.make_move(start_index, getIndexFromPosition(event.mouseButton.x,event.mouseButton.y));
                            left_clicked = false;
                            start_index = -1;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        this->drawSprites();
        this->m_MainWindow.display();
    }
}