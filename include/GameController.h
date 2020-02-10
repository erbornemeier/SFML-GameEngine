
#include <SFML/Graphics.hpp>
using namespace sf;

#include "Player.h"
#include "ResourcePack.h"


class GameController {

public:
    GameController(RenderWindow* window, float frame_rate, string rp_name="default");
    ~GameController();
    void drawFrame();
    void handleEvent(Event& e);

private:
    //window and frame rate control
    RenderWindow* _window;
    Time _frame_time;
    Clock* _frame_timer;

    //graphics objects
    ResourcePack* _rp;

    //game objects
    Player* _player;
};