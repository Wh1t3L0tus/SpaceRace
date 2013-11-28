#include "Spawner.h"
#include "LaneExplorer.h"
#include "Collider.h"

Spawner::Spawner() : m_traveledDistance(0.0)
{
}

void Spawner::update(float elapsedTime, float speed)
{
    m_traveledDistance += (elapsedTime * speed);
    updateImplementation(elapsedTime);
}

SpawnResult Spawner::spawn(float speed)
{
    return spawnImplementation(speed);
}

Spawner::~Spawner()
{
}