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
    Spawner(float initSpeed, float spaceBetweenSpaceships = 400.0);
    virtual ~Spawner();

    /** Update your random spaceship generation algorithm
     */
    virtual void update(float elapsedTime);
    
    /** Implementation of the update method
      * @param elapsedTime : elapsed time since the last frame
     */
    virtual void updateImplementation(float elapsedTime) = 0;
    
    /** Tell whether conditions are statisfied to spawn or noy
     * 
     * @return true if it's ok to spawn
     */
    virtual bool canSpawn();
    
    /** Get the spawn density
     * 
     * @return the spawn density
     */
    virtual float getSpawnDensity();
    
    /** Increase the spawn density
     * 
     * @param inc : spawn density increment
     */
    virtual void increaseSpawnDensity(float inc);
    
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
    float m_spawnDensity;         //the lower it is, closer are the spaceships to each other
    float m_traveledDistance;     //theorical distance traveled by the last spawned spaceship (based on its speed at birth)
    float m_spaceshipSpeed;       //speed of the last spawned spaceship
};

#endif	/* SPAWNER_H */

