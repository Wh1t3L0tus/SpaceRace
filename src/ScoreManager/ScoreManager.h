/* 
 * File:   ScoreManager.h
 * Author: theo
 *
 * Created on 4 décembre 2013, 19:40
 */

#ifndef SCOREMANAGER_H
#define	SCOREMANAGER_H

#include <utility>
#include <vector>
#include <string>

using namespace std;

class ScoreManager {
public:
    /**
     * Constructor
     */
    ScoreManager();
    
    /**
     * Initialize the score manager
     * @param filename : the file name of the file containing the best scores 
     */
    void init(string filename);
    
    /**
     * Get the rank a player would its score was 'score'
     * @param score : the 
     * @return 
     */
    int getRank(int score);
    
    /**
     * Check if a score can be considered as a top score then save it
     * @param name : the name of the player
     * @param score : the score of the player
     */
    void saveBestScore(string name, int score);
    
    void clean();
    
    virtual ~ScoreManager();
private:
    string                      m_filename;
    vector<pair<string, int>* > m_scores;
    
};

#endif	/* SCOREMANAGER_H */

