#include "Stwor.hpp"
#include <windows.h>
using namespace sf;

/***************************************************************************************
***********************   KONTRUKTOR   *************************************************
***************************************************************************************/
Stwor::Stwor()
{
    //if(!texture.loadFromFile("data/tekstury/stwor.png"))
    if(!texture.loadFromFile("data/tekstury/gofatlas.png"))
    {
        MessageBox(NULL,"Texture not found!","ERROR",NULL);
          return;
    }
    sprite.setTexture(texture);

    //sprite.setOrigin(320,320);
    //sprite.setOrigin(80,80);
    //sprite.setScale(0.26,0.26);
    sprite.setPosition(700,100);
    sprite.setRotation(225);
    sprite.setTextureRect(sf::IntRect(0,0,228.75,160));
    sprite.setOrigin(124,80); //setOrigin sluzy do ustawienia punktu wg którego bêdziemy poruszali nasza postacia, obracali itd.
    anim_clock.restart();



}
/***************************************************************************************
***********************   DESTRUKTOR   *************************************************
***************************************************************************************/
Stwor::~Stwor()
{

}
void Stwor::update()
{
    if(anim_clock.getElapsedTime() > sf::seconds(0.2))
          {

                if(frame < 3)//liczba klatek animacji
                  frame++;                                // czyli beda wykonywac sie dwie klatki animacji, zaczynajac od klatki nr 1
                else
                  frame = 0; //zapetlanie animacji

                                                //x, y, szerokosc, wysokosc
                sprite.setTextureRect(sf::IntRect(frame*228.75,0,228.75,160));

                anim_clock.restart();

        }
       // ruchAgresywny();
}
/***************************************************************************************
***********************   RUCH       *************************************************
***************************************************************************************
void Stwor::ruchAgresywny()
{
    if(Hero::circle.getPosition().x > sprite.getPosition().x)
        sprite.setPosition(sprite.getPosition().x+-.5,sprite.getPosition().y);
}
*/
