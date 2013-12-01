/* 
 * File:   MenuState.h
 * Author: Théo
 *
 * Created on 13 août 2013, 20:24
 */

#ifndef MENUSTATE_H
#define	MENUSTATE_H

#include "GameState.h"
#include "StarField.h"
#include "StarBackground.h"

//MenuState : state handling the game main menu
class MenuState : public GameState {
public:
    MenuState();
    virtual ~MenuState();
    
    virtual void init();
    virtual bool update(sf::RenderWindow &window, float elapsedTime);
    virtual bool handleNotifiedEvents(sf::Event& event, float elapsedTime);
private:
    
    sf::Texture m_texture;
    sf::Sprite m_sprite;

};

#endif	/* MENUSTATE_H */

