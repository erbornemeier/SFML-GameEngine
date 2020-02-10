#include "GameController.h"

#include <SFML/Graphics.hpp>
using namespace sf;

GameController::GameController(RenderWindow* window, float frame_rate, string rp_name){
    //load window and get frame time control
    window = window;
    _frame_time = Time(seconds(1.0 / frame_rate));
    _frame_timer = new Clock;

    //load resource pack
    _rp = new ResourcePack(rp_name);
}

GameController::~GameController(){
    delete _frame_timer;
    delete _rp;
}

void GameController::drawFrame(){
    _frame_timer->restart();

    //TODO: draw all objects

    _window->display();
    Time sleep_time = _frame_time - _frame_timer->getElapsedTime();
    sleep(sleep_time);
}

void GameController::handleEvent(Event& e){

    switch (e.type){
        default:
            //TODO: PASS EVENTS TO CLASS MEMBERS
            break; 
    }

}