/* 
 * File:   Player.cpp
 * Author: Théo
 * 
 * Created on 14 août 2013, 01:01
 */

#include "Player.h"
#include "ContentManager.h"

Player::Player() : Entity(ContentManager::getInstance()->getTexture("spaceCraft")) {
    setSpeed(500);
}

Player::~Player() {
}

