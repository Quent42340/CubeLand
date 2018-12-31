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
#include "ApplicationStateStack.hpp"
#include "LevelEndState.hpp"
#include "Scene.hpp"
#include "SpikeFactory.hpp"

#include "CollisionComponent.hpp"
#include "HitboxComponent.hpp"

void spikeAction(SceneObject&, SceneObject &object, bool isInCollision);

SceneObject SpikeFactory::create(u16 tileX, u16 tileY) {
	SceneObject spike;
	spike.set<HitboxComponent>(0, 7, 16, 9);
	spike.setPosition(tileX * 16, tileY * 16);

	auto &collisionComponent = spike.set<CollisionComponent>();
	collisionComponent.addAction(&spikeAction);

	return spike;
}

void spikeAction(SceneObject&, SceneObject &object, bool isInCollision) {
	if(isInCollision && Scene::isPlayer(object)) {
		auto &stateStack = ApplicationStateStack::getInstance();
		stateStack.push<LevelEndState>(&stateStack.top(), false);
	}
}


