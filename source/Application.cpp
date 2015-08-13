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
	m_window.create(sf::VideoMode(640, 480), "CubeLand", sf::Style::Close);
}

void Application::run() {
	Sprite tileset("graphics/tileset.png", 16, 16);
	
	Map map("data/maps/level0.tmx", tileset);
	
	Map::currentMap = &map;
	
	while(m_window.isOpen()) {
		sf::Event event;
		while(m_window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				m_window.close();
			}
		}
		
		m_clock.updateGame([&] {
			if(quit) m_window.close();
			
			m_player.update();
		});
		
		m_clock.drawGame([&] {
			m_window.clear();
			
			m_window.draw(map);
			
			m_window.draw(m_player);
			
			m_window.display();
		});
	}
}

