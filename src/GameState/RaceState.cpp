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
#include "StateManager.h"
#include "ScoreManager.h"
#include "NewRecordState.h"

#include <math.h>

#include <iostream>

using namespace std;

RaceState::RaceState() : m_raceArea(sf::FloatRect(0, 0, 800, 600)), m_isPaused(false), m_score(0) {
    m_pNextState = NULL;
    m_raceArea.setViewport(sf::FloatRect((1.0 - (800.0 / 900.0)) / 2.0, 0.01, 800.0 / 900.0, 600.0 / 700.0));
}

RaceState::~RaceState() {
}

void RaceState::init()
{
    if (!m_isPaused) {
        m_mobMgr.init();
        m_player.init();
        m_player.setPosition(LaneExplorer::getAbscissaFromLane(3), 600 - m_player.size().y);
        m_player.setSpeed(2000);
        m_stars.init();
        m_scoreMgr.init("etc/scripts/scores.json");
        m_score = 0;
    }
    else
        m_isPaused = false;
}

void RaceState::update(sf::RenderWindow& window, float elapsedTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        m_loopAgain = false;
        m_pNextState = NULL;
    }
    
    m_mobMgr.manageMobs(elapsedTime, m_player);
    
    if (m_player.isAlive() == false)
    {
        int rank = m_scoreMgr.getRank(m_score);
        if (rank > 10 || rank < 1)
            goToState(StateManager::getState("gameOver"));
        else {
            ((NewRecordState*) StateManager::getState("newRecord"))->init(&m_scoreMgr, m_score);
            goToState(StateManager::getState("newRecord"));
        }
    }
    
    m_stars.scroll(elapsedTime, (m_mobMgr.speed() / 2.0) + 100.0);
    
    float multiplicator;
    if (m_mobMgr.speed() == 0.0)
        multiplicator = 0.0;
    else
        multiplicator = exp(m_mobMgr.speed() / 1060.0 * 3.0);
    
    m_score += multiplicator  * (elapsedTime * 100);
    m_gui.update(m_mobMgr.speed(), (int)m_score);
    
    
    window.clear(sf::Color(255, 255, 255));
    window.setView(m_raceArea);
    window.draw(m_stars);
    window.draw(m_player);
    window.draw(m_mobMgr);
    window.setView(window.getDefaultView());
    window.draw(m_gui);
    window.display();
    
    sf::sleep(sf::milliseconds(10));
}

void RaceState::handleNotifiedEvents(sf::Event& event, float)
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
            m_isPaused = true;
            goToState(StateManager::getState("pause"));
        }
    }
}