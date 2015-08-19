/*
 * =====================================================================================
 *
 *       Filename:  Mouse.cpp
 *
 *    Description:  
 *
 *        Created:  19/08/2015 21:12:16
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Mouse.hpp"

sf::Window *Mouse::window = nullptr;

sf::Vector2i Mouse::getPosition() {
	return sf::Mouse::getPosition(*window);
}

