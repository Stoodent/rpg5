#ifndef Hero_rpg5_hpp
#define Hero_rpg5_hpp

#include <SFML\Graphics.hpp>
#include <vector>
#include <Windows.h>
#include <cmath>
#include "Ekwipunek.hpp"

struct _P
{
    int maximum;
    float aktualne;
    float dl_paska;

};

/***************************************************************************************
***********************   KLASA   *************************************************
***************************************************************************************/
class Hero: public sf::Drawable,sf::Transformable
{
//__________________________________________________________________
    public:
         Hero(void);
         ~Hero(void);

         enum StatusRuchu {idz,stoj};
         sf::CircleShape circle;
         _P HP;
         _P MANA;
         Ekwipunek ekwipunek;


         void update(); //zapetlanie animacji
         void ruch(sf::Keyboard::Key);
         void stop();
         void reset();
//__________________________________________________________________
    protected:
        //int klatka_animacji;
//__________________________________________________________________
    private:

         sf::Texture texture;
         sf::Sprite sprite;
         StatusRuchu status;

         sf::Clock anim_clock;

         float speed;
         size_t frame;

     virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};

#endif // Hero_rpg5_hpp

