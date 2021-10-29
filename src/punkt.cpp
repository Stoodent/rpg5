#include "punkt.hpp"
#include <ctime>

/***************************************************************************************
************************   KONSTRUKTOR   **********************************************
***************************************************************************************/
Punkt::Punkt(void)
{

    if(!punkt_texture.loadFromFile("data/tekstury/atlas2.png"))
     {
          MessageBox(NULL,"Textures not found!","ERROR",NULL);
          return;
     }

     punkt_sprite.setTexture(punkt_texture);
     punkt_sprite.setTextureRect(sf::IntRect(0,0,100,100));
     punkt_sprite.setPosition(losPozycji());
     punkt_sprite.setScale(0.8,0.8);
     punkt_sprite.setOrigin(50,50);

    //kolo
     punkt_circle.setRadius(50*0.8);
     punkt_circle.setPosition(punkt_sprite.getPosition());


     punkt_anim_clock.restart();
     frame = 0;
     licznik_zebran = 0;

}
/***************************************************************************************
*************************   DESTRUKTOR   **********************************************
***************************************************************************************/
Punkt::~Punkt(void)
{

}
/***************************************************************************************
*************************   LOS POZYCJI   **********************************************
***************************************************************************************/
sf::Vector2f Punkt::losPozycji()
{
     int losX,losY;
    do
    {
        losX = rand()%700+50;
        losY = rand()%500+50;
    }while((losX>300&&losX<500) || (losY>200&&losY<400));
    sf::Vector2f losWynik(losX,losY);

    return losWynik;
}
/***************************************************************************************
***************************   DRAW   **********************************************
***************************************************************************************/
void Punkt::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(punkt_sprite);
}
/***************************************************************************************
***************************   ANIMACJA   **********************************************
***************************************************************************************/
void Punkt::update()
{
         if(punkt_anim_clock.getElapsedTime() > sf::seconds(0.13))
          {


        if(frame < 6 /*liczba klatek animacji*/)
          frame++;
        else
          frame = 0; //zapetlanie animacji

        punkt_sprite.setTextureRect(sf::IntRect(frame*100,0,100,100));
                                        //x, y, szerokosc, wysokosc

            punkt_anim_clock.restart();

          }
}
/***************************************************************************************
***************************   RESET   **********************************************
***************************************************************************************/
void Punkt::reset()
{
   punkt_sprite.setPosition(losPozycji());
   punkt_circle.setPosition(punkt_sprite.getPosition());
   licznik_zebran++;
}
