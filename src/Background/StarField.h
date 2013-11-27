/* 
 * File:   StarField.h
 * Author: Théo
 *
 * Created on 21 août 2013, 02:52
 */

#ifndef STARFIELD_H
#define	STARFIELD_H

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Star.h"

#define STARS_COUNT 100

class StarField : public Entity {
public:
    StarField();
    StarField(StarField& orig);
    StarField(sf::Vector2f size, sf::Vector2f pos = sf::Vector2f(0, 0));
    void generate(sf::Vector2f size, sf::Vector2f pos);
    const StarField& operator=(const StarField& orig);
    virtual ~StarField(); 
    
private:
    sf::RenderTexture m_fieldTexture;
    Star m_stars[STARS_COUNT];
};

#endif	/* STARFIELD_H */

