#ifndef punkt_hpp
#define punkt_hpp

#include <SFML\Graphics.hpp>
#include <Windows.h>


class Punkt: public sf::Drawable,sf::Transformable
{
//__________________________________________________________________
public:
     Punkt(void);
     ~Punkt(void);

     int licznik_zebran;
     sf::CircleShape punkt_circle;

     void update(); //zapetlanie animacji
     void reset();
//__________________________________________________________________
protected:
    int klatka_animacji;
//__________________________________________________________________
private:

     sf::Texture punkt_texture;
     sf::Sprite punkt_sprite;
     sf::Clock punkt_anim_clock;

     size_t frame;

     sf::Vector2f losPozycji();

     virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};

#endif // punkt_hpp
