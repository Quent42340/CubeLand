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
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/component/PositionComponent.hpp>

#include "DoorFactory.hpp"
#include "LevelEndState.hpp"
#include "LockComponent.hpp"

void doorAction(gk::SceneObject &door, gk::SceneObject &object, bool isInCollision);

gk::SceneObject DoorFactory::create(u16 tileX, u16 tileY, u16 lockID) {
	gk::SceneObject door;
	door.set<gk::HitboxComponent>(0, 0, 16, 32);
	door.set<gk::PositionComponent>(tileX * 16, tileY * 16);
	door.set<LockComponent>(lockID, false);

	auto &collisionComponent = door.set<gk::CollisionComponent>();
	collisionComponent.addAction(&doorAction);

	return door;
}

void doorAction(gk::SceneObject &door, gk::SceneObject &object, bool isInCollision) {
	if(isInCollision && object.type() == "player"
	&& !door.get<LockComponent>().isLocked()) {
		auto &stateStack = gk::ApplicationStateStack::getInstance();
		stateStack.push<LevelEndState>(&stateStack.top(), true);
	}
}

