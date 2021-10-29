#ifndef stwor_hpp
#define stwor_hpp

#include "NPC.hpp"
#include "Hero.hpp"

class Stwor :public NPC
{
    public:
        Stwor();
        ~Stwor();

        void update();

    protected:

    private:
        void ruchAgresywny();


};
#endif // stwor_hpp
