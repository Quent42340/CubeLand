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
#include "KeyFactory.hpp"

#include "CollisionComponent.hpp"
#include "HitboxComponent.hpp"
#include "LockComponent.hpp"

void keyAction(SceneObject &key, SceneObject &object, bool inCollision);

SceneObject KeyFactory::create(u16 tileX, u16 tileY, u16 lockID) {
	SceneObject key;
	key.set<HitboxComponent>(4, 0, 9, 16);
	key.set<LockComponent>(lockID, true);
	key.setPosition(tileX * 16, tileY * 16);
	
	auto &collisionComponent = key.set<CollisionComponent>();
	collisionComponent.addAction(&keyAction);
	
	return key;
}

#include "Map.hpp"
#include "Scene.hpp"

void keyAction(SceneObject &key, SceneObject &object, bool inCollision) {
	if(inCollision && Scene::isPlayer(object)) {
		key.get<LockComponent>().unlock();
		
		DEBUG("Collision!");
		
		Map::currentMap->setTile(key.getPosition().x / 16, key.getPosition().y / 16, 0);
	}
}

