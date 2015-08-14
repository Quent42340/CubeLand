/*
 * =====================================================================================
 *
 *       Filename:  Player.hpp
 *
 *    Description:  
 *
 *        Created:  10/08/2015 20:23:53
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "IntTypes.hpp"
#include "Image.hpp"

class Player : public Image {
	public:
		Player();
		
		void checkCollisions();
		
		void update();
		
		float x() const { return getPosition().x; }
		float y() const { return getPosition().y; }
		
		enum class JumpState : u8 {
			Landed,
			Jumping,
			Falling
		};
		
	private:
		float m_speed = 0.5f;
		float m_jumpSpeed = 3.0f;
		
		float m_vx = 0.0f;
		float m_vy = 0.0f;
		
		JumpState m_jumpState = JumpState::Landed;
};

#endif // PLAYER_HPP_
