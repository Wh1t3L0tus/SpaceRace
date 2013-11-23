/* 
 * File:   Collidable.h
 * Author: Théo
 *
 * Created on 15 août 2013, 14:44
 */

#ifndef COLLIDABLE_H
#define	COLLIDABLE_H

#include <SFML/Graphics.hpp>

class Collidable
{
public:
    Collidable(){};
    virtual ~Collidable(){};
    
    virtual sf::FloatRect hitbox() = 0;
};

#endif	/* COLLIDABLE_H */

