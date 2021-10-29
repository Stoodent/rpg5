#ifndef ekwipunek_hpp
#define ekwipunek_hpp

#include "Item.hpp"
#include <SFML\Graphics.hpp>

class Ekwipunek
{
    public:
        Ekwipunek();
        ~Ekwipunek();

        void dodaj(Item);
        void usun(Item);
        void update();


};

#endif // ekwipunek_hpp
