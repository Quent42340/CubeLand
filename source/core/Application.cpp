/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:
 *
 *        Created:  12/08/2015 19:44:00
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/input/GamePad.hpp>
#include <gk/resource/TextureLoader.hpp>

#include "Application.hpp"
#include "TitleScreenState.hpp"

#include "LevelLoader.hpp"
#include "TilesetLoader.hpp"

#include "LevelEndState.hpp"
#include "LevelState.hpp"
#include "LevelListState.hpp"

void Application::init() {
	gk::CoreApplication::init();

	createWindow(sf::VideoMode(screenWidth, screenHeight), "CubeLand", sf::Style::Close);

	m_resourceHandler.loadConfigFile<gk::TextureLoader>("resources/config/textures.xml");
	m_resourceHandler.loadConfigFile<TilesetLoader>("resources/config/tilesets.xml");
	m_resourceHandler.loadConfigFile<LevelLoader>("resources/config/levels.xml");
	m_resourceHandler.add<sf::Font>("font-default").loadFromFile("resources/fonts/terminus.ttf");

	m_keyboardHandler.loadKeysFromFile("resources/config/keys.xml");
	gk::GamePad::init(m_keyboardHandler);

	m_stateStack.push<TitleScreenState>();
	// m_stateStack.push<LevelListState>();
	// m_stateStack.push<LevelState>(0);
}

void Application::onEvent(const sf::Event &event) {
	gk::CoreApplication::onEvent(event);

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		m_isRunning = false;
	}
}

