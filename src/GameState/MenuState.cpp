/* 
 * File:   MenuState.cpp
 * Author: Théo
 * 
 * Created on 13 août 2013, 20:24
 */

#include "MenuState.h"
#include "RaceState.h"
#include "ContentManager.h"
#include "Random.h"
#include "StarBackground.h"
#include "StateManager.h"

MenuState::MenuState() {
    m_sprite.setTexture(ContentManager::getInstance()->getTexture("menu"));
}

void MenuState::init()
{
    m_sprite.setPosition(0, 0);
}

void MenuState::update(sf::RenderWindow &window, float)
{
    window.clear();
    sf::sleep(sf::milliseconds(10));
    window.draw(m_sprite);
    window.display();
}

void MenuState::handleNotifiedEvents(sf::Event& event, float)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Return)
            goToState(StateManager::getState("race"));
        else if (event.key.code == sf::Keyboard::Escape)
            exit();
    }
}

MenuState::~MenuState() {
}

