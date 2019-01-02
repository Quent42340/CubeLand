/*
 * =====================================================================================
 *
 *       Filename:  SpikeFactory.cpp
 *
 *    Description:
 *
 *        Created:  02/09/2015 21:34:32
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/component/PositionComponent.hpp>

#include "LevelEndState.hpp"
#include "SpikeFactory.hpp"

gk::SceneObject SpikeFactory::create(u16 tileX, u16 tileY) {
	gk::SceneObject spike;
	spike.set<gk::HitboxComponent>(0, 7, 16, 9);
	spike.set<gk::PositionComponent>(tileX * 16, tileY * 16);

	auto &collisionComponent = spike.set<gk::CollisionComponent>();
	collisionComponent.addAction(&SpikeFactory::action);

	return spike;
}

void SpikeFactory::action(gk::SceneObject&, gk::SceneObject &object, bool isInCollision) {
	if(isInCollision && object.type() == "player") {
		auto &stateStack = gk::ApplicationStateStack::getInstance();
		stateStack.push<LevelEndState>(&stateStack.top(), false);
	}
}


