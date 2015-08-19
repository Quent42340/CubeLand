/*
 * =====================================================================================
 *
 *       Filename:  LevelState.cpp
 *
 *    Description:  
 *
 *        Created:  14/08/2015 18:03:42
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "LevelState.hpp"
#include "Map.hpp"
#include "PlayerFactory.hpp"
#include "ResourceHandler.hpp"

sf::View LevelState::view{sf::FloatRect(0, 0, Application::screenWidth, Application::screenHeight)};

LevelState::LevelState() {
	Map::currentMap = &ResourceHandler::getInstance().get<Map>("level0");
	
	m_scene.addObject(PlayerFactory::create(48, 16));
}

void LevelState::update() {
	m_scene.update();
}

void LevelState::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.setView(view);
	
	target.draw(*Map::currentMap, states);
	
	target.draw(m_scene, states);
	
	target.setView(target.getDefaultView());
}

