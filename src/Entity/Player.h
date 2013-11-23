/* 
 * File:   Player.h
 * Author: Théo
 *
 * Created on 14 août 2013, 01:01
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "Entity.h"
#include "SpaceShip.h"


class Player : public SpaceShip {
public:
    Player();
    virtual ~Player();
    
    bool isAlive();
    void destroy();
    void increaseMileageCounter(float inc);
    float getMileage();
    
private:
    bool m_alive;
    float m_mileageCounter;
};

#endif	/* PLAYER_H */

