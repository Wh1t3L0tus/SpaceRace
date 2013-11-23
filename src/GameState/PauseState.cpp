/* 
 * File:   PauseState.cpp
 * Author: Théo
 * 
 * Created on 13 août 2013, 20:43
 */

#include "PauseState.h"
#include "RaceState.h"
#include "ContentManager.h"

PauseState::PauseState(RaceState pausedGame) : m_pausedGame(pausedGame) {
    m_sprite.setTexture(ContentManager::getInstance()->getTexture("pause"));
}

PauseState::~PauseState() {
}

void PauseState::init()
{
    cout << "entering pause" << endl;
    m_sprite.setPosition(0, 0);
}

bool PauseState::update(sf::RenderWindow& window)
{
    window.clear(); 
    sf::sleep(sf::milliseconds(10));
    window.draw(m_sprite);
    window.display();
    
    return m_loopAgain;
}

bool PauseState::handleNotifiedEvents(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
        {
            m_loopAgain = false;
            m_pNextState = new RaceState(m_pausedGame);
        }    
    }
    return m_loopAgain;
}
