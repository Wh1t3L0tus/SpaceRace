/* 
 * File:   RaceGui.cpp
 * Author: Théo
 * 
 * Created on 22 août 2013, 22:15
 */

#include "RaceGui.h"
#include "ContentManager.h"
#include <string>
#include <sstream>

using namespace std;

RaceGui::RaceGui() {
    m_speedText.setFont(ContentManager::getInstance()->getFont("arial"));
    m_mileageText.setFont(ContentManager::getInstance()->getFont("arial"));
    
    m_speedText.setPosition(100, 650);
    m_mileageText.setPosition(550, 650);
    
    m_speedText.setColor(sf::Color(0, 0, 0));
    m_mileageText.setColor(sf::Color(0, 0, 0));
    
    m_speedText.setCharacterSize(24);
    m_mileageText.setCharacterSize(24);
}

RaceGui::~RaceGui() {
}

void RaceGui::update(int speed, int mileage)
{
    ostringstream os1;
    os1 << speed;
    m_speedText.setString("Speed : " + os1.str());
    
    ostringstream os2;    
    
    os2 << mileage;
    m_mileageText.setString("Mileage : " + os2.str());
}

void RaceGui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_speedText);
    target.draw(m_mileageText);
}