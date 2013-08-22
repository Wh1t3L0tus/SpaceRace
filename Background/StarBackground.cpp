/* 
 * File:   StarBackground.cpp
 * Author: Théo
 * 
 * Created on 21 août 2013, 23:32
 */

#include "StarBackground.h"
#include <iostream>

using namespace std;

StarBackground::StarBackground()
{
    for (unsigned int i = 0; i < 3; i++)
        m_starfields[i].generate(sf::Vector2f(800, 600), sf::Vector2f(0, (float)i * 600.0 * -1.0));
}

StarBackground::StarBackground(StarBackground& orig)
{
//    for (unsigned int i = 0; i < 3; i++)
//        m_starfields[i] = orig.m_starfields[i];
}

StarBackground::~StarBackground() {
}

void StarBackground::scroll(float elapsedTime, float speed)
{
    for (unsigned int i = 0; i < 3; i++)
    {
        m_starfields[i].move(sf::Vector2f(0, speed * elapsedTime));
        if (m_starfields[i].position().y > 600)
            m_starfields[i].generate(sf::Vector2f(800, 600), sf::Vector2f(0, -2 * 600));
    }
}

void StarBackground::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (unsigned int i = 0; i < 3; i++)
        target.draw(m_starfields[i]);
}