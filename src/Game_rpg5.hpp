#ifndef Game_rpg5_hpp
#define Game_rpg5_hpp

//#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>
#include "Engine_rpg5.hpp"

using namespace std;
using namespace sf;

class Game
{
    public:
        Game(void);
        ~Game(void);

        void runGame();
        void single();

    protected:
        enum GameState {MENU,GAME,GAME_OVER,END}; //lista wyliczeniowa statusu gry,
        GameState state;


    private:
        sf::Image Ikona;//na pasek
        Font font;
        Texture menu_texture;
        Sprite menu_sprite;
        sf::RenderWindow window;

        void menu();

};


#endif // head_rpg

