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
    static int getAbscissaFromLane(int x)
    {
        return x * 160 - 130;
    }
    
    static int getLaneFromAbscissa(int x)
    {
        return (x + 130) / 160;
    }
};

#endif	/* LANEEXPLORER_H */

