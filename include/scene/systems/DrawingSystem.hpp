/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:57:52
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DRAWINGSYSTEM_HPP_
#define DRAWINGSYSTEM_HPP_

#include <gk/gl/RenderTarget.hpp>
#include <gk/gl/RenderStates.hpp>

#include "SceneObject.hpp"

class DrawingSystem {
	public:
		static void draw(const SceneObject &object, gk::RenderTarget &target, gk::RenderStates states);
};

#endif // DRAWINGSYSTEM_HPP_
