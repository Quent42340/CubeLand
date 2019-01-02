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
#include <gk/resource/ResourceHandler.hpp>

#include "Application.hpp"
#include "LevelState.hpp"
#include "Map.hpp"
#include "PlayerFactory.hpp"
#include "Scene.hpp"

#include "DoorFactory.hpp"
#include "KeyFactory.hpp"

gk::View LevelState::view{{0, 0, Application::screenWidth, Application::screenHeight}};

LevelState::LevelState(u16 levelID) {
	m_levelID = levelID;

	view.reset({0, 0, Application::screenWidth, Application::screenHeight});

	Map::currentMap = &gk::ResourceHandler::getInstance().get<Map>("level" + std::to_string(m_levelID));

	m_player = PlayerFactory::create(2 * 16, 28 * 16);

	Scene::player = &m_player;

	Scene::currentScene = &gk::ResourceHandler::getInstance().get<Scene>("level" + std::to_string(m_levelID) + "-scene");

	Scene::currentScene->addObject(KeyFactory::create(78, 24, 0));
	Scene::currentScene->addObject(DoorFactory::create(78, 1, 0));
}

void LevelState::update() {
	Scene::currentScene->update();
}

void LevelState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.setView(view);

	target.draw(*Map::currentMap, states);

	target.draw(*Scene::currentScene, states);

	target.setView(target.getDefaultView());
}

