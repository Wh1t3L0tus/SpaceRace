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
    
    GameState *gs = new IntroState();
    
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Race");

    while (window.isOpen() && gs != NULL)
    {
        gs->init();
        while (gs->updateLoop(window));
        cout << "Changing game state" << endl;
        GameState* freeThis = gs;
        gs = gs->quit();
        if (gs == NULL)
            cout << "quit == NULL" << endl;
        delete freeThis;
    }
    
    
    return 0;
}

