/*
 * =====================================================================================
 *
 *       Filename:  SceneObject.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:09:38
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECT_HPP_
#define SCENEOBJECT_HPP_

#include <map>
#include <memory>
#include <typeindex>

#include <SFML/Graphics/Transformable.hpp>

#include "Exception.hpp"

class SceneObject : public sf::Transformable {
	public:
		SceneObject(const std::string &type = "null", const std::string &name = "null")
			: m_name(name), m_type(type) {}
		
		SceneObject(const SceneObject &) = delete;
		SceneObject(SceneObject &&) = default;
		
		SceneObject &operator=(const SceneObject &) = delete;
		SceneObject &operator=(SceneObject &&) = default;
		
		template<typename T, typename... Args>
		T &set(Args &&...args) {
			m_components[typeid(T).hash_code()] = std::make_shared<T>(std::forward<Args>(args)...);
			return get<T>();
		}
		
		template<typename T>
		bool has() const {
			return m_components.count(typeid(T).hash_code()) == 1;
		}
		
		template<typename T>
		T &get() const {
			auto it = m_components.find(typeid(T).hash_code());
			if(it == m_components.end()) {
				throw EXCEPTION("SceneObject", (void*)this, "doesn't have a component of type:", typeid(T).name());
			}
			
			return *std::static_pointer_cast<T>(it->second);
		}
		
		template<typename T>
		void remove() {
			m_components.erase(typeid(T).hash_code());
		}
		
		void debug() const {
			DEBUG("=== Component list of object:", (void*)this, " ===");
			DEBUG("=== List address:", (void*)&m_components);
			
			for(auto &it : m_components) {
				DEBUG(it.first, ":", (void*)it.second.get());
			}
			
			DEBUG("=== End of list. ===");
		}
		
		const std::string &name() const { return m_name; }
		const std::string &type() const { return m_type; }
		
	private:
		std::string m_name;
		std::string m_type;
		
		std::map<size_t, std::shared_ptr<void>> m_components;
};

#endif // SCENEOBJECT_HPP_
