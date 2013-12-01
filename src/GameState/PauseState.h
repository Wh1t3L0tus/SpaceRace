/* 
 * File:   PauseState.h
 * Author: Théo
 *
 * Created on 13 août 2013, 20:43
 */

#ifndef PAUSESTATE_H
#define	PAUSESTATE_H

#include "GameState.h"
#include "RaceState.h"


class PauseState : public GameState {
public:
    PauseState();
    virtual ~PauseState();
    
    virtual void init();
    virtual bool update(sf::RenderWindow &window, float elapsedTime);
    virtual bool handleNotifiedEvents(sf::Event& event, float elapsedTime);
//    virtual GameState* quit();
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

};

#endif	/* PAUSESTATE_H */

