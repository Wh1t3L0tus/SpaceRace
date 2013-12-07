/* 
 * File:   NewRecordState.h
 * Author: theo
 *
 * Created on 5 décembre 2013, 23:11
 */

#ifndef NEWRECORDSTATE_H
#define	NEWRECORDSTATE_H

#include <string>

#include "GameState.h"
#include "ScoreManager.h"

using namespace std;

class NewRecordState : public GameState {
public:
    NewRecordState();
    virtual ~NewRecordState();
    
    void init(ScoreManager* scoreMgr, int score);
    
    virtual void update(sf::RenderWindow &window, float elapsedTime);
    virtual void handleNotifiedEvents(sf::Event&, float);


private:

    bool                m_delChar;
    string              m_enteredPseudo;
    int                 m_score;
    
    sf::Text            m_textFieldText;
    sf::Text            m_textRank[10];
    sf::Text            m_textPseudo[10];
    sf::Text            m_textScore[10];
    sf::Text            m_textEntered;
    sf::Text            m_textNewScore;
    ScoreManager*       m_pScoreMgr;
};

#endif	/* NEWRECORDSTATE_H */

