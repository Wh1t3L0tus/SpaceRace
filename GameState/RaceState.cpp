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
#include "Gui/RaceGui.h"

#include <iostream>

using namespace std;

RaceState::RaceState() : m_raceArea(sf::FloatRect(0, 0, 800, 600)) {
    m_pNextState = NULL;
    m_player.setPosition(LaneExplorer::getAbscissaFromLane(3), 600 - m_player.size().y);
    m_player.setSpeed(1000);
    m_raceArea.setViewport(sf::FloatRect((1.0 - (800.0 / 900.0)) / 2.0, 0.01, 800.0 / 900.0, 600.0 / 700.0));
}

RaceState::~RaceState() {
}

void RaceState::init()
{
    cout << "entering race" << endl;
    m_clock.restart();
}

bool RaceState::update(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        m_loopAgain = false;
        m_pNextState = NULL;
    }
    
    float elapsed = m_clock.restart().asSeconds();
    
    m_mobMgr.manageMobs(elapsed, m_player);
    
    if (m_player.isAlive() == false)
    {
        m_loopAgain = false;
        m_pNextState = new GameOverState();
    }
    
    m_stars.scroll(elapsed, m_mobMgr.speed() / 2.0);
    m_gui.update(m_mobMgr.speed(), m_player.getMileage());
    
    
    window.clear(sf::Color(255, 255, 255));
    window.setView(m_raceArea);
    window.draw(m_stars);
    window.draw(m_player);
    window.draw(m_mobMgr);
    window.setView(window.getDefaultView());
    window.draw(m_gui);
    window.display();
    
    sf::sleep(sf::milliseconds(10));

    return m_loopAgain;
}

bool RaceState::handleNotifiedEvents(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left && m_player.actualLane() > 1)
            m_player.takeLane(LeftLane);
        else if (event.key.code == sf::Keyboard::Right && m_player.actualLane() < 5)
            m_player.takeLane(RightLane);
        else if (event.key.code == sf::Keyboard::Up)
            m_mobMgr.increaseSpeed(10);
        else if (event.key.code == sf::Keyboard::Down)
            m_mobMgr.increaseSpeed(-10);
        else if (event.key.code == sf::Keyboard::F1)
        {
            cout << "pause requested" << endl;
            m_loopAgain = false;
            m_pNextState = new PauseState(*this);
        }
    }
    
    return m_loopAgain;
}