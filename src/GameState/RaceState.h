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
#include "RaceGui.h"


class RaceState : public GameState {
public:
    RaceState();
    virtual ~RaceState();
    
    virtual void init();
    virtual bool update(sf::RenderWindow &window, float elapsedTime);
    virtual bool handleNotifiedEvents(sf::Event &event, float elapsedTime);
//    virtual GameState* quit();
private:
    MobManager m_mobMgr;    
    Player m_player;
    StarBackground m_stars;
    sf::View m_raceArea;
    RaceGui m_gui;
    bool m_isPaused;

};

#endif	/* RACESTATE_H */

