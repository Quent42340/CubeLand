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
#include "Mouse.hpp"
#include "ResourceHandler.hpp"
#include "TitleScreenState.hpp"

#include "LevelLoader.hpp"
#include "TilesetLoader.hpp"
#include "TextureLoader.hpp"

#include "LevelState.hpp"

bool Application::quit = false;

Application::Application() {
	m_window.create(sf::VideoMode(screenWidth, screenHeight), "CubeLand", sf::Style::Close);
	
	Mouse::setWindow(m_window);
	
	ResourceHandler::getInstance().loadConfigFile<TextureLoader>("data/config/textures.xml");
	ResourceHandler::getInstance().loadConfigFile<TilesetLoader>("data/config/tilesets.xml");
	ResourceHandler::getInstance().loadConfigFile<LevelLoader>("data/config/levels.xml");
	
	sf::Font &defaultFont = ResourceHandler::getInstance().add<sf::Font>("font-default");
	defaultFont.loadFromFile("fonts/terminus.ttf");
	
	ApplicationStateStack::getInstance().push<TitleScreenState>();
	// ApplicationStateStack::getInstance().push<LevelState>(0);
}

void Application::handleEvents() {
	sf::Event event;
	while(m_window.pollEvent(event)) {
		if(event.type == sf::Event::Closed) {
			m_window.close();
		}
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

