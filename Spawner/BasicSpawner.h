/* 
 * File:   BasicSpawner.h
 * Author: Théo
 *
 * Created on 16 août 2013, 00:32
 */

#ifndef BASICSPAWNER_H
#define	BASICSPAWNER_H

#include "Spawner.h"

class BasicSpawner : public Spawner {
public:
    BasicSpawner(float speed);
    BasicSpawner(float speed, sf::FloatRect lanes[5]);
    virtual ~BasicSpawner();
    
    sf::FloatRect getLane(int i);
    void update();
    SpawnResult spawnImplementation(float speed);
    float spawnInterval();
    
    bool lanesCleared();
private:
    sf::FloatRect m_lanes[5];
    
    int m_leftWriter;
    int m_rightWriter;
    bool m_start;
    int m_holePosition;
};

#endif	/* BASICSPAWNER_H */

