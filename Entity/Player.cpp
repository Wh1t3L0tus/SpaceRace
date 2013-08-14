/* 
 * File:   Player.cpp
 * Author: Théo
 * 
 * Created on 14 août 2013, 01:01
 */

#include "Player.h"
#include "ContentManager.h"
#include <iostream>

using namespace std;

Player::Player() : Entity(ContentManager::getInstance()->getTexture("spaceCraft")), m_alive(true) {
    setSpeed(500);
}

Player::~Player() {
}

bool Player::isAlive()
{
    return m_alive;
}

void Player::destroy()
{
    m_alive = false;
}