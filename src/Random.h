/* 
 * File:   Random.h
 * Author: Théo
 *
 * Created on 14 août 2013, 03:07
 */

#ifndef RANDOM_H
#define	RANDOM_H

#include <cstdlib>
#include <ctime>

class Random
{
public:
    static int range(int min, int max)
    {
        if (!initialized)
        {
            srand(time(NULL));
            initialized = true;
        }
            
        
        return (rand() % (max - min + 1)) + min;
    }
private:
    static bool initialized;
    
};

#endif	/* RANDOM_H */

