/* 
 * File:   main.cpp
 * Author: Théo
 *
 * Created on 13 août 2013, 18:15
 */

#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameState/IntroState.h"
#include "GameState/MenuState.h"
#include "GameState/RaceState.h"
#include "GameState/PauseState.h"
#include "ContentManager/ContentManager.h"

using namespace std;

int main(int argc, char** argv) {
    
    GameState *gs = new MenuState();
    
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Race");
    window.setVerticalSyncEnabled(true);

    while (window.isOpen() && gs != NULL)
    {
        gs->initState();
        while (gs->updateLoop(window));
        GameState* freeThis = gs;
        gs = gs->quit();
        delete freeThis;
    }
    
    
    return 0;
}

