/* 
 * File:   WaveNode.h
 * Author: Théo
 *
 * Created on 28 septembre 2013, 18:31
 */

#ifndef WAVENODE_H
#define	WAVENODE_H

#include <vector>
#include <tinyxml2.h>

#include "LineNode.h"
#include "OrderNode.h"

using namespace std;
using namespace tinyxml2;

class WaveNode {
public:
    WaveNode(XMLNode *node);
    virtual ~WaveNode();
    
//    int getLinesCount();
//    LineNode& getLine(int index);
//    
//    int getOrderCount();
//    OrderNode& getOrder(int index);
    
private:
//    vector<LineNode> lines;
//    vector<OrderNode> order;
};

#endif	/* WAVENODE_H */

