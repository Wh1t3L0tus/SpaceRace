/* 
 * File:   Wave.cpp
 * Author: theo
 * 
 * Created on 24 novembre 2013, 22:17
 */

#include "Wave.h"

Wave::Wave(Json::Value wave) {
    m_spacing = wave["spacing"].asInt();
    
    // Read the lines
    for (Json::UInt i = 0; i < wave["lines"].size(); i++)
        m_lines.push_back(new pair<int, string>(wave["lines"][i]["spacing"].asInt(), wave["lines"][i]["pattern"].asString()));
    
    // Read the line orders
    for (Json::UInt i = 0; i < wave["linesOrders"].size(); i++) {
        vector<int> *lineOrder = new vector<int>();
        for (Json::UInt j = 0; j < wave["linesOrders"][i].size(); j++)
            lineOrder->push_back(wave["lineOrders"][j][i].asInt());
        m_lineOrders.push_back(lineOrder);
    }
}

Wave::~Wave() {
    for (int i = 0; i < m_lineOrders.size(); i++)
        delete m_lineOrders[i];
    
    for (int i = 0; i < m_lines.size(); i++)
            delete m_lines[i];
}

int Wave::getSpacing() {
    return m_spacing;
}

pair<int, string>& Wave::getLine(int index) {
    return *m_lines[index];
}

int Wave::getLineCount() {
    return m_lines.size();
}

vector<int> Wave::getLineOrder(int index) {
    return *m_lineOrders[index];
}

int Wave::getLineOrderCount() {
    return m_lineOrders.size();
}