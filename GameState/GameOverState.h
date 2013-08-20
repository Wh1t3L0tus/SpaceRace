/* 
 * File:   GameOverState.h
 * Author: Théo
 *
 * Created on 15 août 2013, 01:23
 */

#ifndef GAMEOVERSTATE_H
#define	GAMEOVERSTATE_H

#include "GameState.h"

//GameOverState : state that handles the game over screen
class GameOverState : public GameState {
public:
    GameOverState();
    virtual ~GameOverState();
    
    virtual void init();
    virtual bool update(sf::RenderWindow &window);
    virtual bool handleNotifiedEvents(sf::Event& event);

private:
    sf::Sprite m_sprite;

};

#endif	/* GAMEOVERSTATE_H */

