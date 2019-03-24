/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.cpp
 *
 *    Description:
 *
 *        Created:  11/02/2015 15:49:47
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/Debug.hpp>
#include <gk/core/IntTypes.hpp>
#include <gk/core/KeyboardUtils.hpp>
#include <gk/core/XMLFile.hpp>

#include "GameKey.hpp"
#include "KeyboardHandler.hpp"

void KeyboardHandler::loadKeysFromFile(const std::string &filename) {
	gk::XMLFile doc(filename);

	tinyxml2::XMLElement *keys = doc.FirstChildElement("keys").ToElement();

	// Reading keys from names as defined here: https://wiki.libsdl.org/SDL_Keycode
	auto addKey = [&](gk::GameKey key, const char *name) {
		tinyxml2::XMLElement *keyElement = keys->FirstChildElement(name);
		m_keys[key] = gk::KeyboardUtils::getKeyFromName(keyElement->Attribute("key"));

		if(m_keys[key] == sf::Keyboard::Unknown) {
			DEBUG("Key '", keyElement->Attribute("key"), "' not recognized");
		}
	};

	addKey(GameKey::Left,  "Left");
	addKey(GameKey::Right, "Right");
	addKey(GameKey::Up,    "Up");
	addKey(GameKey::Down,  "Down");

	addKey(GameKey::A, "A");
	addKey(GameKey::B, "B");

	addKey(GameKey::Start,  "Start");
	addKey(GameKey::Select, "Select");
}

bool KeyboardHandler::isKeyPressed(gk::GameKey key) {
	m_keysPressed[key] = sf::Keyboard::isKeyPressed(m_keys[key]);

	return m_keysPressed[key];
}

