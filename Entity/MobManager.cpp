/* 
 * File:   MobManager.cpp
 * Author: Théo
 * 
 * Created on 14 août 2013, 02:56
 */

#include "MobManager.h"
#include "Random.h"
#include <iostream>

MobManager::MobManager() {
}

MobManager::~MobManager() {
    for (unsigned int i = 0; i < m_pool.size(); i++)
        delete m_pool[i];
}

void MobManager::createMob()
{
    Mob *m = new Mob(Random::range(0, 800 - 100), -200);
    m_pool.push_back(m);
    m->setSpeed(Random::range(200, 500));
}

void MobManager::manageMobs(float elapsedTime)
{
    for (unsigned int i = 0; i < m_pool.size(); i++)
    {
        m_pool[i]->move(Down, elapsedTime);
        if (m_pool[i]->position().y > 900)
            m_pool.erase(m_pool.begin()+i);
    }
}

void MobManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (unsigned int i = 0; i < m_pool.size(); i++)
        target.draw(*m_pool[i], states);
}