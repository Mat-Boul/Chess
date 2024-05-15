
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
        this->m_DrawableObjects.at(std::toupper(ident[0])).sprite.setTexture(curr_obj.texture);
    }
    for (std::string &ident : pieces_identifiers)
    {
        drawableObjects curr_obj;
        this->m_DrawableObjects.insert(std::make_pair(ident[0],curr_obj));
        this->m_DrawableObjects.at(ident[0]).texture.loadFromFile("C:\\Dev\\Chess\\assets\\pieces\\white_"+ident+".png");
        this->m_DrawableObjects.at(ident[0]).texture.setSmooth(true);
        this->m_DrawableObjects.at(ident[0]).sprite.setTexture(curr_obj.texture);
    }
}
void GUI::drawSprites()
{
    this->m_MainWindow.clear();
    this->m_MainWindow.draw(this->m_DrawableObjects.at('0').sprite);

}

void GUI::run()
{
    while(this->m_MainWindow.isOpen())
    {
        sf::Event event;
        while (this->m_MainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->m_MainWindow.close();
        }
        this->drawSprites();
        this->m_MainWindow.display();
    }
}