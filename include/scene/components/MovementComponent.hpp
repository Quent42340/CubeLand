/*
 * =====================================================================================
 *
 *       Filename:  MovementComponent.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:23:42
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVEMENTCOMPONENT_HPP_
#define MOVEMENTCOMPONENT_HPP_

#include <memory>
#include <stack>

#include <gk/core/Vector2.hpp>

#include "Movement.hpp"

class MovementComponent {
	public:
		MovementComponent(Movement *_movement) : movement(_movement) {}

		gk::Vector2f v{0, 0};

		bool isMoving = false;
		bool isDirectionLocked = false;

		gk::Vector2<bool> isBlocked{false, false};

		std::unique_ptr<Movement> movement;
};

#endif // MOVEMENTCOMPONENT_HPP_
