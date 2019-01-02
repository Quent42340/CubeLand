/*
 * =====================================================================================
 *
 *       Filename:  Scene.cpp
 *
 *    Description:
 *
 *        Created:  07/05/2015 17:07:43
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Scene.hpp"

#include "BehaviourSystem.hpp"
#include "DrawingSystem.hpp"
#include "MovementSystem.hpp"

Scene *Scene::currentScene = nullptr;

SceneObject *Scene::player = nullptr;

SceneObject &Scene::addObject(SceneObject &&object) {
	return m_objects.addObject(std::move(object));
}

void Scene::reset() {
	if (player) {
		resetObject(*player);
	}

	for(auto &object : m_objects) resetObject(object);
}

void Scene::update() {
	if (player) {
		updateObject(*player);
	}

	for(auto &object : m_objects) updateObject(object);
}

void Scene::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	if (player) {
		drawObject(*player, target, states);
	}

	for(const auto &object : m_objects) drawObject(object, target, states);
}

void Scene::resetObject(SceneObject &object) {
	if(m_resetHandler) m_resetHandler(object);
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

	if(m_updateHandler) m_updateHandler(object);
}

void Scene::drawObject(const SceneObject &object, gk::RenderTarget &target, gk::RenderStates states) const {
	if(object.has<SceneObjectList>()) {
		const SceneObjectList &objects = object.get<SceneObjectList>();
		for(auto &object : objects) {
			DrawingSystem::draw(object, target, states);
		}
	}

	DrawingSystem::draw(object, target, states);

	if(m_drawHandler) m_drawHandler(object, target, states);
}

