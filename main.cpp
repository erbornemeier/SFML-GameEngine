#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

#include "GameController.h"

int main(){

    RenderWindow* window = new RenderWindow(VideoMode(1280, 720), "BANK TANKS");

    GameController game(window, 60);

    while (window->isOpen()){
        
        game.drawFrame();

        Event e;
        while (window->pollEvent(e)){
            switch(e.type){
                case Event::Closed:
                    window->close();
                    break;
                default:
                    game.handleEvent(e);
                    break;
            }
        }

    }

}
