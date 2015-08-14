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

#include "Map.hpp"
#include "Sprite.hpp"

bool Application::quit = false;

Application::Application() {
	m_window.create(sf::VideoMode(screenWidth, screenHeight), "CubeLand", sf::Style::Close);
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
	Sprite tileset("graphics/tileset.png", 16, 16);
	
	Map map("data/maps/level0.tmx", tileset);
	
	sf::View view(sf::FloatRect(0, 0, screenWidth, screenHeight));
	
	Map::currentMap = &map;
	
	while(m_window.isOpen()) {
		handleEvents();
		
		m_clock.updateGame([&] {
			if(quit) m_window.close();
			
			m_player.update();
			
			sf::Vector2f playerCenter = m_player.getPosition() + sf::Vector2f(m_player.width(), m_player.height()) / 2.0f;
			view.setCenter(floor(playerCenter.x), floor(playerCenter.y));
		});
		
		m_clock.drawGame([&] {
			m_window.clear();
			
			m_window.setView(view);
			
			m_window.draw(map);
			
			m_window.draw(m_player);
			
			m_window.setView(m_window.getDefaultView());
			
			m_window.display();
		});
	}
}

