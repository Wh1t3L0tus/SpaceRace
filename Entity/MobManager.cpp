/* 
 * File:   MobManager.cpp
 * Author: Théo
 * 
 * Created on 14 août 2013, 02:56
 */

#include "MobManager.h"
#include "Random.h"
#include "Collider.h"
#include <iostream>
#include <assert.h>
#include <set>

using namespace std;


void findAndErase(Mob* m, std::vector<Mob*> &v)
{
    for (std::vector<Mob*>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (*it == m)
        {
            delete *it;
            v.erase(it);
            break;
        }
    }
}

MobManager::MobManager() : m_pool() {
}

MobManager::~MobManager() {
    for (std::vector<Mob*>::iterator it = m_pool.begin(); it != m_pool.end(); ++it)
        delete *it;
}

void MobManager::createMob()
{
    int x = Random::range(1, 5)*160 - 130;
    Mob *m = new Mob(x, -200);
    m_pool.push_back(m);
    m->setSpeed(Random::range(200, 500));
    cout << "create " << (void*)m << endl;
}

void MobManager::manageMobs(float elapsedTime, Player& player)
{    
    //move the mob
    for (std::vector<Mob*>::iterator it = m_pool.begin(); it != m_pool.end(); ++it)
    {
        cout << "trying to move " << (void*)*it << " " << m_pool.size() << endl;
        (*it)->move(Down, elapsedTime);
        if ((*it)->position().y > 900)
        {
            cout << "destroy " << (void*)*it << endl;
            delete *it;
            m_pool.erase(it);
        }  
    }

    std::set<Mob*> mobToErase;
    //check for collisions between mobs
    for (unsigned int i = 0; i < m_pool.size(); i++)
    {
        for (unsigned int j = 0; j < m_pool.size(); j++)
        {
            if (m_pool[i] != m_pool[j] && Collider::collide(*m_pool[i], *m_pool[j]))
            {   
                mobToErase.insert(m_pool[i]);
                mobToErase.insert(m_pool[j]);
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
    
    //cleaning
    for (std::set<Mob*>::iterator it = mobToErase.begin(); it != mobToErase.end(); ++it)
        findAndErase(*it, m_pool);
}

void MobManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (std::vector<Mob*>::const_iterator it = m_pool.begin(); it != m_pool.end(); ++it)
        target.draw(**it, states);
}