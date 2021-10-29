#ifndef npc_hpp
#define npc_hpp

#include <SFML/Graphics.hpp>
#include <string>

class NPC :public sf::Drawable,sf::Transformable
{
    public:
        NPC();
        ~NPC();

        enum nastawienie {wrogie,neutralne,pokojowe};
//        string nazwa;

    //protected:

         sf::Texture texture;
         sf::Sprite sprite;

         sf::Clock anim_clock;

         size_t frame;

     virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};
#endif // npc_hpp
