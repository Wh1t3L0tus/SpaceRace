/* 
 * File:   BasicSpawner.cpp
 * Author: Théo
 * 
 * Created on 16 août 2013, 00:32
 */

#include "Random.h"
#include "BasicSpawner.h"
#include "LaneExplorer.h"
#include "ContentManager.h"
#include <iostream>

using namespace std;

BasicSpawner::BasicSpawner(float speed) : Spawner(speed), m_leftWriter(5), m_rightWriter(7), m_start(true), m_holePosition(Random::range(1, 5)) {
}

BasicSpawner::BasicSpawner(float speed, sf::FloatRect lanes[5]) : Spawner(speed), m_leftWriter(5), m_rightWriter(7), m_start(true), m_holePosition(Random::range(1, 5))
{
    //copying lanes into m_lanes
    for (unsigned int i = 0; i < 5; i++)
       m_lanes[i] = lanes[i]; 
    
    //checking wether the lanes are cleared or not
    lanesCleared();
}

sf::FloatRect BasicSpawner::getLane(int i)
{
    return m_lanes[i];
}

void BasicSpawner::update()
{
    if (m_start)
    {
        m_leftWriter--;
        m_rightWriter--;
        if (m_rightWriter < 1)
        {
            m_leftWriter = 5;
            m_rightWriter = 7;
            m_holePosition = Random::range(1, 5);
        }
    }
    else
        lanesCleared();
}

SpawnResult BasicSpawner::spawnImplementation(float speed)
{
    SpawnResult sr;
    if (m_start)
    {
        if (m_leftWriter >= 1 && m_leftWriter <= 5 && m_holePosition != m_leftWriter)
            sr.lanes[m_leftWriter - 1] = new SpaceShip(sf::Vector2f(LaneExplorer::getAbscissaFromLane(m_leftWriter), -400), "spacecraft3", speed);
        if (m_rightWriter >= 1 && m_rightWriter <= 5 && m_holePosition != m_rightWriter)
            sr.lanes[m_rightWriter - 1] = new SpaceShip(sf::Vector2f(LaneExplorer::getAbscissaFromLane(m_rightWriter), -400), "spacecraft3", speed);        
    }
    update();
    return sr;
}

bool BasicSpawner::lanesCleared()
{
    sf::FloatRect hitbox(0, -200, ContentManager::getInstance()->getTexture("spacecraft2").getSize().x,
                                  ContentManager::getInstance()->getTexture("spacecraft2").getSize().y);
    m_start = true;
    for (unsigned int i = 0; i < 5; i++)
    {
        hitbox.left = LaneExplorer::getAbscissaFromLane(i + 1);
        if (hitbox.intersects(m_lanes[i]))
        {
            m_start = false;
            break;
        }
    }
    
    return m_start;
}

float BasicSpawner::spawnInterval()
{
    return m_spawnInterval;
}

BasicSpawner::~BasicSpawner() {
}

