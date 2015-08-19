/*
 * =====================================================================================
 *
 *       Filename:  MovementComponent.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:23:42
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVEMENTCOMPONENT_HPP_
#define MOVEMENTCOMPONENT_HPP_

#include <memory>
#include <stack>

#include <SFML/System/Vector2.hpp>

#include "Movement.hpp"

class MovementComponent {
	public:
		MovementComponent(Movement *_movement) : movement(_movement) {}
		
		sf::Vector2f v{0, 0};
		
		bool isMoving = false;
		bool isDirectionLocked = false;
		
		sf::Vector2<bool> isBlocked{false, false};
		
		std::unique_ptr<Movement> movement;
};

#endif // MOVEMENTCOMPONENT_HPP_
