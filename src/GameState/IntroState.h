/* 
 * File:   IntroState.h
 * Author: Théo
 *
 * Created on 13 août 2013, 20:42
 */

#ifndef INTROSTATE_H
#define	INTROSTATE_H

#include "GameState.h"

//IntroState : the state handling the game introduction
class IntroState : public GameState {
public:
    IntroState();
    virtual ~IntroState();
    
    virtual void init();
    virtual bool update(sf::RenderWindow &window);
    
private:
    
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Clock m_clock;

};

#endif	/* INTROSTATE_H */

