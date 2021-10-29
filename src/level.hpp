#ifndef level_hpp
#define level_hpp

#include <fstream>
#include <string>

class Level
{
    public:

         //funkcje skladowe klasy
         Level();
         Level(std::string filename);

         void loadFromFile(std::string filename);

         ~Level(void);

         //"podklasy"
         enum FieldType {
              NONE,
              DIRT1,
              GRASS,
              DIRT3,
              COUNT};

         struct Tile
         {
              FieldType type;
              bool isWall;
         };

         //zmienne
         const static int width = 20;
         const static int height = 15; //ilosc kafli

         const static int tile_width = 40;
         const static int tile_height = 40; //wymiary kafla

         Tile poziom[height][width]; //tworzenie poziomu wg struktury 'Tile'
};

#endif // level_hpp
