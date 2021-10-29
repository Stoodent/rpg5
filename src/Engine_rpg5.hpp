#ifndef Engine_rpg5_hpp
#define Engine_rpg5_hpp

#include "Hero.hpp"
#include "level.hpp"
#include "punkt.hpp"
#include "Stwor.hpp"


class Engine
{
    public:
         Engine(sf::RenderWindow &window);
         ~Engine(void);

         void runEngine(sf::RenderWindow &window);

    private:
         sf::Font font;
         sf::RenderWindow window;

         Hero hero;
         Punkt punkt;
         Stwor stwor;

         void hud(sf::RenderWindow &window);
         void Kolizje(bool &menu);
         void zebranie();
         void walka();


         sf::Texture hud_texture;
         sf::Sprite hud_sprite;

         Level level; //poziom gry
         sf::Texture level_texture[Level::COUNT]; //tekstury kafli
         sf::Sprite level_sprite[Level::height][Level::width]; //poziom widziany przez gracza
};

#endif // Engine_rpg5_hpp
