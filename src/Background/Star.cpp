/* 
 * File:   Star.cpp
 * Author: Théo
 * 
 * Created on 21 août 2013, 00:19
 */

#include <iostream>
#include <math.h>
#include "Star.h"

#define PI 3.14159265
#define VERTICES_COUNT 11

using namespace std;

Star::Star() : m_circle(sf::TrianglesFan, VERTICES_COUNT + 1) {}

Star::Star(sf::Vector2f pos, double radius, double intensity) : m_circle(sf::TrianglesFan, VERTICES_COUNT + 1) {
    setStar(pos, radius, intensity);
}

Star::Star(const Star& s) : m_circle(sf::TrianglesFan, VERTICES_COUNT + 1)
{
    setStar(s.m_position, s.m_radius, s.m_lightIntensity);
}

void Star::setStar(sf::Vector2f pos, double radius, double intensity)
{
    double delta = 0;
    m_position = pos;
    m_radius = radius;
    m_lightIntensity = intensity;
    m_circle[0].position = pos;
    m_circle[0].color = sf::Color(255, 255, 255, 255 - m_radius);
    m_circle[VERTICES_COUNT].position = sf::Vector2f(m_radius * cos(0), m_radius * sin(0)) + pos;
    m_circle[VERTICES_COUNT].color = sf::Color(m_lightIntensity, m_lightIntensity, m_lightIntensity, m_radius);
    
    for (unsigned int i = 1; i < VERTICES_COUNT; i++)
    {
        m_circle[i].position = sf::Vector2f(m_radius * cos(delta), m_radius * sin(delta)) + pos;
        m_circle[i].color = sf::Color(m_lightIntensity, m_lightIntensity, m_lightIntensity, m_radius);
        delta += (2 * PI) / (VERTICES_COUNT - 1);
    }
}

void Star::setStar(const Star& s)
{
    setStar(s.m_position, s.m_radius, s.m_lightIntensity);
}

void Star::setPosition(sf::Vector2f pos)
{
    m_circle[0].position = pos;
    m_circle[VERTICES_COUNT].position -= m_position;
    m_circle[VERTICES_COUNT].position += pos;
    for (unsigned int i = 1; i < VERTICES_COUNT; i++)
    {
        m_circle[i].position -= m_position;
        m_circle[i].position += pos;
    }
    m_position = pos;
}

const sf::Vector2f& Star::getPosition() const {
    return m_position;
}

void Star::move(sf::Vector2f movement) {
    setPosition(m_position + movement);
}

void Star::setRadius(double radius)
{
    setStar(m_position, radius, m_lightIntensity);
}

Star::~Star() {
}

void Star::draw(sf::RenderTarget& target, sf::RenderStates) const
{
    target.draw(m_circle);
}

