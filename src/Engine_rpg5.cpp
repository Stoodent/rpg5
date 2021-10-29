#include "Engine_rpg5.hpp"
#include <cmath>
#include <sstream>

using namespace sf;


/***************************************************************************************
***********************   KONTRUKTOR   *************************************************
***************************************************************************************/
Engine::Engine(RenderWindow &win)
{

    win;


//___________________Poziom(napis)__________________________________________
     if(!font.loadFromFile("data/menu,ikony/KRUSH.ttf"))
     {
          MessageBox(NULL,"Font not found!","ERROR",NULL);
          return;
     }

//______ustawienia planszy(kafla,tekstury)_______________________________________________

    //wczytanie tekstur
     for(int i=1;i<Level::COUNT;i++)
     {
          level_texture[i].loadFromFile("data/levels/grass.png",IntRect((i-1)*level.tile_width,0,level.tile_width,level.tile_height));
                                                                        //x, y, szerokosc, wysokosc
     }

     //ustawienie kafli
     level.loadFromFile("map.level");
     for(int i=0;i<level.height;i++)
     {
          for(int j=0;j<level.width;j++)
          {
               if(level.poziom[i][j].type != Level::NONE)
               {
                    level_sprite[i][j].setTexture(level_texture[level.poziom[i][j].type]);
                    level_sprite[i][j].setPosition(j*level.tile_width,i*level.tile_height);
               }
          }
     }
//_________hud wczytywanie tekstury____________________________________________________________
     if(!hud_texture.loadFromFile("data/tekstury/HUD.png"))
     {
          MessageBox(NULL,"Texture not found!","ERROR",NULL);
          return;
     }

     hud_sprite.setTexture(hud_texture);
//______RUN ENGINE______________________________________________________________________

	runEngine(win);

}
/***************************************************************************************
***********************   DESTRUKTOR   *************************************************
***************************************************************************************/
Engine::~Engine(void)
{
}
/***************************************************************************************
***********************   RUN ENGINE   *************************************************
***************************************************************************************/
void Engine::runEngine(RenderWindow &window)
{

    bool menu = false;
     while(!menu)
     {

//______wydarzenia__________________________________________________________________
          Event event;
          while(window.pollEvent(event))
          {
              //wyjscie do menu - ESC
               if(event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
                menu = true;

             //Ruch Gracza - strzałki
               if(event.type == Event::KeyPressed && (event.key.code == Keyboard::Up||event.key.code == Keyboard::Down||event.key.code == Keyboard::Right ||event.key.code == Keyboard::Left ))
                hero.ruch(event.key.code);
               else hero.stop();

          }
//______logika____________________________________________________________________

        Kolizje(menu);

        punkt.update();
        stwor.update();
        hero.update();

//_____czyszczenie okna______________________________________________________________
        window.clear();

//_____rysowanie poziomu_____________________________________________________________
        for(int i=0;i<level.height;i++)
            for(int j=0;j<level.width;j++)
                if(level.poziom[i][j].type != Level::NONE)
                window.draw(level_sprite[i][j]);
//____rysowanie obiektow______________________________________________________________
          window.draw(punkt);
          window.draw(stwor);
          window.draw(hero);

          hud(window);



//_____wyswietlanie okna______________________________________________________________
          window.display();
     }
}
/***************************************************************************************
***********************   KOLIZJE    *************************************************
***************************************************************************************/
void Engine::Kolizje(bool &menu)
{
    //wszytsko do poprawy
     Vector2f ODL = hero.circle.getPosition() - punkt.punkt_circle.getPosition();
    int Xodl = abs(ODL.x);
    int Yodl = abs(ODL.y);
    int PRZEK = sqrt((Xodl*Xodl) + (Yodl*Yodl));

    if(PRZEK < 50) zebranie();

    Vector2f ODL2 = hero.circle.getPosition() - stwor.sprite.getPosition();
    int Xodl2 = abs(ODL2.x);
    int Yodl2 = abs(ODL2.y);
    int PRZEK2 = sqrt((Xodl2*Xodl2) + (Yodl2*Yodl2));

    if(PRZEK2 < 100)
    {
        walka();
        if(hero.HP.aktualne <= 0) menu = true;
    }
}
/***************************************************************************************
***********************   RESET      *************************************************
***************************************************************************************/
void Engine::zebranie()
{
    punkt.reset();
}
void Engine::walka()
{
    hero.HP.aktualne -= 0.5;
}
/***************************************************************************************
***********************   HUD     *****************************************************
***************************************************************************************/
void Engine::hud(RenderWindow &window)
{
//__________Zycie___________________________________

   RectangleShape hp_pasek(Vector2f(hero.HP.dl_paska,14));
   hp_pasek.setFillColor(Color::Red);
   hp_pasek.setPosition(151,29);

//__________Poziom__________________________________
    int poziom = punkt.licznik_zebran;
    std::ostringstream ss;
    ss << poziom;
    std::string strPoziom = ss.str();

    Text poziom_napis("Poziom: "+strPoziom,font,40);
    poziom_napis.setPosition(570,550);

//__________Rysowanie________________________________
    //window.draw(hp_sprite);
    window.draw(hp_pasek);
    window.draw(poziom_napis);
    window.draw(hud_sprite);

}

