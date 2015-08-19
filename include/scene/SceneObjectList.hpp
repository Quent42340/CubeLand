/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectList.hpp
 *
 *    Description:  
 *
 *        Created:  07/05/2015 17:24:15
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECTLIST_HPP_
#define SCENEOBJECTLIST_HPP_

#include <deque>

#include "CollisionComponent.hpp"
#include "CollisionSystem.hpp"
#include "SceneObject.hpp"

class SceneObjectList {
	using iterator = std::deque<SceneObject>::iterator;
	using const_iterator = std::deque<SceneObject>::const_iterator;
	
	public:
		SceneObject &addObject(SceneObject &&object) {
			m_objects.emplace_back(std::move(object));
			
			SceneObject &obj = m_objects.back();
			
			if(obj.has<CollisionComponent>()) {
				obj.get<CollisionComponent>().addChecker([&](SceneObject &object) {
					for(SceneObject &object2 : m_objects) {
						if(&object != &object2) {
							CollisionSystem::checkCollision(object, object2);
						}
					}
				});
			}
			
			return obj;
		}
		
		SceneObject &operator[](size_t n) { return m_objects[n]; }
		
		void remove(size_t n) { m_objects.erase(m_objects.begin() + n); }
		
		iterator begin() noexcept { return m_objects.begin(); }
		iterator end() noexcept { return m_objects.end(); }
		
		const_iterator begin() const noexcept { return m_objects.begin(); }
		const_iterator end() const noexcept { return m_objects.end(); }
		
		size_t size() const { return m_objects.size(); }
		
	private:
		std::deque<SceneObject> m_objects;
};

#endif // SCENEOBJECTLIST_HPP_
