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
#include "Scene.hpp"

#include "DoorFactory.hpp"
#include "KeyFactory.hpp"

sf::View LevelState::view{sf::FloatRect(0, 0, Application::screenWidth, Application::screenHeight)};

LevelState::LevelState(u16 levelID) {
	m_levelID = levelID;
	
	view.reset(sf::FloatRect(0, 0, Application::screenWidth, Application::screenHeight));
	
	Map::currentMap = &ResourceHandler::getInstance().get<Map>("level" + std::to_string(m_levelID));
	
	m_player = PlayerFactory::create(2 * 16, 28 * 16);
	
	Scene::player = &m_player;
	
	Scene::currentScene = &ResourceHandler::getInstance().get<Scene>("level" + std::to_string(m_levelID) + "-scene");
	
	Scene::currentScene->addObject(KeyFactory::create(78, 24, 0));
	Scene::currentScene->addObject(DoorFactory::create(78, 1, 0));
}

void LevelState::update() {
	Scene::currentScene->update();
}

void LevelState::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.setView(view);
	
	target.draw(*Map::currentMap, states);
	
	target.draw(*Scene::currentScene, states);
	
	target.setView(target.getDefaultView());
}

