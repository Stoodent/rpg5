#include "Game_rpg5.hpp"


/***************************************************************************************
************************  KONSTRUKTOR    **********************************************
***************************************************************************************/
Game::Game(void)//Konstruktor
{
//_________________Tworzenie okna________________________________________
    window.create(sf::VideoMode(800,600,32),"RPG 5", sf::Style::Close);
    window.setFramerateLimit(60);

//___________________Czcionka do menu__________________________________________
     if(!font.loadFromFile("data/menu,ikony/KRUSH.ttf"))
     {
          MessageBox(NULL,"Font not found!","ERROR",NULL);
          return;
     }
//___________________Tlo do menu__________________________________________
     if(!menu_texture.loadFromFile("data/menu,ikony/menu.png"))
     {
          MessageBox(NULL,"Texture not found!","ERROR",NULL);
          return;
     }
//___________________Ikonka na pasek__________________________________________
     if(!Ikona.loadFromFile("data/menu,ikony/min_ikonka.png"))
     {
         MessageBox(NULL,"ikona not found!","ERROR",NULL);
          return;
     }
    const unsigned char * Icon = Ikona.getPixelsPtr();
    window.setIcon(32,32,Icon);
//___________________Właczenie menu__________________________________________

    state = MENU;
}
/***************************************************************************************
***************************  DESTRUKTOR   ********************************************
***************************************************************************************/
Game::~Game(void)
{

}
/***************************************************************************************
*************************    RUN GAME      ******************************************
***************************************************************************************/
void Game::runGame()
{


     while(state != END) //petla która wykonuje sie dopóki nie ma konca gry, w zaleznosci od wyboru uzytkownika uruchamia odpowiednia funkcjê
     {
          switch (state)
          {
          case MENU:
               menu();
               break;
          case GAME:
               single();
               break;

          }
     }
}
/***************************************************************************************
***************************   MENU   *************************************************
***************************************************************************************/
void Game::menu() //uruchamia nam i wyswietla menu,
{

//______________Ustawianie tla i napisow(czcionki)_______________________________

    //tlo do menu
    menu_sprite.setTexture(menu_texture);

    //napisy
     Text title("RPG 5",font,80);
     title.setStyle(Text::Bold);

     title.setPosition(1280/2-title.getGlobalBounds().width/2,20);

     const int ile = 2;

     Text tekst[ile];

     string str[] = {"Graj","Wyjdz"};
     for(int i=0;i<ile;i++)
     {
          tekst[i].setFont(font);
          tekst[i].setCharacterSize(50);

          tekst[i].setString(str[i]);
          tekst[i].setPosition(1280/2-tekst[i].getGlobalBounds().width/2,250+i*120);
     }
//____________________Obsluga zdarzen___________________________________________

     while(state == MENU)
     {
          Vector2f mouse(Mouse::getPosition(window));//pozycja myszki
          Event event;//zdarzenie

          while(window.pollEvent(event))
          {
             //Wciśnięcie ESC lub przycisk X
              if(event.type == Event::Closed || event.type == Event::KeyPressed &&
                   event.key.code == Keyboard::Escape)
                   state = END;

              //kliknięcie 'Wyjdz'
              else if(tekst[1].getGlobalBounds().contains(mouse) &&
                      event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
                        {
                            state = END;
                        }
             //klikniecie 'Graj'
                else if(tekst[0].getGlobalBounds().contains(mouse) &&
                        event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
                        {
                                state = GAME;
                        }
          }
    //podswietlanie napisow
    for(int i=0;i<ile;i++)
        if(tekst[i].getGlobalBounds().contains(mouse))
            tekst[i].setColor(Color::Red);
        else tekst[i].setColor(Color::White);

   //RYSOWANIE/WYSWITLANIE
          window.clear();
          window.draw(menu_sprite);
          window.draw(title);
          for(int i=0;i<ile;i++)
          window.draw(tekst[i]);

          window.display();
     }
}
/***************************************************************************************
*************************  SINGLE  ****************************************************
***************************************************************************************/
void Game::single()
{
     Engine engine(window); //przy tworzeniu przekazujemy okno do konstruktora Engine,nastepnie uruchamiamy sama gre
     state = MENU;
}
