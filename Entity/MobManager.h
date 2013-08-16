/* 
 * File:   MobManager.h
 * Author: Théo
 *
 * Created on 14 août 2013, 02:56
 */

#ifndef MOBMANAGER_H
#define	MOBMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include "Player.h"
#include "Spawner.h"

class MobManager : public sf::Drawable {
public:
    MobManager();
    void createMob();
    void manageMobs(float elapsedTime, Player &player);
    void increaseSpeed(float delta);
    virtual ~MobManager();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    std::vector<SpaceShip*> m_pool;
    int m_speedDelta;
    float m_mobsSpeed;
    float m_elapsedTime;
    Spawner* m_spawner;
};

#endif	/* MOBMANAGER_H */

