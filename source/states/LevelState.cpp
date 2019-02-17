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
#include <gk/scene/controller/BehaviourController.hpp>
#include <gk/scene/controller/MovementController.hpp>
#include <gk/scene/view/SpriteView.hpp>

#include "Application.hpp"
#include "LevelState.hpp"
#include "Map.hpp"
#include "PlayerFactory.hpp"

#include "DoorFactory.hpp"
#include "KeyFactory.hpp"

gk::View LevelState::view{{0, 0, Application::screenWidth, Application::screenHeight}};

LevelState::LevelState(u16 levelID) {
	m_levelID = levelID;

	view.reset({0, 0, Application::screenWidth, Application::screenHeight});

	Map::currentMap = &gk::ResourceHandler::getInstance().get<Map>("level" + std::to_string(m_levelID));

	m_scene = &gk::ResourceHandler::getInstance().get<gk::Scene>("level" + std::to_string(m_levelID) + "-scene");
	m_scene->addController<gk::BehaviourController>();
	m_scene->addController<gk::MovementController>();
	m_scene->addView<gk::SpriteView>();

	m_player = m_scene->addObject(PlayerFactory::create(2 * 16, 28 * 16)); // FIXME: This is weird

	m_scene->addObject(KeyFactory::create(78, 24, 0));
	m_scene->addObject(DoorFactory::create(78, 1, 0));
}

void LevelState::update() {
	m_scene->update();
}

void LevelState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.setView(view);

	target.draw(*Map::currentMap, states);

	target.draw(*m_scene, states);

	target.setView(target.getDefaultView());
}

