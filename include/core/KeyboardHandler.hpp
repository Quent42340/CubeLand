/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.hpp
 *
 *    Description:
 *
 *        Created:  11/02/2015 15:49:54
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef KEYBOARDHANDLER_HPP_
#define KEYBOARDHANDLER_HPP_

#include <map>

#include <SFML/Window/Keyboard.hpp>

#include <gk/core/input/InputHandler.hpp>

class KeyboardHandler : public gk::InputHandler {
	public:
		void loadKeysFromFile(const std::string &filename);

		bool isKeyPressed(gk::GameKey key);

	private:
		std::map<gk::GameKey, sf::Keyboard::Key> m_keys;
};

#endif // KEYBOARDHANDLER_HPP_
