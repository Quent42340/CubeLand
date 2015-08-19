/*
 * =====================================================================================
 *
 *       Filename:  Scene.hpp
 *
 *    Description:  
 *
 *        Created:  07/05/2015 17:05:23
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <SFML/Graphics/Drawable.hpp>

#include "SceneObject.hpp"
#include "SceneObjectList.hpp"

class Scene : public sf::Drawable {
	public:
		SceneObject &addObject(SceneObject &&object);
		
		void reset();
		void update();
		
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		
		void resetObject(SceneObject &object);
		void updateObject(SceneObject &object);
		void drawObject(const SceneObject &object, sf::RenderTarget &target, sf::RenderStates states) const;
		
		SceneObjectList m_objects;
};

#endif // SCENE_HPP_
