/* 
 * File:   MenuState.cpp
 * Author: Théo
 * 
 * Created on 13 août 2013, 20:24
 */

#include "MenuState.h"
#include "RaceState.h"
#include "ContentManager.h"

MenuState::MenuState() {
    m_sprite.setTexture(ContentManager::getInstance()->getTexture("menu"));
}

void MenuState::init()
{
    GameState::init();
    m_sprite.setPosition(0, 0);
}

bool MenuState::updateLoop(sf::RenderWindow &window)
{
    if (!GameState::updateLoop(window))
        return false;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        m_loopAgain = false;
        m_pNextState = new RaceState();
    }
    window.clear();
    sf::sleep(sf::milliseconds(10));
    window.draw(m_sprite);
    window.display();
    return m_loopAgain;
}

//GameState* MenuState::quit()
//{
//    //nothing to do before quitting
//    return m_pNextState;
//}

MenuState::~MenuState() {
}

