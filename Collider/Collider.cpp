/* 
 * File:   Collider.cpp
 * Author: Théo
 * 
 * Created on 14 août 2013, 18:55
 */

#include "Collider.h"
#include "Entity.h"

bool Collider::collide(Entity e1, Entity e2)
{
    return e1.hitbox().intersects(e2.hitbox());
}

