/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.cpp
 *
 *    Description:
 *
 *        Created:  19/08/2015 15:47:53
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/input/GamePad.hpp>
#include <gk/scene/component/MovementComponent.hpp>

#include "GameKey.hpp"
#include "GamePadMovement.hpp"

void GamePadMovement::process(gk::SceneObject &object) {
	auto &movement = object.get<gk::MovementComponent>();

	if(movement.isBlocked.y) {
		m_jumpState = JumpState::Landed;
	}
	else if(movement.v.y >= 0) {
		m_jumpState = JumpState::Falling;
	}

	movement.v.x = 0;

	if(gk::GamePad::isKeyPressed(GameKey::Left)) {
		movement.v.x = -m_speed;
	}
	else if(gk::GamePad::isKeyPressed(GameKey::Right)) {
		movement.v.x = m_speed;
	}

	if(gk::GamePad::isKeyPressed(GameKey::A) && movement.v.y == 0 && m_jumpState == JumpState::Landed) {
		movement.v.y = -m_jumpSpeed;

		m_jumpState = JumpState::Jumping;
	}

	movement.v.y += 0.075f; // Gravity

	if(movement.v.y > m_jumpSpeed) movement.v.y = m_jumpSpeed; // Max jump accel
}

