/* 
 * File:   SpaceShip.cpp
 * Author: Théo
 * 
 * Created on 15 août 2013, 14:48
 */

#include "SpaceShip.h"
#include "ContentManager.h"
#include "LaneExplorer.h"

SpaceShip::SpaceShip(sf::Vector2f pos, std::string shipName, float speed) : 
        Entity(ContentManager::getInstance()->getTexture(shipName), pos),
        m_abscissaGoal(position().x)
{
    setSpeed(speed);
}

SpaceShip::~SpaceShip() {
}

void SpaceShip::update(float elapsedSeconds)
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

void SpaceShip::takeLane(Lane destination)
{
    if (destination == LeftLane)
        m_abscissaGoal = LaneExplorer::getAbscissaFromLane(LaneExplorer::getLaneFromAbscissa(position().x + size().x) - 1);
    else if (destination == RightLane)
        m_abscissaGoal = LaneExplorer::getAbscissaFromLane(LaneExplorer::getLaneFromAbscissa(position().x) + 1);
}

int SpaceShip::actualLane()
{
    return LaneExplorer::getLaneFromAbscissa(position().x);
}

bool SpaceShip::isJumpingLane()
{
    return position().x != m_abscissaGoal;
}

void SpaceShip::setPosition(sf::Vector2f pos)
{
    SpaceShip::setPosition(pos.x, pos.y);   
}

void SpaceShip::setPosition(float x, float y)
{
    Entity::setPosition(x, y);
    m_abscissaGoal = x;
}

sf::FloatRect SpaceShip::hitbox()
{
    return sf::FloatRect(position(), size());
}