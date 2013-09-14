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

BasicSpawner::BasicSpawner(float initSpeed, string spacecraftName) : Spawner(initSpeed), m_leftWriter(5), m_rightWriter(7), m_startCondition(1.0), m_elapsedTime(0.0), m_holePosition(Random::range(1, 5)), m_spacecraftName(spacecraftName) {
}

void BasicSpawner::updateImplementation(float elapsedTime)
{
    m_elapsedTime += elapsedTime;
    if (m_elapsedTime >= m_startCondition)
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
}

SpawnResult BasicSpawner::spawnImplementation(float speed)
{
    SpawnResult sr;
    if (m_leftWriter >= 1 && m_leftWriter <= 5 && m_holePosition != m_leftWriter)
        sr.lanes[m_leftWriter - 1] = new SpaceShip(sf::Vector2f(LaneExplorer::getAbscissaFromLane(m_leftWriter), -Spawner::spawnHeight()), m_spacecraftName, speed);
    if (m_rightWriter >= 1 && m_rightWriter <= 5 && m_holePosition != m_rightWriter)
        sr.lanes[m_rightWriter - 1] = new SpaceShip(sf::Vector2f(LaneExplorer::getAbscissaFromLane(m_rightWriter), -Spawner::spawnHeight()), m_spacecraftName, speed);        

    if (sr.empty() == false)
    {
        m_spaceshipSpeed = speed;
        m_traveledDistance = 0.0;
    }
    
    return sr;
}

BasicSpawner::~BasicSpawner() {
}

