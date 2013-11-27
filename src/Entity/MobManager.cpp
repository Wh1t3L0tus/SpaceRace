/* 
 * File:   MobManager.cpp
 * Author: Théo
 * 
 * Created on 14 août 2013, 02:56
 */

#include "MobManager.h"
#include "Random.h"
#include "Collider.h"
#include "BasicSpawner.h"
#include "ScriptedSpawner.h"
#include <iostream>
#include <iomanip>
#include <assert.h>
#include <set>

using namespace std;


void findAndErase(SpaceShip* m, std::vector<SpaceShip*> &v)
{
    for (std::vector<SpaceShip*>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (*it == m)
        {
            delete *it;
            v.erase(it);
            break;
        }
    }
}

MobManager::MobManager() : m_pool(), m_speedDelta(0), m_mobsSpeed(500), m_elapsedTime(0.0) {
//    m_spawner = new BasicSpawner(m_mobsSpeed, "spacecraft3");
    m_spawner = new ScriptedSpawner(m_mobsSpeed, 100, "./etc/scripts/spawner.json");
}

MobManager::MobManager(MobManager& orig) : 
        m_speedDelta(orig.m_speedDelta),
        m_mobsSpeed(orig.m_mobsSpeed),
        m_elapsedTime(orig.m_elapsedTime)
{
    for (unsigned int i = 0; i < orig.m_pool.size(); i++)
        m_pool.push_back(orig.m_pool[i]);
    m_spawner = orig.m_spawner;
    
    orig.m_pool.clear();
    orig.m_spawner = NULL;
}

MobManager::~MobManager() {
    if (m_spawner != NULL)
        delete m_spawner;
    for (std::vector<SpaceShip*>::iterator it = m_pool.begin(); it != m_pool.end(); ++it)
        delete *it;
}

void MobManager::createMob()
{
    SpawnResult sp = m_spawner->spawn(m_mobsSpeed + m_speedDelta);
    if (sp.empty() == false)
    {
        for (unsigned int i = 0; i < 5; i++)
        {
            if (sp.lanes[i] != NULL)
                m_pool.push_back(sp.lanes[i]);
        }        
    }
}

void MobManager::manageMobs(float elapsedTime, Player& player)
{
//    m_elapsedTime += elapsedTime;
    
    player.update(elapsedTime);
    m_spawner->update(elapsedTime);
    if (m_spawner->canSpawn())
        createMob();

    
    for (unsigned int i = 0; i < m_pool.size(); i++)
    {
        //if there is a speed delta, then set the new speed for all ships
        if (m_speedDelta != 0)
            m_pool[i]->setSpeed(m_pool[i]->getSpeed() + m_speedDelta);
//        if (Random::range(1, 1000) <= 5)
//            m_pool[i]->takeLane((Lane)Random::range(LeftLane, RightLane));
        m_pool[i]->move(Down, elapsedTime);
        m_pool[i]->update(elapsedTime);    
        if (m_pool[i]->position().y > 900)
        {
            delete m_pool[i];
            m_pool.erase(m_pool.begin()+i);
            i--;
        }  
    }
    m_speedDelta = 0;


    //check for collisions between mobs
    std::set<SpaceShip*> mobToErase;
    for (unsigned int i = 0; i < m_pool.size(); i++)
    {
        for (unsigned int j = 0; j < m_pool.size(); j++)
        {
            if (j > i && Collider::collide(*m_pool[i], *m_pool[j]))
            {
                mobToErase.insert(m_pool[i]);
                mobToErase.insert(m_pool[j]);
//                cout << "destroy : " << (void*)m_pool[i] << (void*)m_pool[j] << endl;
            }
        }
    }
    
    //check for collision between mobs and player
    for (unsigned int i = 0; i < m_pool.size(); i++)
    {
        if (Collider::collide(*m_pool[i], player))
        {
            player.destroy();
            mobToErase.insert(m_pool[i]);
        }
    }
    
    if (player.isAlive())
        player.increaseMileageCounter(m_mobsSpeed * elapsedTime);
    
    //cleaning
    for (std::set<SpaceShip*>::iterator it = mobToErase.begin(); it != mobToErase.end(); ++it)
        findAndErase(*it, m_pool);
}

void MobManager::increaseSpeed(float delta)
{
    if (m_mobsSpeed + delta <= 1060 && m_mobsSpeed + delta >= 0)
    {
        m_speedDelta = delta;
        m_mobsSpeed += delta;
    }
}

float MobManager::speed()
{
    return m_mobsSpeed;
}

void MobManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (std::vector<SpaceShip*>::const_iterator it = m_pool.begin(); it != m_pool.end(); ++it)
        target.draw(**it, states);
}