/* 
 * File:   ContentManager.h
 * Author: Théo
 *
 * Created on 13 août 2013, 23:20
 */

#ifndef CONTENTMANAGER_H
#define	CONTENTMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

#include <SpawnerNode.h>

class ContentManager {
public:
    sf::Texture& getTexture(std::string str);
    sf::Font& getFont(std::string str);
    static ContentManager* getInstance();
    static void deleteInstance();
    virtual ~ContentManager();
private:
    ContentManager();
        
//    SpawnerNode m_xmlWaves;
    std::map<std::string, sf::Texture*> m_textureMap;
    std::map<std::string, sf::Font*> m_fontMap;
    static ContentManager* m_pSingleton; 
};

#endif	/* CONTENTMANAGER_H */

