/* 
 * File:   Player.h
 * Author: Théo
 *
 * Created on 14 août 2013, 01:01
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "Entity.h"


class Player : public Entity {
public:
    Player();
    virtual ~Player();
    
    bool isAlive();
    void destroy();
private:
    bool m_alive;
};

#endif	/* PLAYER_H */

