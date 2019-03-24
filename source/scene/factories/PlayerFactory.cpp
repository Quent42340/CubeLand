/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.cpp
 *
 *    Description:
 *
 *        Created:  19/08/2015 15:36:11
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <cmath>

#include <gk/graphics/Image.hpp>
#include <gk/scene/behaviour/EasyBehaviour.hpp>
#include <gk/scene/component/BehaviourComponent.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/component/MovementComponent.hpp>
#include <gk/scene/component/PositionComponent.hpp>

#include "Application.hpp"
#include "GameKey.hpp"
#include "GamePadMovement.hpp"
#include "LevelState.hpp"
#include "Map.hpp"
#include "PlayerFactory.hpp"

gk::SceneObject PlayerFactory::create(u16 x, u16 y) {
	gk::SceneObject player{"player", "player"};
	player.set<gk::HitboxComponent>(0, 0, 16, 16);
	player.set<gk::Image>("texture-characters-player");
	player.set<gk::PositionComponent>(x, y);

	player.set<gk::MovementComponent>(new GamePadMovement);

	auto &collisionComponent = player.set<gk::CollisionComponent>();
	collisionComponent.addChecker(&checkCollisions);

	auto &behaviourComponent = player.set<gk::BehaviourComponent>();
	behaviourComponent.addBehaviour<gk::EasyBehaviour>("scrollLevel", &scrollLevel);

	return player;
}

void PlayerFactory::checkCollisions(gk::SceneObject &player) {
	auto &position = player.get<gk::PositionComponent>();
	auto &movement = player.get<gk::MovementComponent>();

	sf::FloatRect hitbox(0, 0, player.get<gk::Image>().width(), player.get<gk::Image>().height());

	float hitboxX1 = position.x + hitbox.left;
	float hitboxY1 = position.y + hitbox.top;

	float hitboxX2 = hitboxX1 + hitbox.width - 1.0f;
	float hitboxY2 = hitboxY1 + hitbox.height - 1.0f;

	sf::Vector2f sides[4][4] = {
		{{hitboxX2, hitboxY1}, {hitboxX2, hitboxY2}},
		{{hitboxX1, hitboxY1}, {hitboxX1, hitboxY2}},
		{{hitboxX1, hitboxY1}, {hitboxX2, hitboxY1}},
		{{hitboxX1, hitboxY2}, {hitboxX2, hitboxY2}}
	};

	for(u8 i = 0 ; i < 4 ; i++) {
		bool test;

		switch(i) {
			case 0: test = movement.v.x > 0; break;
			case 1: test = movement.v.x < 0; break;
			case 2: test = movement.v.y < 0; break;
			case 3: test = movement.v.y > 0; break;
		}

		float vx = (i < 2) ? movement.v.x : 0.0f;
		float vy = (i > 1) ? movement.v.y : 0.0f;

		if(test
		&& (!Map::currentMap->isPassable(sides[i][0].x + vx, ceil(sides[i][0].y + vy))
		 || !Map::currentMap->isPassable(sides[i][1].x + vx, ceil(sides[i][1].y + vy)))) {
			if(i < 2) {
				movement.v.x = 0;

				movement.isBlocked.x = true;
			}
			else if(i == 2) {
				movement.v.y = 0;
			}
			else if(i == 3) {
				movement.v.y = 0;

				movement.isBlocked.y = true;
			}
		}
	}
}

void PlayerFactory::scrollLevel(gk::SceneObject &player) {
	sf::Vector2f screenHalfSize{Application::screenWidth  / 2,
	                            Application::screenHeight / 2};

	sf::Vector2i mapSize{Map::currentMap->width()  * Map::currentMap->tileset().tileWidth(),
	                     Map::currentMap->height() * Map::currentMap->tileset().tileHeight()};

	auto position = player.get<gk::PositionComponent>();
	sf::Vector2f playerCenter{
		position.x + player.get<gk::Image>().width() / 2.0f,
		position.y + player.get<gk::Image>().height() / 2.0f,
	};

	if (playerCenter.x > screenHalfSize.x
	 && playerCenter.x < mapSize.x - screenHalfSize.x) {
		LevelState::view.setCenter(floor(playerCenter.x), LevelState::view.getCenter().y);
	}

	if (playerCenter.y > screenHalfSize.y
	 && playerCenter.y < mapSize.y - screenHalfSize.y) {
		LevelState::view.setCenter(LevelState::view.getCenter().x, floor(playerCenter.y));
	}
}

