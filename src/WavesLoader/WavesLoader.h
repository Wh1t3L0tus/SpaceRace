/* 
 * File:   WavesLoader.h
 * Author: theo
 *
 * Created on 24 novembre 2013, 19:01
 */

#ifndef WAVESLOADER_H
#define	WAVESLOADER_H

#include <vector>
#include <json/json.h>

#include "Wave.h"


using namespace std;

class WavesLoader {
public:
    WavesLoader();
    virtual ~WavesLoader();
    
    bool isOk();
    
    Wave& getWave(int index);
    int getWaveCount();
    
    vector<int>& getWaveOrder(int index);
    int getWaveOrderCount();
    
private:

    Json::Value                  m_jsonRoot;
    bool                         m_isOk;
    
    vector<vector<int>* >        m_wavesOrders;
    vector<Wave*>                m_waves;
    
};

#endif	/* WAVESLOADER_H */

