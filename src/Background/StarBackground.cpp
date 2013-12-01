/* 
 * File:   StarBackground.cpp
 * Author: Théo
 * 
 * Created on 21 août 2013, 23:32
 */

#include "StarBackground.h"
#include <iostream>

using namespace std;

StarBackground::StarBackground() : m_starfield(sf::Vector2f(800, 900), sf::Vector2f(0, -300)) {
}

StarBackground::StarBackground(StarBackground& orig) : m_starfield(orig.m_starfield)
{

}

StarBackground::~StarBackground() {
}

void StarBackground::init() {
    m_starfield.generate(sf::Vector2f(800, 900), sf::Vector2f(0, -300));
}

void StarBackground::scroll(float elapsedTime, float speed)
{
    m_starfield.scroll(elapsedTime * speed);
}

void StarBackground::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_starfield);
}
