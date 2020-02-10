
#include <SFML/Graphics.hpp>
using namespace sf;

#include "ResourcePack.h"

class Player{
    public:
        Player(ResourcePack* rp){};

    private:
        Sprite* turret_texture;
        Sprite* base_texture;

};