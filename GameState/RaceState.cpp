/* 
 * File:   RaceState.cpp
 * Author: Théo
 * 
 * Created on 13 août 2013, 20:43
 */

#include "RaceState.h"
#include "PauseState.h"
#include "ContentManager.h"
#include "MenuState.h"
#include "MobManager.h"
#include "GameOverState.h"
#include "LaneExplorer.h"

#include <iostream>

using namespace std;

RaceState::RaceState() {
    m_pNextState = NULL;
}

RaceState::~RaceState() {
}

void RaceState::init()
{
    GameState::init();
    m_clock.restart();
    m_player.setPosition(LaneExplorer::getAbscissaFromLane(3), 600 - m_player.size().y);
}

bool RaceState::updateLoop(sf::RenderWindow& window)
{
    if (!GameState::updateLoop(window))
        return false;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
    {
        m_loopAgain = false;
        m_pNextState = new PauseState();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        m_loopAgain = false;
        m_pNextState = NULL;
    }
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_player.takeLane(RightLane);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_player.takeLane(LeftLane);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        m_mobMgr.increaseSpeed(10);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        m_mobMgr.increaseSpeed(-10);    
    
    m_mobMgr.manageMobs(m_clock.restart().asSeconds(), m_player);
    
    if (m_player.isAlive() == false)
    {
        m_loopAgain = false;
        m_pNextState = new GameOverState();
    }
    
    window.clear(sf::Color(255, 255, 255));
    window.draw(m_player);
    window.draw(m_mobMgr);
    window.display();
    
    sf::sleep(sf::milliseconds(10));

    return m_loopAgain;
}