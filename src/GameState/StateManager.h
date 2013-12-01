/* 
 * File:   StateManager.h
 * Author: theo
 *
 * Created on 1 décembre 2013, 00:11
 */

#ifndef STATEMANAGER_H
#define	STATEMANAGER_H

#include <map>
#include <string>

#include "GameState.h"

using namespace std;

class StateManager {
public:

    static void run(string stateName, sf::RenderWindow& window);
    static void addState(string key, GameState* state);
    static GameState* getState(string key);
    virtual ~StateManager();
private:
    StateManager();
    static StateManager* getInstance();
    void addStateToInstance(string key, GameState* state);
    
    
    
    map<string, GameState*> m_statesMap;
    
    static StateManager* m_pSingleton;
};

#endif	/* STATEMANAGER_H */

