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

#include <gk/gui/Image.hpp>

#include "Application.hpp"
#include "CollisionSystem.hpp"
#include "GamePadMovement.hpp"
#include "LevelState.hpp"
#include "Map.hpp"
#include "PlayerFactory.hpp"
#include "Scene.hpp"

#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "HitboxComponent.hpp"
#include "MovementComponent.hpp"

void checkCollisions(SceneObject &player);
void scrollLevel(SceneObject &player);

SceneObject PlayerFactory::create(u16 x, u16 y) {
	SceneObject player;
	player.set<HitboxComponent>(0, 0, 16, 16);
	player.set<gk::Image>("characters-player");
	player.set<MovementComponent>(new GamePadMovement);
	player.setPosition(x, y);

	auto &collisionComponent = player.set<CollisionComponent>();
	collisionComponent.addChecker(&checkCollisions);

	collisionComponent.addChecker([&](SceneObject &object) {
		for(SceneObject &object2 : Scene::currentScene->objects()) {
			if(&object != &object2) {
				CollisionSystem::checkCollision(object, object2);
			}
		}
	});

	auto &behaviourComponent = player.set<BehaviourComponent>();
	behaviourComponent.addAction("scrollLevel", &scrollLevel);

	return player;
}

void checkCollisions(SceneObject &player) {
	auto &movement = player.get<MovementComponent>();

	gk::FloatRect hitbox(0, 0, player.get<gk::Image>().width(), player.get<gk::Image>().height());

	float hitboxX1 = player.getPosition().x + hitbox.x;
	float hitboxY1 = player.getPosition().y + hitbox.y;

	float hitboxX2 = hitboxX1 + hitbox.width - 1.0f;
	float hitboxY2 = hitboxY1 + hitbox.height - 1.0f;

	gk::Vector2f sides[4][4] = {
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

void scrollLevel(SceneObject &player) {
	gk::Vector2f screenHalfSize{Application::screenWidth  / 2,
	                            Application::screenHeight / 2};

	gk::Vector2i mapSize{Map::currentMap->width()  * Map::currentMap->tileset().tileWidth(),
	                     Map::currentMap->height() * Map::currentMap->tileset().tileHeight()};

	gk::Vector2f playerCenter{
		player.getPosition().x + player.get<gk::Image>().width() / 2.0f,
		player.getPosition().y + player.get<gk::Image>().height() / 2.0f,
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

