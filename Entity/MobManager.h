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
#include "Mob.h"

class MobManager : public sf::Drawable {
public:
    MobManager();
    void createMob();
    void manageMobs(float elapsedTime);
    virtual ~MobManager();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    std::vector<Mob*> m_pool;
};

#endif	/* MOBMANAGER_H */

