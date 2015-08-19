/*
 * =====================================================================================
 *
 *       Filename:  MovementSystem.cpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:27:38
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "MovementSystem.hpp"

#include "CollisionComponent.hpp"
#include "MovementComponent.hpp"

void MovementSystem::process(SceneObject &object) {
	if(object.has<MovementComponent>()) {
		auto &movement = object.get<MovementComponent>();
		
		movement.movement->process(object);
		
		movement.isBlocked.x = false;
		movement.isBlocked.y = false;
	}
	
	if(object.has<CollisionComponent>()) {
		object.get<CollisionComponent>().checkCollisions(object);
	}
	
	if(object.has<MovementComponent>()) {
		auto &movement = object.get<MovementComponent>();
		movement.isMoving = (movement.v.x || movement.v.y) ? true : false;
		
		object.move(movement.v);
	}
}

