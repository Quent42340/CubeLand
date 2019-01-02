/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.cpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:58:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/gui/Image.hpp>
#include <gk/gui/Sprite.hpp>

#include "DrawingSystem.hpp"

void DrawingSystem::draw(const SceneObject &object, gk::RenderTarget &target, gk::RenderStates states) {
	states.transform *= object.getTransform();

	if(object.has<gk::Image>()) {
		target.draw(object.get<gk::Image>(), states);
	}

	if(object.has<gk::Sprite>()) {
		target.draw(object.get<gk::Sprite>(), states);
	}
}

