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
#include <iostream>
#include <vector>
#include <set>

using namespace std;

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
    
    bool empty()
    {
        return lanes[0] == NULL && lanes[1] == NULL && lanes[2] == NULL && lanes[3] == NULL && lanes[4] == NULL ;
    }
    
    SpaceShip* lanes[5];
};

class Spawner {
public:
    Spawner();
    virtual ~Spawner();

    /** Update your random spaceship generation algorithm
     */
    virtual void update(float elapsedTime, float speed);
    
    /** Implementation of the update method
      * @param elapsedTime : elapsed time since the last frame
     */
    virtual void updateImplementation(float elapsedTime) = 0;
    
    /** Randomly create a spaceship
     * 
     * @return all the spaceships created in a SpawnResult
     */
    virtual SpawnResult spawn(float speed);
    
    /** Implementation of the spawn method
     * 
     * @param speed : speed of the spaceships to create
     * @return the spaceships created in a SpawnResult structure
     */
    virtual SpawnResult spawnImplementation(float speed) = 0;

    /** Get the spawn height
     * 
     * @return the spawn height
     */
    static int spawnHeight()
    {
        return 400;
    }
    
    
protected:
    SpaceShip* m_lanes[5];      //array where each SpaceShip pointer points to the first SpaceShip of each lane
    float m_traveledDistance;     //theorical distance traveled by the last spawned spaceship
};

#endif	/* SPAWNER_H */

