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

ScriptedSpawner::ScriptedSpawner() : Spawner() {}

ScriptedSpawner::~ScriptedSpawner() {
}

bool ScriptedSpawner::loadScript(string filename) {
    bool toReturn = m_wavesLoader.load(filename);
    generateNewWaves();
    waveEnding = false;
    return toReturn;
}

void ScriptedSpawner::updateImplementation(float)
{
    
}

SpawnResult ScriptedSpawner::spawnImplementation(float speed)
{
    SpawnResult result;
    if (waveEnding) {
        if (m_traveledDistance >= m_currentWaveSpacing) {
            m_traveledDistance = 0;
            waveEnding = false;
            nextWave();
        }
    }
    else {
        if (m_traveledDistance >= m_currentSpacing) {
            m_traveledDistance = 0;
            interpretPattern(result, m_currentPattern, speed);
            if (m_currentLineOrder.size() > 0) {
                nextLine();
            }
            else if (m_currentWaveOrder.size() > 0) {
                waveEnding = true;
            }
            else
                generateNewWaves();
        }
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
    m_currentWaveSpacing = m_currentWave->getSpacing();
    m_currentWaveOrder.pop_front();
    m_currentLineOrder = m_currentWave->getLineOrder(Random::range(0, m_currentWave->getLineOrderCount()));
    nextLine();
}

void ScriptedSpawner::generateNewWaves() {
    m_currentWaveOrder = m_wavesLoader.getWaveOrder(Random::range(0, m_wavesLoader.getWaveOrderCount()));
    nextWave();
}

void ScriptedSpawner::interpretPattern(SpawnResult& result, string pattern, float speed) {
    for (unsigned int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == 'X') {
            result.lanes[i] = new SpaceShip(sf::Vector2f(LaneExplorer::getAbscissaFromLane(i + 1), -Spawner::spawnHeight()), "spacecraft2", speed);
        } 
        else if (pattern[i] == 'Y') {
            result.lanes[i] = new SpaceShip(sf::Vector2f(LaneExplorer::getAbscissaFromLane(i + 1), -Spawner::spawnHeight()), "spacecraft3", speed);            
        }
    }
}