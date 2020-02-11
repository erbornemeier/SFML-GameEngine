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

    //TODO add all game objects to game

    game.run();

}
