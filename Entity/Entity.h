/* 
 * File:   Entity.h
 * Author: Théo
 *
 * Created on 14 août 2013, 00:37
 */

#ifndef ENTITY_H
#define	ENTITY_H

#include <SFML/Graphics.hpp>

enum Direction {
    Left,Right, Up, Down
};


class Entity : public sf::Drawable {
public:
    Entity(sf::Vector2f pos = sf::Vector2f(0, 0));
    Entity(sf::Texture &texture, sf::Vector2f pos = sf::Vector2f(0, 0));
    virtual void move(sf::Vector2f movement);
    virtual void move(Direction dir, float elapsedSeconds);
    virtual void setPosition(sf::Vector2f position);
    virtual void setPosition(float x, float y);
    virtual void setSpeed(float speed);
    virtual float getSpeed();
    virtual sf::Vector2f position();
    virtual sf::Vector2f size();
    virtual void setTexture(const sf::Texture &texture, sf::IntRect textureRect);
    virtual void setTexture(const sf::Texture &texture);
    
//    virtual sf::FloatRect hitbox();
    virtual ~Entity();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;
private:
    sf::Sprite m_sprite;
    sf::Vector2f m_size;
    float m_speed;//speed in pixels/sec
    

};

#endif	/* ENTITY_H */

