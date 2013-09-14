/* 
 * File:   Collider.h
 * Author: Théo
 *
 * Created on 14 août 2013, 18:55
 */

#ifndef COLLIDER_H
#define	COLLIDER_H

#include "Collidable.h"

class Collider {
public:
    
    static bool collide(Collidable& e1, Collidable& e2);
    static bool collide(Collidable& e1, sf::FloatRect& e2);


};

#endif	/* COLLIDER_H */

