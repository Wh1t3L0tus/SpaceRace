/* 
 * File:   PauseState.cpp
 * Author: Théo
 * 
 * Created on 13 août 2013, 20:43
 */

#include "PauseState.h"
#include "RaceState.h"
#include "ContentManager.h"

PauseState::PauseState() {
    m_sprite.setTexture(ContentManager::getInstance()->getTexture("pause"));
}

PauseState::~PauseState() {
}

void PauseState::init()
{
    GameState::init();
    m_sprite.setPosition(0, 0);
}

bool PauseState::updateLoop(sf::RenderWindow& window)
{
    sf::err() << "PauseState::updateLoop\n";
    if (!GameState::updateLoop(window))
        return false;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
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

//GameState* PauseState::quit()
//{
//    //nothing to do here before quitting
//    return new RaceState();
//}