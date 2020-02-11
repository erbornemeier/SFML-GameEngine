#include "GameController.h"

#include <SFML/Graphics.hpp>
using namespace sf;

GameController::GameController(RenderWindow* window, float frame_rate, string rp_name){
    //load window and get frame time control
    window = window;
    _frame_time = Time(seconds(1.0 / frame_rate));
    _frame_timer = new Clock;
    _update_timer = new Clock;

    //load resource pack
    _rp = new ResourcePack(rp_name);
}

GameController::~GameController(){
    delete _frame_timer;
    delete _update_timer;
    delete _rp;
    for (auto go: _game_objects){
        delete go.second;
    }
}

void GameController::run(){
    while (_window->isOpen()){ 
        updateAll();
        drawFrame();
        Event e;
        while (_window->pollEvent(e)){
            switch(e.type){
                case Event::Closed:
                    _window->close();
                    break;
                default:
                    handleEvent(e);
                    break;
            }
        }
    }
}

void GameController::drawFrame(){
    _frame_timer->restart();

    for (auto go: _game_objects){
        go.second->draw();
    }

    _window->display();
    Time sleep_time = _frame_time - _frame_timer->getElapsedTime();
    sleep(sleep_time);
}

void GameController::updateAll(){
    
    Time since_last_update = _update_timer->getElapsedTime();
    for (auto go: _game_objects){
        go.second->update(since_last_update);
    }
    _update_timer->restart();
}

void GameController::handleEvent(Event& e){
    for (auto go: _game_objects){
        go.second->handleEvent(e);
    }
}