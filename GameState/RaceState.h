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
#include "StarBackground.h"

class RaceState : public GameState {
public:
    RaceState();
    virtual ~RaceState();
    
    virtual void init();
    virtual bool update(sf::RenderWindow &window);
    virtual bool handleNotifiedEvents(sf::Event &event);
//    virtual GameState* quit();
private:
    MobManager m_mobMgr;    
    Player m_player;
    sf::Clock m_clock;
    StarBackground m_stars;

};

#endif	/* RACESTATE_H */

