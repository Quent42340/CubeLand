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
#include "LevelState.hpp"
#include "ResourceHandler.hpp"

#include "LevelLoader.hpp"
#include "TilesetLoader.hpp"
#include "TextureLoader.hpp"

bool Application::quit = false;

Application::Application() {
	m_window.create(sf::VideoMode(screenWidth, screenHeight), "CubeLand", sf::Style::Close);
	
	ResourceHandler::getInstance().loadConfigFile<TextureLoader>("data/config/textures.xml");
	ResourceHandler::getInstance().loadConfigFile<TilesetLoader>("data/config/tilesets.xml");
	ResourceHandler::getInstance().loadConfigFile<LevelLoader>("data/config/levels.xml");
	
	ApplicationStateStack::getInstance().push<LevelState>();
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

