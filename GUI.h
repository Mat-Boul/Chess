
#ifndef CHESS_GUI_H
#define CHESS_GUI_H
#include "SFML/Graphics.hpp"
#include <string>
#include <unordered_map>
#include "ChessGame.h"


struct drawableObjects
{
    sf::Texture texture;
    sf::Sprite  sprite;
};


class GUI
        {
        public:
            GUI(int width, int height, std::string title, ChessGame& game);
            void run();
            void drawSprites();
            const float scale_pieces = 1.5f;
            static const int sprite_offset = 49;
        private:
            int getIndexFromPosition(int x , int y);
            sf::Vector2f getPositionFromIndex(int index);
            sf::RenderWindow m_MainWindow;
            std::unordered_map<char,drawableObjects> m_DrawableObjects;
            ChessGame m_Game;

        };
#endif //CHESS_GUI_H
