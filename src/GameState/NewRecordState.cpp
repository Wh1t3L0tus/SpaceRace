/* 
 * File:   NewRecordState.cpp
 * Author: theo
 * 
 * Created on 5 décembre 2013, 23:11
 */

#include <sstream>

#include "NewRecordState.h"
#include "ScoreManager/ScoreManager.h"
#include "GameState.h"
#include "ContentManager.h"
#include "StateManager.h"

NewRecordState::NewRecordState() : m_delChar(false), m_pScoreMgr(NULL) {
    for (int i = 0; i < 10; i++) {
        m_textPseudo[i].setFont(ContentManager::getInstance()->getFont("arial"));
        m_textPseudo[i].setCharacterSize(24);
        m_textPseudo[i].setColor(sf::Color::Black);
        
        m_textRank[i].setFont(ContentManager::getInstance()->getFont("arial"));
        m_textRank[i].setCharacterSize(24);
        m_textRank[i].setColor(sf::Color::Black);
        
        m_textScore[i].setFont(ContentManager::getInstance()->getFont("arial"));
        m_textScore[i].setCharacterSize(24);
        m_textScore[i].setColor(sf::Color::Black);
    }
    
    m_textEntered.setFont(ContentManager::getInstance()->getFont("arial"));
    m_textEntered.setCharacterSize(24);
    m_textEntered.setColor(sf::Color::Black);
    m_textEntered.setPosition(200, 100);
    
    m_textFieldText.setFont(ContentManager::getInstance()->getFont("arial"));
    m_textFieldText.setCharacterSize(24);
    m_textFieldText.setColor(sf::Color::Black);
    m_textFieldText.setPosition(50, 100);
    m_textFieldText.setString("Your pseudo : ");
    
    m_textNewScore.setFont(ContentManager::getInstance()->getFont("arial"));
    m_textNewScore.setCharacterSize(32);
    m_textNewScore.setColor(sf::Color::Black);
    m_textNewScore.setPosition(500, 100);
}

NewRecordState::~NewRecordState() {
}

void NewRecordState::init(ScoreManager* scoreMgr, int score) {
    m_pScoreMgr = scoreMgr;
    m_score = score;
    m_delChar = false;
    const vector<pair<string, int>* > scores = scoreMgr->getScores();
    
    for (unsigned int i = 0; i < scores.size(); i++) {
        ostringstream oss1;
        ostringstream oss2;
        oss1 << (i + 1);
        oss2 << scores.at(i)->second;
        
        m_textRank[i].setString(oss1.str() + " . ");
        m_textRank[i].setPosition(100, i * 25 + 200);
        
        m_textPseudo[i].setString(scores.at(i)->first);
        m_textPseudo[i].setPosition(150, i * 25 + 200);
        
        m_textScore[i].setString(oss2.str());
        m_textScore[i].setPosition(350, i * 25 + 200);
    }
    m_enteredPseudo = "";
    ostringstream oss1;
    ostringstream oss2;
    oss1 << score;
    oss2 << scoreMgr->getRank(score);
    m_textNewScore.setString("NEW RECORD : " + oss1.str() + "\nYour rank : " + oss2.str());
}

bool NewRecordState::update(sf::RenderWindow& window, float) {
    m_delChar = false;
    window.clear(sf::Color::White);
    for (int i = 0; i < 10; i++) {
        window.draw(m_textRank[i]);
        window.draw(m_textPseudo[i]);
        window.draw(m_textScore[i]);
    }
    
    window.draw(m_textNewScore);
    window.draw(m_textFieldText);
    m_textEntered.setString(m_enteredPseudo);
    window.draw(m_textEntered);
    
    sf::sleep(sf::milliseconds(10));
    window.display();
    return m_loopAgain;
}

bool NewRecordState::handleNotifiedEvents(sf::Event& event, float) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            m_loopAgain = false;
            m_pNextState = NULL;
        }
        if (event.key.code == sf::Keyboard::BackSpace) {
            m_delChar = true;
            if (m_enteredPseudo.size() == 1)
                m_enteredPseudo = "";
            else if (m_enteredPseudo.size() > 1)
                m_enteredPseudo = m_enteredPseudo.substr(0, m_enteredPseudo.size() - 1);    
        }
        else if (event.key.code == sf::Keyboard::Return) {
            m_loopAgain = false;
            m_pNextState = StateManager::getState("menu");
            m_pScoreMgr->saveBestScore(m_enteredPseudo, m_score);    
        }
    }
    else if (event.type == sf::Event::TextEntered && m_enteredPseudo.size() < 10 && !m_delChar)
        m_enteredPseudo += static_cast<char>(event.text.unicode);
         
        
    return m_loopAgain;
}