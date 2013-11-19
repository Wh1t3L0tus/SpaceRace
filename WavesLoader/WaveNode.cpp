///* 
// * File:   WaveNode.cpp
// * Author: Théo
// * 
// * Created on 28 septembre 2013, 18:31
// */
//
//#include <cstring>
//
//#include "WaveNode.h"
//#include "OrderNode.h"
//
////WaveNode::WaveNode(xml_node<> *node) {
////    xml_node<> *tmp_node = node;
////    do {
////        if (strcmp(tmp_node->name(), "Line") == 0)
////            lines.push_back(*new LineNode(tmp_node));
////    } while (tmp_node->next_sibling());
//}
//
//WaveNode::~WaveNode() {
//}
//
//int WaveNode::getLinesCount() {
//    return lines.size();
//}
//
//LineNode& WaveNode::getLine(int index) {
//    return lines[index];
//}
//
//int WaveNode::getOrderCount() {
//    return order.size();
//}
//
//OrderNode& WaveNode::getOrder(int index) {
//    return order[index];
//}
