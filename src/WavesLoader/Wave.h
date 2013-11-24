/* 
 * File:   Wave.h
 * Author: theo
 *
 * Created on 24 novembre 2013, 22:17
 */

#ifndef WAVE_H
#define	WAVE_H

#include <vector>
#include <utility>

#include <json/json.h>

using namespace std;

class Wave {
public:
    Wave(Json::Value wave);
    virtual ~Wave();
    
    int getSpacing();
    
    pair<int, string>& getLine(int index);
    int getLineCount();
    
    vector<int> getLineOrder(int index);
    int getLineOrderCount();
    
private:

    int                                 m_spacing;
    vector<pair<int, string>* >         m_lines;
    vector<vector<int>* >               m_lineOrders;
};

#endif	/* WAVE_H */

