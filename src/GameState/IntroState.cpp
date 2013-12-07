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
#include "StateManager.h"

IntroState::IntroState() {

    m_sprite.setTexture(ContentManager::getInstance()->getTexture("intro"));
}

IntroState::~IntroState() {
}

void IntroState::init()
{
    m_sprite.setPosition(0, 0);
}

void IntroState::update(sf::RenderWindow& window, float)
{
    if (m_clock.getElapsedTime().asSeconds() >= 2)
        goToState(StateManager::getState("menu"));
    window.clear();
    sf::sleep(sf::milliseconds(10));
    window.draw(m_sprite);
    window.display();
}

