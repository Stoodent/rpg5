#include "Hero.hpp"
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace sf;

/***************************************************************************************
*********************   KONSTRUKTOR   *************************************************
***************************************************************************************/
Hero::Hero(void)
{
//__________początkowe_parametry____________________________________________________
    HP.maximum = 100;
    HP.aktualne = 100;
    MANA.maximum = 100;
    MANA.aktualne = 100;

    HP.dl_paska = (HP.aktualne/(float)HP.maximum)*200;

    status = stoj;
//________ustawienia_sprita_________________________________________________________
    if(!texture.loadFromFile("data/tekstury/heroatlas2.png"))
     {
          MessageBox(NULL,"Textures not found!","ERROR",NULL);
          return;
     }

     sprite.setTexture(texture);
     sprite.setTextureRect(sf::IntRect(0,0,512,512));
     sprite.setScale(0.3,0.3);
     sprite.setOrigin(256,256);
     sprite.setPosition(400,300);
//_____bounding_box____________________________________________________________
     circle.setRadius(256);
     circle.setScale(0.3,0.3);
//_________________________________________________________________
     frame = 0;
     anim_clock.restart();

}
/***************************************************************************************
***********************   DESTRUKTOR   *************************************************
***************************************************************************************/
Hero::~Hero(void)
{

}
/***************************************************************************************
***************************   DRAW   *************************************************
***************************************************************************************/
void Hero::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprite);
}
/***************************************************************************************
***************************   RUCH   *************************************************
***************************************************************************************/
void Hero::ruch(sf::Keyboard::Key klawisz)
{
    //float vx = 5;
    //float vy = 5;

    float odl = 5;
    float skos_odl = odl/sqrt(2);

    float rotation = sprite.getRotation();

    status = idz;

    switch(klawisz)
    {
/**
        //rychy po skosie
        case (Keyboard::Up && Keyboard::Right)  : sprite.setRotation(45);   sprite.move(skos_odl,-skos_odl);break;
        case (Keyboard::Down && Keyboard::Right)  : sprite.setRotation(135);  sprite.move(skos_odl,skos_odl);break;
        case Keyboard::Down && Keyboard::Left   : sprite.setRotation(225);  sprite.move(-skos_odl,skos_odl);break;
        case Keyboard::Up && Keyboard::Left     : sprite.setRotation(315);  sprite.move(-skos_odl,-skos_odl);break;
*/
        //ruchy w 4 kierunkach
        case Keyboard::Up       : sprite.setRotation(0);    sprite.move(0,-odl);break;
        case Keyboard::Right    : sprite.setRotation(90);   sprite.move(odl,0);break;
        case Keyboard::Down     : sprite.setRotation(180);  sprite.move(0,odl);break;
        case Keyboard::Left     : sprite.setRotation(270);  sprite.move(-odl,0);break;
        default                 : /**/ ;


    }
    circle.setPosition(sprite.getPosition());
    //sprite.move(speed*vx,speed*vy);
}
/***************************************************************************************
***************************   STOP      **********************************************
***************************************************************************************/
void Hero:: stop()
{
    status = stoj;
   // sprite.setTextureRect(sf::IntRect(0,0,512,512));

}
/***************************************************************************************
***************************   ANIMACJA   **********************************************
***************************************************************************************/
void Hero::update()
{
    HP.dl_paska = (HP.aktualne/(float)HP.maximum)*200;
/**
    if(anim_clock.getElapsedTime() > sf::seconds(0.15))

        switch(status)
        {
            case idz:
                if(frame < 2)frame++;
                else frame = 1;
                sprite.setTextureRect(sf::IntRect(frame*512,0,512,512));
                                                //x, y, szerokosc, wysokosc
                anim_clock.restart();

                system("cls");
                std::cout << "idz" << std::endl;
/*
            case stoj:sprite.setTextureRect(sf::IntRect(0,0,512,512));
            system("cls");
            std::cout << "stoj" << std::endl;

        }

}
*/


         if(anim_clock.getElapsedTime() > sf::seconds(0.15))
          {
            if(status == idz)
            {
                if(frame < 2)frame++; //liczba klatek animacji // czyli beda wykonywac sie dwie klatki animacji, zaczynajac od klatki nr 1
                else frame = 1; //zapetlanie animacji
                sprite.setTextureRect(sf::IntRect(frame*512,0,512,512));
                                                //x, y, szerokosc, wysokosc
                anim_clock.restart();
            }
            else
            {
                sprite.setTextureRect(sf::IntRect(0,0,512,512));
            }
          }
}
/***************************************************************************************
***************************   RESET     **********************************************
***************************************************************************************/
void Hero::reset()
{
    sprite.setPosition(400,300);
    sprite.setRotation(0);
}
