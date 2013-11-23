/* 
 * File:   ScriptedSpawner.cpp
 * Author: Théo
 * 
 * Created on 14 septembre 2013, 17:33
 */

#include "ScriptedSpawner.h"

ScriptedSpawner::ScriptedSpawner(float initSpeed, float spaceBetweenSpaceships, string filename) : Spawner(initSpeed, spaceBetweenSpaceships) {
}

ScriptedSpawner::~ScriptedSpawner() {
}

void ScriptedSpawner::updateImplementation(float elapsedTime)
{
    
}

SpawnResult ScriptedSpawner::spawnImplementation(float speed)
{
    return SpawnResult();
}