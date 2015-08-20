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

#include "GamePadMovement.hpp"
#include "Image.hpp"
#include "PlayerFactory.hpp"

#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "MovementComponent.hpp"

void checkCollisions(SceneObject &player);
void scrollLevel(SceneObject &player);

SceneObject PlayerFactory::create(u16 x, u16 y) {
	SceneObject player;
	player.setPosition(x, y);
	player.set<Image>("characters-player");
	player.set<MovementComponent>(new GamePadMovement());
	
	auto &collisionComponent = player.set<CollisionComponent>();
	collisionComponent.addChecker(&checkCollisions);
	
	auto &behaviourComponent = player.set<BehaviourComponent>();
	behaviourComponent.addAction("scrollLevel", &scrollLevel);
	
	return player;
}

#include "Map.hpp"

void checkCollisions(SceneObject &player) {
	// {12, 8,12,13},
	// { 4, 8, 4,13},
	// { 5, 5,10, 5},
	// { 5,15,10,15}
	// => (5, 5, 5, 10)
	// => (4, 8, 8, 5)
	// ................
	// ................
	// ................
	// ................
	// ................
	// ................
	// .....******.....
	// .....*....*.....
	// ....++++++++....
	// ....+*....*+....
	// ....+*....*+....
	// ....+*....*+....
	// ....++++++++....
	// .....*....*.....
	// .....******.....
	// ................
	// => (5, 8, 5, 6)
	// {10, 8,10,14},
	// { 5, 8, 5,14},
	// { 5, 8,10, 8},
	// { 5,14,10,14}
	auto &movement = player.get<MovementComponent>();
	
	sf::FloatRect hitbox(0, 0, player.get<Image>().width(), player.get<Image>().height());
	
	float hitboxX1 = player.getPosition().x + hitbox.left;
	float hitboxY1 = player.getPosition().y + hitbox.top;
	
	float hitboxX2 = hitboxX1 + hitbox.width - 1.0f;
	float hitboxY2 = hitboxY1 + hitbox.height - 1.0f;
	
	float collisionMatrix[4][4] = {
		{hitboxX2, hitboxY1, hitboxX2, hitboxY2},
		{hitboxX1, hitboxY1, hitboxX1, hitboxY2},
		{hitboxX1, hitboxY1, hitboxX2, hitboxY1},
		{hitboxX1, hitboxY2, hitboxX2, hitboxY2}
	};
	
	for(u8 i = 0 ; i < 4 ; i++) {
		bool test;
		
		if(i == 0) {
			test = movement.v.x > 0;
		}
		else if(i == 1) {
			test = movement.v.x < 0;
		}
		else if(i == 2) {
			test = movement.v.y < 0;
		}
		else if(i == 3) {
			test = movement.v.y > 0;
		}
		
		if(test
		&& (!Map::currentMap->isPassable(collisionMatrix[i][0] + ((i < 2) ? movement.v.x : 0.0f), ceil(collisionMatrix[i][1] + ((i > 1) ? movement.v.y : 0.0f)))
		 || !Map::currentMap->isPassable(collisionMatrix[i][2] + ((i < 2) ? movement.v.x : 0.0f), ceil(collisionMatrix[i][3] + ((i > 1) ? movement.v.y : 0.0f))))) {
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

#include "Application.hpp"
#include "LevelState.hpp"

void scrollLevel(SceneObject &player) {
	sf::Vector2f playerCenter = player.getPosition() + sf::Vector2f(player.get<Image>().width(), player.get<Image>().height()) / 2.0f;
	
	sf::Vector2f screenHalfSize{Application::screenWidth  / 2,
	                            Application::screenHeight / 2};
	
	sf::Vector2i mapSize{Map::currentMap->width()  * Map::currentMap->tileset().tileWidth(),
	                     Map::currentMap->height() * Map::currentMap->tileset().tileHeight()};
	
	if(playerCenter.x > screenHalfSize.x
	&& playerCenter.x < mapSize.x - screenHalfSize.x) {
		LevelState::view.setCenter(floor(playerCenter.x), LevelState::view.getCenter().y);
	}
	
	if(playerCenter.y > screenHalfSize.y
	&& playerCenter.y < mapSize.y - screenHalfSize.y) {
		LevelState::view.setCenter(LevelState::view.getCenter().x, floor(playerCenter.y));
	}
}

