/*
 * =====================================================================================
 *
 *       Filename:  Mouse.hpp
 *
 *    Description:  
 *
 *        Created:  19/08/2015 21:05:35
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOUSE_HPP_
#define MOUSE_HPP_

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Mouse.hpp>

class Mouse {
	public:
		static sf::Vector2i getPosition();
		
		template<typename T>
		static bool isInRect(sf::Rect<T> rect) {
			return rect.contains(getPosition().x, getPosition().y);
		}
		
		static void setWindow(sf::Window &_window) { window = &_window; }
		
	private:
		static sf::Window *window;
};

#endif // MOUSE_HPP_
