/* 
 * File:   StateManager.cpp
 * Author: theo
 * 
 * Created on 1 décembre 2013, 00:11
 */

#include "StateManager.h"

/**
 * Helper function that check if a given exists in a map
 * @param key : the key to find
 * @param map : the map in which looking for the key 'key'
 * @return true if the key exists
 */
bool keyExists(string key, map<string, GameState*> & map) {
    return map.find(key) != map.end();
}


/**
 *
 * CLASS MEMBERS
 * 
 */

StateManager* StateManager::m_pSingleton = NULL;

/**
 * Run the game begining with the state referenced by the name 'stateName'
 * @param stateName : name of state to run first (see addState)
 * @param window : the window to render on
 */
void StateManager::run(string stateName, sf::RenderWindow& window) {
    GameState* toRun = NULL;
    if (keyExists(stateName, getInstance()->m_statesMap))
        toRun = getInstance()->m_statesMap.at(stateName);
    
    getInstance()->m_clock.restart();
    while (window.isOpen() && toRun != NULL)
    {
        toRun->initState();
        while (toRun->updateLoop(window, getInstance()->m_clock.restart().asSeconds()));
        toRun = toRun->quit();
    }
    
    delete getInstance();
}

/**
 * Add a game state to the state manager
 * @param key : the key to retrieve this state in the futur
 * @param state : the state to add
 */
void StateManager::addState(string key, GameState* state) {
    getInstance()->addStateToInstance(key, state);
}

/**
 * Retrieve a game state
 * @param key : the key that references the game state
 * @return the game state or NULL if the key is bad
 */
GameState* StateManager::getState(string key) {
    if (keyExists(key, getInstance()->m_statesMap))
        return getInstance()->m_statesMap.at(key);
    else
        return NULL;
}

/**
 * Get the only StateManager instance
 * @return the only StateManager existing
 */
StateManager* StateManager::getInstance() {
    if (m_pSingleton == NULL)
        m_pSingleton = new StateManager();
    return m_pSingleton;
}

/**
 * 
 * INSTANCE MEMBERS
 * 
 */

StateManager::StateManager() {   
}

void StateManager::addStateToInstance(string key, GameState* state) {
    m_statesMap.insert(make_pair<string, GameState*>(key, state));    
}

StateManager::~StateManager() {
    for (map<string, GameState*>::iterator i = m_statesMap.begin(); i != m_statesMap.end(); i++) {
        delete i->second;
    }
}
