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
#include "NewRecordState.h"

using namespace std;

int main(int , char**) {
    
    StateManager::addState("menu", new MenuState());
    StateManager::addState("race", new RaceState());
    StateManager::addState("pause", new PauseState());
    StateManager::addState("intro", new IntroState());
    StateManager::addState("gameOver", new GameOverState());
    StateManager::addState("newRecord", new NewRecordState());
    
    sf::RenderWindow window(sf::VideoMode(900, 700), "Space Race");
    
    StateManager::run("menu", window);    
    
    return 0;
}

