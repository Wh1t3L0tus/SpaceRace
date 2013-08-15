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

MobManager::MobManager() : m_pool() {
}

MobManager::~MobManager() {
    for (std::vector<SpaceShip*>::iterator it = m_pool.begin(); it != m_pool.end(); ++it)
        delete *it;
}

void MobManager::createMob()
{
    int x = Random::range(1, 5) * 160 - 130;
    SpaceShip *m = new SpaceShip(sf::Vector2f(x, -200), "spacecraft2", Random::range(200, 500));
    m_pool.push_back(m);
//    cout << "create " << (void*)m << endl;
}

void MobManager::manageMobs(float elapsedTime, Player& player)
{    
    //move the mob and check if it is out of screen (if so delete it))
    for (unsigned int i = 0; i < m_pool.size(); i++)
    {
//        cout << "trying to move " << (void*)m_pool[i] << " " << m_pool.size() << endl;
        if (Random::range(1, 1000) == 1)
            m_pool[i]->takeLane((Lane)Random::range(LeftLane, RightLane));
        m_pool[i]->move(Down, elapsedTime);
        m_pool[i]->update(elapsedTime);    
        if (m_pool[i]->position().y > 900)
        {
//            cout << "destroy " << (void*)m_pool[i] << endl;
            delete m_pool[i];
            m_pool.erase(m_pool.begin()+i);
            i--;
        }  
    }

    std::set<SpaceShip*> mobToErase;
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
    for (std::set<SpaceShip*>::iterator it = mobToErase.begin(); it != mobToErase.end(); ++it)
        findAndErase(*it, m_pool);
}

void MobManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (std::vector<SpaceShip*>::const_iterator it = m_pool.begin(); it != m_pool.end(); ++it)
        target.draw(**it, states);
}