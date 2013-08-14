/* 
 * File:   Mob.h
 * Author: Théo
 *
 * Created on 14 août 2013, 02:52
 */

#ifndef MOB_H
#define	MOB_H

#include "Entity.h"

class Mob : public Entity {
public:
    Mob(float x, float y);
    virtual ~Mob();
private:

};

#endif	/* MOB_H */

