/* 
 * File:   Star.h
 * Author: Théo
 *
 * Created on 21 août 2013, 00:18
 */

#ifndef STAR_H
#define	STAR_H

#include <SFML/Graphics.hpp>

class Star : public sf::Drawable {
public:
    Star();
    Star(sf::Vector2f pos, double radius, double intensity);
    Star(const Star& s);
    void setStar(sf::Vector2f pos, double radius, double intensity);
    void setStar(const Star& s);
    void setPosition(sf::Vector2f pos);
    void setRadius(double radius);
    void setIntensity(double intensity);
    virtual ~Star();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    sf::Vector2f m_position;            //center of the star
    double m_radius;                       //radius in px
    double m_lightIntensity;               //light intensity of the star
    sf::VertexArray m_circle;
    

};

#endif	/* STAR_H */

