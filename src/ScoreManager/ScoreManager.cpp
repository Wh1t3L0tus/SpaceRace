/* 
 * File:   ScoreManager.cpp
 * Author: theo
 * 
 * Created on 4 décembre 2013, 19:40
 */

#include <fstream>
#include <json/json.h>
#include <cassert>
#include "ScoreManager.h"

ScoreManager::ScoreManager() {
}

void ScoreManager::init(string filename) {
    clean();
    m_filename = filename;

    fstream file(filename.c_str(), fstream::in);
    Json::Reader jsonReader;
    Json::Value jsonRoot;
    
    if (!jsonReader.parse(file, jsonRoot))
        assert(false);
    
    for (Json::UInt i = 0; i < jsonRoot["scores"].size(); i++)
        m_scores.push_back(new pair<string, int>(jsonRoot["scores"][i]["name"].asString(), jsonRoot["scores"][i]["score"].asInt()));
}

int ScoreManager::getRank(int score) {
    int challenger = -1;
    for (unsigned int i = 0; i < m_scores.size(); i++) {
        if (score > m_scores.at(i)->second) {
            challenger = i;
            break;
        }
        else if (score == m_scores.at(i)->second) {
            challenger = i;
        }
        else if (challenger != -1) {
            challenger = i;
            break;
        }
    }
    
    if (challenger != -1)
        return challenger + 1;
    
    if (m_scores.size() < 10)
        return m_scores.size() + 1;
    
    return -1;
}

void ScoreManager::saveBestScore(string name, int score) {
    
    m_scores.push_back(new pair<string, int>(name, score));
    
    for (unsigned int i = 0; i < m_scores.size(); i++) {
        for (unsigned int j = 0; j < m_scores.size(); j++) {
            if (m_scores.at(i)->second > m_scores.at(j)->second) {
                int tmpInt = m_scores.at(i)->second;
                string tmpString = m_scores.at(i)->first;
                m_scores.at(i)->second = m_scores.at(j)->second;
                m_scores.at(i)->first = m_scores.at(j)->first;
                
                m_scores.at(j)->second = tmpInt;
                m_scores.at(j)->first = tmpString;
            }
        }
    }
    
    if (m_scores.size() > 10)
        m_scores.pop_back();
        
    Json::Value jsonScores;
    for (unsigned int i = 0; i < m_scores.size(); i++) {
        jsonScores[(Json::UInt)i]["name"] = m_scores.at(i)->first;
        jsonScores[(Json::UInt)i]["score"] = m_scores.at(i)->second;
    }
    Json::Value newJsonRoot;
    newJsonRoot["scores"] = jsonScores;

    fstream file(m_filename.c_str(), fstream::out);
    Json::StyledWriter jsonWriter;
    file << jsonWriter.write(newJsonRoot);
    file.close();
}

void ScoreManager::clean() {
    for (unsigned int i = 0; i < m_scores.size(); i++)
        delete m_scores.at(i);
    m_scores.clear();
}


ScoreManager::~ScoreManager() {
    clean();
}

const vector<pair<string, int>* >& ScoreManager::getScores() {
    return m_scores;
}