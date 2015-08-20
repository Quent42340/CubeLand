/*
 * =====================================================================================
 *
 *       Filename:  InputHandler.cpp
 *
 *    Description:  
 *
 *        Created:  20/08/2015 13:17:34
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "GameClock.hpp"
#include "InputHandler.hpp"

bool InputHandler::isKeyPressedOnce(GameKey key) {
	if(isKeyPressed(key)) {
		if(!m_keysPressed[key]) {
			m_keysPressed[key] = true;
			return true;
		} else {
			return false;
		}
	} else {
		m_keysPressed[key] = false;
		return false;
	}
}

bool InputHandler::isKeyPressedWithDelay(GameKey key, u16 delay) {
	if(isKeyPressed(key) && GameClock::getTicks() - m_lastTimePressed[key] > delay) {
		m_lastTimePressed[key] = GameClock::getTicks();
		return true;
	} else {
		if(!isKeyPressed(key)) m_lastTimePressed[key] = 0;
		return false;
	}
}

