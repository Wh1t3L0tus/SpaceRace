/* 
 * File:   IntroState.cpp
 * Author: Théo
 * 
 * Created on 13 août 2013, 20:43
 */

#include <stdlib.h>

#include "IntroState.h"
#include "GameState.h"
#include "MenuState.h"
#include "ContentManager.h"

IntroState::IntroState() {

    m_sprite.setTexture(ContentManager::getInstance()->getTexture("intro"));
}

IntroState::~IntroState() {
}

void IntroState::init()
{
    m_sprite.setPosition(0, 0);
}

bool IntroState::update(sf::RenderWindow& window)
{
    if (m_clock.getElapsedTime().asSeconds() >= 2)
    {
        m_loopAgain = false;
        m_pNextState = new MenuState();
    }
    window.clear();
    sf::sleep(sf::milliseconds(10));
    window.draw(m_sprite);
    window.display();
    
    return m_loopAgain;
}

