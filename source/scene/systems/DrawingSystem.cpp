/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.cpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:58:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "DrawingSystem.hpp"
#include "Image.hpp"

void DrawingSystem::draw(const SceneObject &object, sf::RenderTarget &target, sf::RenderStates states) {
	states.transform *= object.getTransform();
	
	if(object.has<Image>()) {
		target.draw(object.get<Image>(), states);
	}
}

