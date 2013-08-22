/* 
 * File:   StarField.cpp
 * Author: Théo
 * 
 * Created on 21 août 2013, 02:52
 */

#include "StarField.h"
#include "Entity.h"
#include "Star.h"
#include "Random.h"
#include <iostream>

using namespace std;

StarField::StarField(){}

StarField::StarField(sf::Vector2f size, sf::Vector2f pos) {
    generate(size, pos);
}

StarField::StarField(StarField& orig)
{
    setPosition(orig.position());
    m_fieldTextture.create(orig.m_fieldTextture.getSize().x, orig.m_fieldTextture.getSize().y);
    m_fieldTextture.clear();
    m_fieldTextture.draw(orig);
    m_fieldTextture.display();
}

StarField::~StarField() {
}

void StarField::generate(sf::Vector2f size, sf::Vector2f pos)
{
    Star star;
    setPosition(pos);
    if (m_fieldTextture.create(size.x, size.y) == false)
        exit(EXIT_FAILURE);
    
    m_fieldTextture.clear(sf::Color(0, 0, 0));
    for (unsigned int i = 0; i < 100; i++)
    {
        star.setStar(sf::Vector2f(Random::range(0, 800), Random::range(0, 600)), Random::range(1, 5), Random::range(0, 255));
        m_fieldTextture.draw(star);
    }
    m_fieldTextture.display();
    setTexture(m_fieldTextture.getTexture());
}