/* 
 * File:   WavesLoader.h
 * Author: theo
 *
 * Created on 24 novembre 2013, 19:01
 */

#ifndef WAVESLOADER_H
#define	WAVESLOADER_H

#include <list>
#include <json/json.h>

#include "Wave.h"


using namespace std;

class WavesLoader {
public:
    WavesLoader(string filename);
    virtual ~WavesLoader();
    
    bool isOk();
    
    Wave* getWave(int index);
    int getWaveCount();
    
    list<int>& getWaveOrder(int index);
    int getWaveOrderCount();
    
private:

    Json::Value                  m_jsonRoot;
    bool                         m_isOk;
    
    list<list<int>* >            m_wavesOrders;
    vector<Wave*>                m_waves;
    
};

#endif	/* WAVESLOADER_H */

