/* 
 * File:   SpawnerNode.cpp
 * Author: Théo
 * 
 * Created on 28 septembre 2013, 18:31
 */

#include "SpawnerNode.h"
#include "WaveNode.h"
#include "OrderNode.h"

#include <cstring>
#include <iostream>

SpawnerNode::SpawnerNode(string fileName) {
    
    if (m_doc.LoadFile(fileName.c_str()) != XML_NO_ERROR) {
        cout << "Error while loading the xml doc !" << endl;
        exit(0);
    }
    
    // Browsing the xml 
    XMLNode* node = m_doc.FirstChild();
    node = node->FirstChild();
    cout << node->Value() << endl;
    
    do {
        if (strcmp(node->Value(), "Wave") == 0)
            m_waves.push_back(new WaveNode(node));
        else if (strcmp(node->Value(), "WaveLineOrders") == 0) {
            XMLNode* child = node->FirstChild();
            do {
                if (strcmp(child->Value(), "Order") == 0)
                    m_waveOrder.push_back(new OrderNode(child));
            } while ((child = child->NextSibling()) != NULL);
        }
    } while ((node = node->NextSibling()) != NULL);
    
    
//    xml_node<> *node = document.first_node();
//    do {
//        if (strcmp(node->name(), "Wave") == 0)
//            m_waves.push_back(*new WaveNode(node));
//        else if (strcmp(node->name(), "WaveLineOrder") == 0)
//        {
//            xml_node<> *child = node->first_node();
//            do {
//                if (strcmp(child->name(), "Order") == 0)
//                    m_waveOrder.push_back(*new OrderNode(child));
//            } while ((child = child->next_sibling()));
//        }
//    } while ((node = node->next_sibling()));
}

SpawnerNode::~SpawnerNode() {
}

//vector<WaveNode>& SpawnerNode::getWaves() {
//    return m_waves;
//}
//
//vector<OrderNode>& SpawnerNode::getOrders() {
//    return m_waveOrder;
//}
