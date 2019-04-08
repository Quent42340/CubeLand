/*
 * =====================================================================================
 *
 *       Filename:  KeyFactory.cpp
 *
 *    Description:
 *
 *        Created:  29/08/2015 18:46:43
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/graphics/Tilemap.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/component/PositionComponent.hpp>

#include "GameData.hpp"
#include "KeyFactory.hpp"
#include "LockComponent.hpp"

void keyAction(gk::SceneObject &key, gk::SceneObject &object, bool isInCollision);

gk::SceneObject KeyFactory::create(u16 tileX, u16 tileY, u16 lockID) {
	gk::SceneObject key;
	key.set<gk::PositionComponent>(tileX * 16, tileY * 16);
	key.set<gk::HitboxComponent>(4, 0, 9, 16);
	key.set<LockComponent>(lockID, true);

	auto &collisionComponent = key.set<gk::CollisionComponent>();
	collisionComponent.addAction(&keyAction);

	return key;
}

void keyAction(gk::SceneObject &key, gk::SceneObject &object, bool isInCollision) {
	if(isInCollision && object.type() == "player") {
		key.get<LockComponent>().unlock();

		auto &position = key.get<gk::PositionComponent>();
		GameData::currentMap->setTile(position.x / 16, position.y / 16, 0);
	}
}

