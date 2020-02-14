#include <vector>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef _Game_Object
#define _Game_Object

class GameObject {
    public:
        GameObject(){};
        virtual ~GameObject() = 0;
        virtual void draw() = 0;
        virtual void update(Time since_last_update) = 0;
        virtual void handleEvent(Event& e) = 0;

    public:
        Vector2f position = {0, 0};
        float rotation = 0;
        vector<Sprite*> graphic;
        Shape* bounding_box;
};

#endif