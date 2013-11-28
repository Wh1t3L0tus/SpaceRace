/* 
 * File:   StarBackground.h
 * Author: Théo
 *
 * Created on 21 août 2013, 23:32
 */

#ifndef STARBACKGROUND_H
#define	STARBACKGROUND_H

#include "StarField.h"

class StarBackground : public sf::Drawable {
public:
    StarBackground();
    StarBackground(StarBackground& orig);
    void scroll(float elapsedTime, float speed);
    virtual ~StarBackground();
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    StarField m_starfield;
    
};

#endif	/* STARBACKGROUND_H */

