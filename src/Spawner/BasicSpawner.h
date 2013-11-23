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
    BasicSpawner(float initSpeed, string spacecraftName);
    virtual ~BasicSpawner();
    
    void updateImplementation(float elapsedTime);
    SpawnResult spawnImplementation(float speed);
    
//    bool lanesCleared();
private:
    
    int m_leftWriter;
    int m_rightWriter;
    float m_startCondition;
    float m_elapsedTime;
    int m_holePosition;
    string m_spacecraftName;
};

#endif	/* BASICSPAWNER_H */

