/*
 * =====================================================================================
 *
 *       Filename:  CollisionSystem.cpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 00:09:30
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "CollisionSystem.hpp"
#include "Sprite.hpp"
#include "Utils.hpp"

#include "CollisionComponent.hpp"
#include "HitboxComponent.hpp"
#include "MovementComponent.hpp"

void CollisionSystem::checkCollision(SceneObject &object1, SceneObject &object2) {
	bool inCollision = CollisionSystem::inCollision(object1, object2);
	
	if(object1.has<CollisionComponent>()) {
		object1.get<CollisionComponent>().collisionActions(object1, object2, inCollision);
	}
	
	if(object2.has<CollisionComponent>()) {
		object2.get<CollisionComponent>().collisionActions(object2, object1, inCollision);
	}
}

bool CollisionSystem::inCollision(SceneObject &object1, SceneObject &object2) {
	if(object1.has<HitboxComponent>() && object2.has<HitboxComponent>()) {
		auto &hitbox1 = object1.get<HitboxComponent>();
		auto &hitbox2 = object2.get<HitboxComponent>();
		
		if(hitbox1.currentHitbox() && hitbox2.currentHitbox()) {
			sf::FloatRect rect1 = *hitbox1.currentHitbox();
			sf::FloatRect rect2 = *hitbox2.currentHitbox();
			
			rect1 += object1.getPosition();
			rect2 += object2.getPosition();
			
			if(object1.has<MovementComponent>()) {
				rect1 += object1.get<MovementComponent>().v;
			}
			
			if(object2.has<MovementComponent>()) {
				rect2 += object2.get<MovementComponent>().v;
			}
			
			if(rect1.intersects(rect2)) {
				return true;
			}
		}
	}
	
	return false;
}

