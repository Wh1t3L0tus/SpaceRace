/* 
 * File:   ContentManager.cpp
 * Author: Théo
 * 
 * Created on 13 août 2013, 23:20
 */
#include <iostream>
#include "ContentManager.h"

#define addTexture(key, texture) insert(std::pair<std::string, sf::Texture*>(key, loadTexture(texture)))
#define addFont(key, font) insert(std::pair<std::string, sf::Font*>(key, loadFont(font)))

ContentManager* ContentManager::m_pSingleton = NULL; 

sf::Texture* loadTexture(std::string str)
{
    sf::Texture *texture = new sf::Texture();
    if (texture->loadFromFile(str) == false)
        exit(EXIT_FAILURE);
    return texture;
}

sf::Font* loadFont(std::string str)
{
    sf::Font* font = new sf::Font();
    if (font->loadFromFile(str) == false)
        exit(EXIT_FAILURE);
    return font;
}

ContentManager::ContentManager() /**: m_xmlWaves("../../etc/SpaceRace/scripts/spawner.ini")**/ {
    //textures
    m_textureMap.addTexture("spaceCraft", "../../etc/SpaceRace/ospacecraft.png");
    m_textureMap.addTexture("menu", "../../etc/SpaceRace/menu.png");
    m_textureMap.addTexture("intro", "../../etc/SpaceRace/intro.png");
    m_textureMap.addTexture("pause", "../../etc/SpaceRace/pause.png");
    m_textureMap.addTexture("spacecraft2", "../../etc/SpaceRace/ospacecraft2.png");
    m_textureMap.addTexture("gameover", "../../etc/SpaceRace/gameover.png");
    m_textureMap.addTexture("spacecraft3", "../../etc/SpaceRace/ospacecraft3.png");
    m_textureMap.addTexture("spacecraft4", "../../etc/SpaceRace/ospacecraft4.png");
    
    //fonts
    m_fontMap.addFont("arial", "../../etc/SpaceRace/fonts/arial.ttf");    
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
        std::cout << str << " texture not found in content manager" << std::endl;
    return *m_textureMap.at(str);
}

sf::Font& ContentManager::getFont(std::string str)
{
    if (m_fontMap.find(str) == m_fontMap.end())
        std::cout << str << " font not found in content manager" << std::endl;
    return *m_fontMap.at(str);
}
