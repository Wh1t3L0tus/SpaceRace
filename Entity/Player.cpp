/* 
 * File:   Player.cpp
 * Author: Théo
 * 
 * Created on 14 août 2013, 01:01
 */

#include "Player.h"
#include "ContentManager.h"
#include "LaneExplorer.h"
#include <iostream>

using namespace std;

Player::Player() : 
        SpaceShip(),
        m_alive(true),
        m_mileageCounter(0)
{
}

Player::~Player() {
}

bool Player::isAlive()
{
    return m_alive;
}

void Player::destroy()
{
//    m_alive = false;
}

void Player::increaseMileageCounter(float inc)
{
    m_mileageCounter += inc;
}

float Player::getMileage()
{
    return m_mileageCounter;
}
