/* 
 * File:   MobManager.h
 * Author: Théo
 *
 * Created on 14 août 2013, 02:56
 */

#ifndef MOBMANAGER_H
#define	MOBMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include "Player.h"
#include "Spawner.h"

class MobManager : public sf::Drawable {
public:
    MobManager();
    
    /** Copy constructor
     * The copy modify this object
     * @param orig : the manager from which you make the copy
     */
    MobManager(MobManager& orig);
    
    /** Create spaceships with the current spawner
     */
    void createMob();
    
    /** Handle traffic collision, mobs speed, destroy mobs when they are out of screen or crashed
     * 
     * @param elapsedTime : the elapsed time in seconds since the last frame
     * @param player : the...player !
     */
    void manageMobs(float elapsedTime, Player &player);
    
    /** Increase the speed of all the ships except the player's ship in order to
     * give the feeling that the player's ship is going faster
     * 
     * @param delta : the speed variation
     */
    void increaseSpeed(float delta);
    
    float speed();
    virtual ~MobManager();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    std::vector<SpaceShip*> m_pool;
//    float m_speedDelta;
    float m_mobsSpeed;
    float m_elapsedTime;
    Spawner* m_spawner;
};

#endif	/* MOBMANAGER_H */

