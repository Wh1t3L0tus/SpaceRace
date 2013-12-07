/* 
 * File:   GameOverState.cpp
 * Author: Théo
 * 
 * Created on 15 août 2013, 01:23
 */

#include "GameOverState.h"
#include "ContentManager.h"
#include "RaceState.h"
#include "StateManager.h"

GameOverState::GameOverState() : m_sprite(ContentManager::getInstance()->getTexture("gameover")){
}

GameOverState::~GameOverState() {
}

void GameOverState::init()
{
    m_sprite.setPosition(0, 0);
}

void GameOverState::update(sf::RenderWindow& window, float)
{
        window.clear();
        window.draw(m_sprite);
        window.display();
        sf::sleep(sf::milliseconds(50));
}

void GameOverState::handleNotifiedEvents(sf::Event& event, float)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            goToState(StateManager::getState("race"));
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            exit();
    }
}
