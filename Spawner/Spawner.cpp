#include "Spawner.h"
#include "LaneExplorer.h"
#include "Collider.h"

Spawner::Spawner(float initSpeed, float spaceBetweenSpaceships) : m_spawnDensity(spaceBetweenSpaceships), m_traveledDistance(0.0), m_spaceshipSpeed(initSpeed)
{
}

void Spawner::update(float elapsedTime)
{
    m_traveledDistance += (elapsedTime * m_spaceshipSpeed);
    updateImplementation(elapsedTime);
}

bool Spawner::canSpawn()
{
    return m_traveledDistance >= m_spawnDensity;
}

float Spawner::getSpawnDensity()
{
    return m_spawnDensity;
}

void Spawner::increaseSpawnDensity(float inc)
{
    m_spawnDensity += inc;
}

SpawnResult Spawner::spawn(float speed)
{
    return spawnImplementation(speed);
}

Spawner::~Spawner()
{
}