/* 
 * File:   ScriptedSpawner.cpp
 * Author: Théo
 * 
 * Created on 14 septembre 2013, 17:33
 */

#include "ScriptedSpawner.h"
#include "Random.h"
#include "LaneExplorer.h"
#include "ContentManager.h"

ScriptedSpawner::ScriptedSpawner(float initSpeed, float spaceBetweenSpaceships, string filename) : Spawner(initSpeed, spaceBetweenSpaceships), m_wavesLoader(filename) {
    generateNewWaves();
}

ScriptedSpawner::~ScriptedSpawner() {
}

void ScriptedSpawner::updateImplementation(float elapsedTime)
{
    
}

SpawnResult ScriptedSpawner::spawnImplementation(float speed)
{
    SpawnResult result;
    if (m_traveledDistance >= m_currentSpacing) {
        m_traveledDistance = 0;
        interpretPattern(result, m_currentPattern, speed);
        if (m_currentLineOrder.size() > 0)
            nextLine();
        else if (m_currentWaveOrder.size() > 0)
            nextWave();
        else
            generateNewWaves();
    }
    return result;
}

void ScriptedSpawner::nextLine() {
    m_currentSpacing = m_currentWave->getLine(m_currentLineOrder.front()).first;
    m_currentPattern = m_currentWave->getLine(m_currentLineOrder.front()).second;
    m_currentLineOrder.pop_front();
}

void ScriptedSpawner::nextWave() {
    m_currentWave = m_wavesLoader.getWave(m_currentWaveOrder.front());
    m_currentWaveOrder.pop_front();
    m_currentLineOrder = m_currentWave->getLineOrder(Random::range(0, m_currentWave->getLineOrderCount()));
    nextLine();
}

void ScriptedSpawner::generateNewWaves() {
    m_currentWaveOrder = m_wavesLoader.getWaveOrder(Random::range(0, m_wavesLoader.getWaveOrderCount()));
    nextWave();
}

void ScriptedSpawner::interpretPattern(SpawnResult& result, string pattern, float speed) {
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == 'X') {
            result.lanes[i] = new SpaceShip(sf::Vector2f(LaneExplorer::getAbscissaFromLane(i), -Spawner::spawnHeight()), "spacecraft2", speed);
        }
        else if (pattern[i] == 'Y') {
            result.lanes[i] = new SpaceShip(sf::Vector2f(LaneExplorer::getAbscissaFromLane(i), -Spawner::spawnHeight()), "spacecraft3", speed);            
        }
    }
}