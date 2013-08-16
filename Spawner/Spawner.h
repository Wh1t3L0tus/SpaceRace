/* 
 * File:   Spawner.h
 * Author: Théo
 *
 * Created on 16 août 2013, 00:04
 */

#ifndef SPAWNER_H
#define	SPAWNER_H

#include <SFML/Graphics.hpp>
#include "SpaceShip.h"

/** Structure that describes the result of call to the spawn() method
 */
struct SpawnResult {
    SpawnResult() 
    {
        lanes[0] = NULL;
        lanes[1] = NULL;
        lanes[2] = NULL;
        lanes[3] = NULL;
        lanes[4] = NULL;
    }
    SpaceShip* lanes[5];
};

class Spawner {
public:
    Spawner(){};
    virtual ~Spawner(){};
    

    /** Know the position of last object in a lane
     * 
     * @param i : lane number
     * @return the hitbox of the last object entered in this lane
     */
    virtual sf::FloatRect getLane(int i) = 0;

    /** Update your random spaceship generation algorithm
     */
    virtual void update() = 0;
    
    /** Randomly create a spaceship
     * 
     * @return all the spaceships created in a SpawnResult
     */
    virtual SpawnResult spawn(float speed) = 0;
    
    /** Get the time interval between two spawn
     * 
     * @return the interval in seconds
     */
    virtual float spawnInterval() = 0;
};

#endif	/* SPAWNER_H */

