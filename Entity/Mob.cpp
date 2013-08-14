/* 
 * File:   Mob.cpp
 * Author: Théo
 * 
 * Created on 14 août 2013, 02:52
 */

#include "Mob.h"
#include "ContentManager.h"

Mob::Mob(float x, float y) : Entity(ContentManager::getInstance()->getTexture("spacecraft2"), sf::Vector2f(x, y)) {
}

Mob::~Mob() {
}

