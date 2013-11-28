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

StarField::StarField(sf::Vector2f size, sf::Vector2f pos) : m_textureSize(size) {
    generate(size, pos);
}

StarField::StarField(StarField& orig)
{
    setPosition(orig.position());
    m_fieldTexture.create(orig.m_fieldTexture.getSize().x, orig.m_fieldTexture.getSize().y);
    m_fieldTexture.clear();
    m_fieldTexture.draw(orig);
    m_fieldTexture.display();
}

StarField::~StarField() {
}

void StarField::generate(sf::Vector2f size, sf::Vector2f pos)
{
    setPosition(pos);
    if (m_fieldTexture.create(size.x, size.y) == false)
        exit(EXIT_FAILURE);
    
    m_fieldTexture.clear(sf::Color(0, 0, 0));
    for (unsigned int i = 0; i < STARS_COUNT; i++)
    {
        m_stars[i].setStar(sf::Vector2f(Random::range(0, 800), Random::range(0, size.y)), Random::range(1, 5), Random::range(0, 255));
        m_fieldTexture.draw(m_stars[i]);
    }
    m_fieldTexture.display();
    setTexture(m_fieldTexture.getTexture());
}

const StarField& StarField::operator=(const StarField& orig)
{
    setPosition(orig.position());
    if (m_fieldTexture.create(orig.m_fieldTexture.getSize().x, orig.m_fieldTexture.getSize().y) == false)
        exit(EXIT_FAILURE);
    
    m_fieldTexture.clear();
    for (unsigned int i = 0; i < STARS_COUNT; i++)
    {
        m_stars[i].setStar(orig.m_stars[i]);
        m_fieldTexture.draw(m_stars[i]);
    }
    m_fieldTexture.display();
    setTexture(m_fieldTexture.getTexture());
    
    return *this;
}

void StarField::scroll(float speed) {
    m_fieldTexture.clear(sf::Color(0, 0, 0));
    for (int i = 0; i < STARS_COUNT; i++) {
        m_stars[i].move(sf::Vector2f(0, speed));
        if (m_stars[i].getPosition().y > m_textureSize.y) {
            m_stars[i].setStar(sf::Vector2f(Random::range(0, 800), 0), Random::range(1, 5), Random::range(0, 255));
        }
        m_fieldTexture.draw(m_stars[i]);
    }
    m_fieldTexture.display();
    setTexture(m_fieldTexture.getTexture());
}

