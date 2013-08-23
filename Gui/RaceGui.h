/* 
 * File:   RaceGui.h
 * Author: Théo
 *
 * Created on 22 août 2013, 22:15
 */

#ifndef RACEGUI_H
#define	RACEGUI_H

#include <SFML/Graphics.hpp>

class RaceGui : public sf::Drawable {
public:
    RaceGui();
    virtual ~RaceGui();
    
    void update(int speed, int mileage);
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::Text m_speedText;
    sf::Text m_mileageText;
};

#endif	/* RACEGUI_H */

