/* 
 * File:   SpawnerNode.h
 * Author: Théo
 *
 * Created on 28 septembre 2013, 18:31
 */

#ifndef SPAWNERNODE_H
#define	SPAWNERNODE_H

#include <string>
#include <vector>
#include <fstream>

#include <tinyxml2.h>

#include "WaveNode.h"
#include "OrderNode.h"

using namespace std;
using namespace tinyxml2;

class SpawnerNode {
public:
    SpawnerNode(string fileName);
    virtual ~SpawnerNode();
    
//    vector<WaveNode>& getWaves();
//    vector<OrderNode>& getOrders();
private:
    XMLDocument m_doc;
    vector<WaveNode> m_waves;
    vector<OrderNode> m_waveOrder;
    
};

#endif	/* SPAWNERNODE_H */

