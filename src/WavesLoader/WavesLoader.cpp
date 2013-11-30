/* 
 * File:   WavesLoader.cpp
 * Author: theo
 * 
 * Created on 24 novembre 2013, 19:01
 */

#include <string>
#include <fstream>

#include "WavesLoader.h"
#include "ContentManager.h"

using namespace std;

WavesLoader::WavesLoader(string filename) {
    
    ifstream file(filename.c_str());
    Json::Reader jsonReader;
    
    if (!jsonReader.parse(file, m_jsonRoot))
        m_isOk = false;
    else {
        m_isOk = true;
        
        // Read the waves orders
        for (Json::UInt i = 0; i < m_jsonRoot["waveOrders"].size(); i++) {
            list<int> *waveOrder = new list<int>();
            for (Json::UInt j = 0; j < m_jsonRoot["waveOrders"][i].size(); j++) {
                waveOrder->push_back(m_jsonRoot["waveOrders"][i][j].asInt());
            }
            m_wavesOrders.push_back(waveOrder);
        }
        
        // Read the waves
        for (Json::UInt i = 0; i < m_jsonRoot["waves"].size(); i++)
            m_waves.push_back(new Wave(m_jsonRoot["waves"][i]));
    }
}

WavesLoader::~WavesLoader() {
    while (!m_wavesOrders.empty()) {
        delete m_wavesOrders.front();
        m_wavesOrders.pop_front();
    }
    
    while (!m_wavesOrders.empty()) {
        delete m_waves.back();
        m_waves.pop_back();
    }
}

bool WavesLoader::isOk() {
    return m_isOk;
}

Wave* WavesLoader::getWave(int index) {
    return m_waves[index];
}

int WavesLoader::getWaveCount() {
    return m_waves.size();
}

list<int>& WavesLoader::getWaveOrder(int index) {
    return *(*(m_wavesOrders.begin().operator ++(index)));
}

int WavesLoader::getWaveOrderCount() {
    return m_wavesOrders.size();
}

