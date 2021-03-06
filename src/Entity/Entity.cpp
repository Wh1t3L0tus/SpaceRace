/* 
 * File:   Entity.cpp
 * Author: Théo
 * 
 * Created on 14 août 2013, 00:37
 */

#include "Entity.h"

Entity::Entity(sf::Vector2f pos) : m_size(0, 0), m_speed(0.0) {
    setPosition(pos);
}

Entity::Entity(sf::Texture &texture, sf::Vector2f pos) : m_sprite(texture), /**m_position(pos), **/m_size(m_sprite.getTextureRect().width, m_sprite.getTextureRect().height), m_speed(0.0) {
    m_sprite.setPosition(pos);
}

Entity::~Entity() {
}

void Entity::move(sf::Vector2f movement)
{
    m_sprite.setPosition(m_sprite.getPosition() + movement);
}

void Entity::move(Direction dir, float elapsedSeconds)
{
    if (dir == Left)
        m_sprite.setPosition(m_sprite.getPosition() + sf::Vector2f(-m_speed, 0) * elapsedSeconds);
    else if (dir == Right)
        m_sprite.setPosition(m_sprite.getPosition() + sf::Vector2f(m_speed, 0) * elapsedSeconds);
    else if (dir == Up)
        m_sprite.setPosition(m_sprite.getPosition() + sf::Vector2f(0, -m_speed) * elapsedSeconds);
    else if (dir == Down)
        m_sprite.setPosition(m_sprite.getPosition() + sf::Vector2f(0, m_speed) * elapsedSeconds);
}       

void Entity::setPosition(sf::Vector2f position)
{
    m_sprite.setPosition(position);
}

void Entity::setPosition(float x, float y)
{
    m_sprite.setPosition(x, y);
}

void Entity::setSpeed(float speed)
{
    m_speed = speed;
}

float Entity::getSpeed()
{
    return m_speed;
}

sf::Vector2f Entity::position() const
{
    return m_sprite.getPosition();
}

sf::Vector2f Entity::size()
{
    return m_size;
}

void Entity::setTexture(const sf::Texture& texture, sf::IntRect textureRect)
{
    m_sprite.setTexture(texture);
    m_sprite.setTextureRect(textureRect);
    m_size = sf::Vector2f(m_sprite.getTexture()->getSize().x, m_sprite.getTexture()->getSize().y);
}

void Entity::setTexture(const sf::Texture& texture)
{
    m_sprite.setTexture(texture);
    m_size = sf::Vector2f(m_sprite.getTexture()->getSize().x, m_sprite.getTexture()->getSize().y);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates) const
{
    target.draw(m_sprite);
}