/* 
 * File:   Player.h
 * Author: Théo
 *
 * Created on 14 août 2013, 01:01
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "Entity.h"

enum Lane {LeftLane, RightLane};


class Player : public Entity {
public:
    Player();
    virtual ~Player();
    
    bool isAlive();
    void destroy();
    void update(float elapsedSeconds);
    void takeLane(Lane destination);
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
private:
    bool m_alive;
    int m_abscissaGoal;
};

#endif	/* PLAYER_H */

