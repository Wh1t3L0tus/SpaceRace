/* 
 * File:   Wave.h
 * Author: theo
 *
 * Created on 24 novembre 2013, 22:17
 */

#ifndef WAVE_H
#define	WAVE_H

#include <list>
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
    
    list<int> getLineOrder(int index);
    int getLineOrderCount();
    
    string toString();
    
private:

    int                                 m_spacing;
    list<pair<int, string>* >           m_lines;
    list<list<int>* >                   m_lineOrders;
};

#endif	/* WAVE_H */

