/*
 * =====================================================================================
 *
 *       Filename:  DoorFactory.cpp
 *
 *    Description:
 *
 *        Created:  01/09/2015 19:56:51
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "DoorFactory.hpp"
#include "LevelEndState.hpp"
#include "Scene.hpp"

#include "CollisionComponent.hpp"
#include "HitboxComponent.hpp"
#include "LockComponent.hpp"

void doorAction(SceneObject &door, SceneObject &object, bool isInCollision);

SceneObject DoorFactory::create(u16 tileX, u16 tileY, u16 lockID) {
	SceneObject door;
	door.set<HitboxComponent>(0, 0, 16, 32);
	door.set<LockComponent>(lockID, false);
	door.setPosition(tileX * 16, tileY * 16);

	auto &collisionComponent = door.set<CollisionComponent>();
	collisionComponent.addAction(&doorAction);

	return door;
}

void doorAction(SceneObject &door, SceneObject &object, bool isInCollision) {
	if(isInCollision && Scene::isPlayer(object)
	&& !door.get<LockComponent>().isLocked()) {
		auto &stateStack = ApplicationStateStack::getInstance();
		stateStack.push<LevelEndState>(&stateStack.top(), true);
	}
}

