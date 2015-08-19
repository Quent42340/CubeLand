/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:57:52
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DRAWINGSYSTEM_HPP_
#define DRAWINGSYSTEM_HPP_

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "SceneObject.hpp"

class DrawingSystem {
	public:
		static void draw(const SceneObject &object, sf::RenderTarget &target, sf::RenderStates states);
};

#endif // DRAWINGSYSTEM_HPP_
