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
        Entity(ContentManager::getInstance()->getTexture("spaceCraft")), 
        m_alive(true),
        m_abscissaGoal(position().x)
{
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
//    m_alive = false;
}

void Player::update(float elapsedSeconds)
{
    if (m_abscissaGoal > position().x)
    {
        move(Right, elapsedSeconds);
        if (m_abscissaGoal < position().x)
            setPosition(m_abscissaGoal, position().y);
    }
    else if (m_abscissaGoal < position().x)
    {
        move(Left, elapsedSeconds);
        if (m_abscissaGoal > position().x)
            setPosition(m_abscissaGoal, position().y);
    }
}

void Player::takeLane(Lane destination)
{
    if (destination == LeftLane)
        m_abscissaGoal = LaneExplorer::getAbscissaFromLane(LaneExplorer::getLaneFromAbscissa(position().x) - 1);
    else if (destination == RightLane)
        m_abscissaGoal = LaneExplorer::getAbscissaFromLane(LaneExplorer::getLaneFromAbscissa(position().x) + 1);
}

void Player::setPosition(sf::Vector2f pos)
{
    Player::setPosition(pos.x, pos.y);
}

void Player::setPosition(float x, float y)
{
    Entity::setPosition(x, y);
    m_abscissaGoal = x;
}