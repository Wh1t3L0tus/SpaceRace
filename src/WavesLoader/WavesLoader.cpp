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

WavesLoader::WavesLoader() {
    string filename = "etc/scripts/spawner.json";
    
    ifstream file(filename.c_str());
    Json::Reader jsonReader;
    
    if (!jsonReader.parse(file, m_jsonRoot))
        m_isOk = false;
    else {
        m_isOk = true;
        
        // Read the waves orders
        for (int i = 0; i < m_jsonRoot["waveOrders"].size(); i++) {
            vector<int> *waveOrder = new vector<int>();
            for (int j = 0; j < m_jsonRoot["waveOrders"][i].size(); j++) {
                waveOrder->push_back(m_jsonRoot["waveOrders"][i][j].asInt());
            }
            m_wavesOrders.push_back(waveOrder);
        }
        
        // Read the waves
        for (int i = 0; i < m_jsonRoot["waves"].size(); i++)
            m_waves.push_back(new Wave(m_jsonRoot["waves"][i]));
    }
}

WavesLoader::~WavesLoader() {
    for (int i = 0; i < m_wavesOrders.size(); i++)
        delete m_wavesOrders[i];
    
    for (int i = 0; i < m_waves.size(); i++)
        delete m_waves[i];
}

bool WavesLoader::isOk() {
    return m_isOk;
}

Wave& WavesLoader::getWave(int index) {
    return *m_waves[index];
}

int WavesLoader::getWaveCount() {
    return m_waves.size();
}

vector<int>& WavesLoader::getWaveOrder(int index) {
    return *m_wavesOrders[index];
}

int WavesLoader::getWaveOrderCount() {
    return m_wavesOrders.size();
}

