/*
 * =====================================================================================
 *
 *       Filename:  Scene.hpp
 *
 *    Description:
 *
 *        Created:  07/05/2015 17:05:23
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <gk/gl/IDrawable.hpp>

#include "SceneObject.hpp"
#include "SceneObjectList.hpp"

class Scene : public gk::IDrawable {
		using SceneHandler = std::function<void(SceneObject &)>;
		using SceneDrawHandler = std::function<void(const SceneObject &, gk::RenderTarget &, gk::RenderStates states)>;

	public:
		SceneObject &addObject(SceneObject &&object);

		void reset();
		void update();

		SceneObjectList &objects() { return m_objects; }

		void setResetHandler(const SceneHandler &resetHandler) { m_resetHandler = resetHandler; }
		void setUpdateHandler(const SceneHandler &updateHandler) { m_updateHandler = updateHandler; }
		void setDrawHandler(const SceneDrawHandler &drawHandler) { m_drawHandler = drawHandler; }

		static bool isPlayer(const SceneObject &object) { return player == &object; }

		static Scene *currentScene;

		static SceneObject *player;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		void resetObject(SceneObject &object);
		void updateObject(SceneObject &object);
		void drawObject(const SceneObject &object, gk::RenderTarget &target, gk::RenderStates states) const;

		SceneHandler m_resetHandler;
		SceneHandler m_updateHandler;
		SceneDrawHandler m_drawHandler;

		SceneObjectList m_objects;
};

#endif // SCENE_HPP_
