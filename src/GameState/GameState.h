/* 
 * File:   GameState.h
 * Author: Théo
 *
 * Created on 13 août 2013, 19:55
 */

#ifndef GAMESTATE_H
#define	GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class GameState {
public:
    GameState(): m_pNextState(NULL), m_loopAgain(true) {}
    virtual ~GameState(){};
    
    /** Init
     * Put here things to do before entering this state
     */
    virtual void init() {}
    
    void initState()
    {
        m_loopAgain = true;
        m_pNextState = NULL;
        init();
    }
    
    /** handleNotifiedEvents
     * Put here codes to handle notified events such as key released or mouse wheel moved
     * 
     * @param sf::Event& event : the event to handle
     * @param float elapsedTime : the time elapsed since the last frame
     */
    virtual void handleNotifiedEvents(sf::Event&, float){}
    
    /** updateLoop
     * Call update and the handleX methods which are defined by the user
     * 
     * @param window : the window on which to draw
     * @param elapsedTime : the time elapsed since the last frame
     * @return false when you have to change of state
     */
    bool updateLoop(sf::RenderWindow &window, float elapsedTime) {
        sf::Event event;
        m_loopAgain = true;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                handleCloseEvent(window);
            }
            else
                handleNotifiedEvents(event, elapsedTime);
        }
        
        if (m_loopAgain)
            update(window, elapsedTime);   
        
        return m_loopAgain;
    }
    
    /** update
     * Put here your game logic for this state
     * 
     * @param window : the window on which to draw
     * @param elapsedTime : the time elapsed since the last frame
     */
    virtual void update(sf::RenderWindow &window, float elapsedTime) = 0;
    
    /** handleCloseEvent
     * Put here what to do on "close window" requests
     * @param window : the window to close
     */
    virtual void handleCloseEvent(sf::RenderWindow& window)
    {
        window.close();
        m_pNextState = NULL;
        m_loopAgain = false;
    }
    
    /**
     * Quit the current state to go to the state "state"
     * @param state : the next state to run (can be NULL)
     */
    void goToState(GameState* state) {
        m_loopAgain = false;
        m_pNextState = state;
    }
    
    /**
     * Quit the current state and quit the StateManager::run() method
     */
    void exit() {
        goToState(NULL);
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

