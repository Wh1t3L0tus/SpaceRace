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

class StarField : public Entity {
public:
    StarField();
    StarField(StarField& orig);
    StarField(sf::Vector2f size, sf::Vector2f pos = sf::Vector2f(0, 0));
    void generate(sf::Vector2f size, sf::Vector2f pos);
    virtual ~StarField(); 
    
private:
    sf::RenderTexture m_fieldTextture;
};

#endif	/* STARFIELD_H */

