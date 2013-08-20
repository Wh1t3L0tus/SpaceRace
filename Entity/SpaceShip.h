/* 
 * File:   SpaceShip.h
 * Author: Théo
 *
 * Created on 15 août 2013, 14:48
 */

#ifndef SPACESHIP_H
#define	SPACESHIP_H

#include "Entity.h"
#include "Collidable.h"
#include <string>

enum Lane {LeftLane, RightLane};

class SpaceShip : public Entity, public Collidable {
public:
    SpaceShip(sf::Vector2f position = sf::Vector2f(0, 0), std::string shipName = "spaceCraft", float speed = 500);
    virtual ~SpaceShip();
    
    void update(float elapsedSeconds);
    void takeLane(Lane destination);
    int actualLane();
    bool isJumpingLane();
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
    virtual sf::FloatRect hitbox();
    
private:
    float m_abscissaGoal;
};

#endif	/* SPACESHIP_H */

