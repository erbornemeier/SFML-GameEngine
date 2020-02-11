#include <map>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

#include "GameObject.h"
#include "ResourcePack.h"

#ifndef _Game_Controller
#define _Game_Controller

class GameController {

public:
    GameController(RenderWindow* window, float frame_rate, string rp_name="default");
    ~GameController();
    void run();
    void drawFrame();
    void updateAll();
    void handleEvent(Event& e);

private:
    //window and frame rate control
    RenderWindow* _window;
    Time _frame_time;
    Clock* _frame_timer;

    //graphics objects
    ResourcePack* _rp;

    //game objects
    map<string, GameObject*> _game_objects;
};

#endif