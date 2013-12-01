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
#include "StateManager.h"
#include "GameOverState.h"

using namespace std;

int main(int argc, char** argv) {
    
    StateManager::addState("menu", new MenuState());
    StateManager::addState("race", new RaceState());
    StateManager::addState("pause", new PauseState());
    StateManager::addState("intro", new IntroState());
    StateManager::addState("gameOver", new GameOverState());
    
    sf::RenderWindow window(sf::VideoMode(900, 700), "Space Race");
    window.setFramerateLimit(60);
    
    StateManager::run("menu", window);    
    
    return 0;
}

