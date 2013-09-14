/* 
 * File:   Collider.cpp
 * Author: Théo
 * 
 * Created on 14 août 2013, 18:55
 */

#include "Collider.h"
#include "Entity.h"

bool Collider::collide(Collidable& e1, Collidable& e2)
{
    return e1.hitbox().intersects(e2.hitbox());
}

bool Collider::collide(Collidable& e1, sf::FloatRect& e2)
{
    return e1.hitbox().intersects(e2);
}