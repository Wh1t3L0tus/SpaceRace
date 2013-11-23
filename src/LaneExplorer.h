/* 
 * File:   LaneExplorer.h
 * Author: Théo
 *
 * Created on 15 août 2013, 03:38
 */

#ifndef LANEEXPLORER_H
#define	LANEEXPLORER_H

class LaneExplorer
{
public:
    inline static float getAbscissaFromLane(float x)
    {
        return x * 160.0 - 130.0;
    }
    
    inline static int getLaneFromAbscissa(float x)
    {
        return (x + 130.0) / 160.0;
    }
    
    inline static int laneNumber()
    {
        return 5;
    }
    
    inline static int laneWidth()
    {
        return 100;
    }
};

#endif	/* LANEEXPLORER_H */

