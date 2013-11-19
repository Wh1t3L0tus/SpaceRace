/* 
 * File:   ScriptedSpawner.h
 * Author: Théo
 *
 * Created on 14 septembre 2013, 17:33
 */

#ifndef SCRIPTEDSPAWNER_H
#define	SCRIPTEDSPAWNER_H

#include "Spawner.h"

class ScriptedSpawner : public Spawner {
public:
    ScriptedSpawner(float initSpeed, float spaceBetweenSpaceships, string filename);
    virtual ~ScriptedSpawner();
    
    void updateImplementation(float elapsedTime);
    SpawnResult spawnImplementation(float speed);
private:
    string m_scriptName;

};

#endif	/* SCRIPTEDSPAWNER_H */

