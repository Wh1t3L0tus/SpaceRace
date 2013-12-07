/* 
 * File:   PauseState.cpp
 * Author: Théo
 * 
 * Created on 13 août 2013, 20:43
 */

#include "PauseState.h"
#include "RaceState.h"
#include "ContentManager.h"
#include "StateManager.h"

PauseState::PauseState() {
    m_sprite.setTexture(ContentManager::getInstance()->getTexture("pause"));
}

PauseState::~PauseState() {
}

void PauseState::init()
{
    m_sprite.setPosition(0, 0);
}

void PauseState::update(sf::RenderWindow& window, float)
{
    window.clear(); 
    sf::sleep(sf::milliseconds(10));
    window.draw(m_sprite);
    window.display();
}

void PauseState::handleNotifiedEvents(sf::Event& event, float)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::F1)
            goToState(StateManager::getState("race"));
        else if (event.key.code == sf::Keyboard::Escape) {
            exit();
        }
        
    }
}
