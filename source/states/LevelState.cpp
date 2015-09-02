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

#include "DoorFactory.hpp"
#include "KeyFactory.hpp"
#include "SpikeFactory.hpp"

sf::View LevelState::view{sf::FloatRect(0, 0, Application::screenWidth, Application::screenHeight)};

LevelState::LevelState(u16 levelID) {
	m_levelID = levelID;
	
	Map::currentMap = &ResourceHandler::getInstance().get<Map>("level" + std::to_string(m_levelID));
	
	m_player = PlayerFactory::create(2 * 16, 28 * 16);
	
	m_scene.addObject(KeyFactory::create(78, 24, 0));
	m_scene.addObject(DoorFactory::create(78, 1, 0));
	
	m_scene.addObject(SpikeFactory::create(14, 28));
	m_scene.addObject(SpikeFactory::create(15, 28));
	m_scene.addObject(SpikeFactory::create(16, 28));
	m_scene.addObject(SpikeFactory::create(17, 28));
	m_scene.addObject(SpikeFactory::create(18, 28));
	
	Scene::player = &m_player;
	
	Scene::currentScene = &m_scene;
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

