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
    m_elapsedTime = 0.0;
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
    
    float elapsedTime = m_clock.getElapsedTime().asSeconds();
    m_elapsedTime += elapsedTime;
    m_clock.restart();
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_player.takeLane(RightLane);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_player.takeLane(LeftLane);
    
    if (m_elapsedTime >= 3)
    {
//        m_mobMgr.createMob();
        m_elapsedTime = 0.0;
    }
    
    cout << "Lane " << LaneExplorer::getLaneFromAbscissa(sf::Mouse::getPosition(window).x) << endl;

    m_player.update(elapsedTime);
    
    m_mobMgr.manageMobs(elapsedTime, m_player);
    
    if (m_player.isAlive() == false)
    {
        m_loopAgain = false;
        m_pNextState = new GameOverState();
    }
    
    window.clear();
    window.draw(m_player);
    window.draw(m_mobMgr);
    window.display();
    
    sf::sleep(sf::milliseconds(10));

    return m_loopAgain;
}

//GameState* RaceState::quit()
//{
//    //you may need to free a bunch of variables here
//    return NULL;
//}