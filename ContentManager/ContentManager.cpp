/* 
 * File:   ContentManager.cpp
 * Author: Théo
 * 
 * Created on 13 août 2013, 23:20
 */
#include <iostream>
#include "ContentManager.h"

#define add(key, texture) insert(std::pair<std::string, sf::Texture*>(key, load(texture)))

ContentManager* ContentManager::m_pSingleton = NULL; 

sf::Texture* load(std::string str)
{
    sf::Texture *texture = new sf::Texture();
    if (texture->loadFromFile(str) == false)
        exit(EXIT_FAILURE);
    return texture;
}

ContentManager::ContentManager() {
    m_textureMap.add("spaceCraft", "../../etc/SpaceRace/dspacecraft.png");
    m_textureMap.add("menu", "../../etc/SpaceRace/menu.png");
    m_textureMap.add("intro", "../../etc/SpaceRace/intro.png");
    m_textureMap.add("pause", "../../etc/SpaceRace/pause.png");
    m_textureMap.add("spacecraft2", "../../etc/SpaceRace/dspacecraft2.png");
    m_textureMap.add("gameover", "../../etc/SpaceRace/gameover.png");
    m_textureMap.add("spacecraft3", "../../etc/SpaceRace/dspacecraft3.png");
    m_textureMap.add("spacecraft4", "../../etc/SpaceRace/dspacecraft4.png");
}

ContentManager::~ContentManager() {
    for (std::map<std::string, sf::Texture*>::iterator it = m_textureMap.begin(); it != m_textureMap.end(); it++)
        delete it->second;
}

ContentManager* ContentManager::getInstance()
{
    if (m_pSingleton == NULL)
        m_pSingleton = new ContentManager();
    
    return m_pSingleton;        
}

void ContentManager::deleteInstance()
{
    if (m_pSingleton != NULL)
        delete m_pSingleton;
}

sf::Texture& ContentManager::getTexture(std::string str)
{
    if (m_textureMap.find(str) == m_textureMap.end())
        std::cout << str << " not found in content manager" << std::endl;
    return *m_textureMap.at(str);
}
