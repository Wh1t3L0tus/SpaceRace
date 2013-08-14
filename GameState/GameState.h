/* 
 * File:   GameState.h
 * Author: Théo
 *
 * Created on 13 août 2013, 19:55
 */

#ifndef GAMESTATE_H
#define	GAMESTATE_H

#include <SFML/Graphics.hpp>

class GameState {
public:
    GameState(): m_pNextState(NULL), m_loopAgain(true) {}
    virtual ~GameState(){};
    
    /** Init
     * Put here things to do before entering this state
     */
    virtual void init() { 
        m_loopAgain = true;
        m_pNextState = NULL;
    }
    
    /** updateLoop
     * Put here your game logic for this state
     * 
     * @param window : the window on which to draw
     * @return false when you have to change of state
     */
    virtual bool updateLoop(sf::RenderWindow &window) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                sf::err() << "Closing the window" << std::endl;
                window.close();
                m_pNextState = NULL;
                m_loopAgain = false;
                return false;
            }
        }
        return true;
    }
    
    /** quit
     * Put here things to do before quitting this state
     */
    virtual GameState* quit() { return m_pNextState; }
    
protected:
    GameState *m_pNextState;
    bool m_loopAgain;

};

#endif	/* GAMESTATE_H */

