/* 
 * File:   GameOverState.cpp
 * Author: Théo
 * 
 * Created on 15 août 2013, 01:23
 */

#include "GameOverState.h"
#include "ContentManager.h"
#include "RaceState.h"

GameOverState::GameOverState() : m_sprite(ContentManager::getInstance()->getTexture("gameover")){
}

GameOverState::~GameOverState() {
}

void GameOverState::init()
{
    GameState::init();
    m_sprite.setPosition(0, 0);
}

bool GameOverState::updateLoop(sf::RenderWindow& window)
{
    if (!GameState::updateLoop(window))
        return false;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        m_loopAgain = false;
        m_pNextState = new RaceState();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        m_loopAgain = false;
        m_pNextState = NULL;
    }
    
        window.clear();
        window.draw(m_sprite);
        window.display();
        sf::sleep(sf::milliseconds(50));
    
    return m_loopAgain;
}