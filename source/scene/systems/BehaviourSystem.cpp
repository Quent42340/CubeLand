/*
 * =====================================================================================
 *
 *       Filename:  BehaviourSystem.cpp
 *
 *    Description:
 *
 *        Created:  19/08/2015 17:55:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "BehaviourComponent.hpp"
#include "BehaviourSystem.hpp"

void BehaviourSystem::process(SceneObject &object) {
	if(object.has<BehaviourComponent>()) {
		object.get<BehaviourComponent>().update(object);
	}
}

