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
#include "Application.hpp"
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "Mouse.hpp"
#include "TitleScreenState.hpp"

#include "LevelLoader.hpp"
#include "TilesetLoader.hpp"
#include "TextureLoader.hpp"

#include "LevelEndState.hpp"
#include "LevelState.hpp"
#include "LevelListState.hpp"

bool Application::quit = false;

Application::Application() {
	m_window.create(sf::VideoMode(screenWidth, screenHeight), "CubeLand", sf::Style::Close);
	m_window.setKeyRepeatEnabled(false);
	
	Mouse::setWindow(m_window);
	
	ResourceHandler::setInstance(m_resourceHandler);
	
	m_resourceHandler.loadConfigFile<TextureLoader>("data/config/textures.xml");
	m_resourceHandler.loadConfigFile<TilesetLoader>("data/config/tilesets.xml");
	m_resourceHandler.loadConfigFile<LevelLoader>("data/config/levels.xml");
	
	GamePad::init(m_keyboardHandler);
	
	sf::Font &defaultFont = m_resourceHandler.add<sf::Font>("font-default");
	defaultFont.loadFromFile("fonts/terminus.ttf");
	
	// ApplicationStateStack::getInstance().push<TitleScreenState>();
	// ApplicationStateStack::getInstance().push<LevelListState>();
	ApplicationStateStack::getInstance().push<LevelState>(0);
}

void Application::handleEvents() {
	m_keyboardHandler.resetState();
	
	sf::Event event;
	while(m_window.pollEvent(event)) {
		if((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		 || event.type == sf::Event::Closed) {
			m_window.close();
		}
		
		m_keyboardHandler.updateState(event);
	}
}

void Application::run() {
	while(m_window.isOpen()) {
		handleEvents();
		
		m_clock.updateGame([&] {
			if(quit) m_window.close();
			
			ApplicationStateStack::getInstance().top().update();
		});
		
		m_clock.drawGame([&] {
			m_window.clear();
			
			m_window.draw(ApplicationStateStack::getInstance().top());
			
			m_window.display();
		});
	}
}

