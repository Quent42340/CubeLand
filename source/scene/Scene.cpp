/*
 * =====================================================================================
 *
 *       Filename:  Scene.cpp
 *
 *    Description:  
 *
 *        Created:  07/05/2015 17:07:43
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Scene.hpp"

#include "BehaviourSystem.hpp"
#include "DrawingSystem.hpp"
#include "LockSystem.hpp"
#include "MovementSystem.hpp"

Scene *Scene::currentScene = nullptr;

SceneObject *Scene::player = nullptr;

SceneObject &Scene::addObject(SceneObject &&object) {
	return m_objects.addObject(std::move(object));
}

void Scene::reset() {
	resetObject(*player);
	
	for(auto &object : m_objects) resetObject(object);
}

void Scene::update() {
	updateObject(*player);
	
	for(auto &object : m_objects) updateObject(object);
	
	LockSystem::update(m_objects);
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	drawObject(*player, target, states);
	
	for(const auto &object : m_objects) drawObject(object, target, states);
}

void Scene::resetObject(SceneObject &object) {
}

void Scene::updateObject(SceneObject &object) {
	MovementSystem::process(object);
	BehaviourSystem::process(object);
	
	if(object.has<SceneObjectList>()) {
		SceneObjectList &objects = object.get<SceneObjectList>();
		for(auto &object : objects) {
			updateObject(object);
		}
	}
}

void Scene::drawObject(const SceneObject &object, sf::RenderTarget &target, sf::RenderStates states) const {
	if(object.has<SceneObjectList>()) {
		const SceneObjectList &objects = object.get<SceneObjectList>();
		for(auto &object : objects) {
			DrawingSystem::draw(object, target, states);
		}
	}
	
	DrawingSystem::draw(object, target, states);
}

