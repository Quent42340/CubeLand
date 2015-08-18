/*
 * =====================================================================================
 *
 *       Filename:  Utils.hpp
 *
 *    Description:  
 *
 *        Created:  18/08/2015 03:08:56
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

template<typename T>
sf::Rect<T> operator+(const sf::Rect<T> &rect, const sf::Vector2<T> &vec) {
	return sf::Rect<T>(rect.left + vec.x, rect.top + vec.y, rect.width, rect.height);
}

template<typename T>
sf::Rect<T> operator+=(const sf::Rect<T> &rect, const sf::Vector2<T> &vec) {
	return rect + vec;
}

#endif // UTILS_HPP_
