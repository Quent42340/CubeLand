/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.cpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:49:47
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "KeyboardHandler.hpp"

void KeyboardHandler::resetState() {
	for(auto &it : m_keysPressed) {
		it.second = false;
	}
}

void KeyboardHandler::updateState(const sf::Event &event) {
	for(auto &it : m_keys) {
		if(event.type == sf::Event::KeyPressed && event.key.code == it.second) {
			m_keysPressed[it.first] = true;
		}
	}
}

bool KeyboardHandler::isKeyPressed(GameKey key) {
	return sf::Keyboard::isKeyPressed(m_keys[key]);
}

bool KeyboardHandler::isKeyPressedOnce(GameKey key) {
	return m_keysPressed[key];
}

