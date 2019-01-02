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
#include <SFML/Window/Keyboard.hpp>

#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"

void GamePadMovement::process(SceneObject &object) {
	auto &movement = object.get<MovementComponent>();

	if(movement.isBlocked.y) {
		m_jumpState = JumpState::Landed;
	}
	else if(movement.v.y >= 0) {
		m_jumpState = JumpState::Falling;
	}

	movement.v.x = 0;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movement.v.x = -m_speed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		movement.v.x = m_speed;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && movement.v.y == 0 && m_jumpState == JumpState::Landed) {
		movement.v.y = -m_jumpSpeed;

		m_jumpState = JumpState::Jumping;
	}

	movement.v.y += 0.075f; // Gravity

	if(movement.v.y > m_jumpSpeed) movement.v.y = m_jumpSpeed; // Max jump accel
}

