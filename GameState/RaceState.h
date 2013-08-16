/* 
 * File:   RaceState.h
 * Author: Théo
 *
 * Created on 13 août 2013, 20:43
 */

#ifndef RACESTATE_H
#define	RACESTATE_H

#include "GameState.h"
#include "Player.h"
#include "MobManager.h"

class RaceState : public GameState {
public:
    RaceState();
    virtual ~RaceState();
    
    virtual void init();
    virtual bool updateLoop(sf::RenderWindow &window);
//    virtual GameState* quit();
private:
    MobManager m_mobMgr;    
    Player m_player;
    sf::Clock m_clock;

};

#endif	/* RACESTATE_H */

