/*
 * =====================================================================================
 *
 *       Filename:  InputHandler.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 17:16:57
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef INPUTHANDLER_HPP_
#define INPUTHANDLER_HPP_

#include <map>

#include <SFML/Window/Event.hpp>

#include "GameKey.hpp"
#include "IntTypes.hpp"

class InputHandler {
	public:
		virtual ~InputHandler() = default;
		
		virtual bool isKeyPressed(GameKey key) = 0;
		virtual bool isKeyPressedOnce(GameKey key);
		virtual bool isKeyPressedWithDelay(GameKey key, u16 delay);
		
	protected:
		std::map<GameKey, bool> m_keysPressed{
			{GameKey::Left,     false},
			{GameKey::Right,    false},
			{GameKey::Up,       false},
			{GameKey::Down,     false},
			
			{GameKey::A,        false},
			{GameKey::B,        false},
			
			{GameKey::Start,    false},
			{GameKey::Select,   false}
		};
		
		std::map<GameKey, u32> m_lastTimePressed{
			{GameKey::Left,     0},
			{GameKey::Right,    0},
			{GameKey::Up,       0},
			{GameKey::Down,     0},
			
			{GameKey::A,        0},
			{GameKey::B,        0},
			
			{GameKey::Start,    0},
			{GameKey::Select,   0}
		};
};

#endif // INPUTHANDLER_HPP_
