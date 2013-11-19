/* 
 * File:   OrderNode.h
 * Author: Théo
 *
 * Created on 28 septembre 2013, 18:32
 */

#ifndef ORDERNODE_H
#define	ORDERNODE_H

#include <string>
#include <tinyxml2.h>

using namespace std;
using namespace tinyxml2;

class OrderNode {
public:
    OrderNode(XMLNode *node);
    virtual ~OrderNode();
    
//    string getOrder();
private:
    string orderValue;
};

#endif	/* ORDERNODE_H */

