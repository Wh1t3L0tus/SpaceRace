/* 
 * File:   ScriptedSpawner.h
 * Author: Théo
 *
 * Created on 14 septembre 2013, 17:33
 */

#ifndef SCRIPTEDSPAWNER_H
#define	SCRIPTEDSPAWNER_H

#include <string>

#include "Spawner.h"
#include "WavesLoader.h"


using namespace std;

class ScriptedSpawner : public Spawner {
public:
    ScriptedSpawner(float initSpeed, float spaceBetweenSpaceships, string filename);
    virtual ~ScriptedSpawner();
    
    void updateImplementation(float elapsedTime);
    SpawnResult spawnImplementation(float speed);
private:
    
    void nextLine();
    void nextWave();
    void generateNewWaves();
    void interpretPattern(SpawnResult &result, string pattern, float speed);
    
    string              m_scriptName;
    WavesLoader         m_wavesLoader;
    
    Wave*               m_currentWave;
    
    int                 m_currentWaveSpacing;
    int                 m_currentSpacing;
    list<int>           m_currentLineOrder;
    list<int>           m_currentWaveOrder;
    string              m_currentPattern;
    bool                waveEnding;

};

#endif	/* SCRIPTEDSPAWNER_H */

