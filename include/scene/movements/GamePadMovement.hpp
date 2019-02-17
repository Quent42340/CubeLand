/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.hpp
 *
 *    Description:
 *
 *        Created:  19/08/2015 15:47:11
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMEPADMOVEMENT_HPP_
#define GAMEPADMOVEMENT_HPP_

#include <gk/scene/movement/Movement.hpp>

class GamePadMovement : public gk::Movement {
	public:
		void process(gk::SceneObject &object);

		enum class JumpState : u8 {
			Landed,
			Jumping,
			Falling
		};

	private:
		float m_speed = 0.5f;
		float m_jumpSpeed = 3.0f;

		JumpState m_jumpState = JumpState::Landed;
};

#endif // GAMEPADMOVEMENT_HPP_
