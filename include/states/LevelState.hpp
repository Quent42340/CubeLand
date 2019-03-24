/*
 * =====================================================================================
 *
 *       Filename:  LevelState.hpp
 *
 *    Description:
 *
 *        Created:  14/08/2015 18:03:09
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LEVELSTATE_HPP_
#define LEVELSTATE_HPP_

#include <SFML/Graphics/View.hpp>

#include <gk/core/ApplicationState.hpp>
#include <gk/scene/Scene.hpp>

class LevelState : public gk::ApplicationState {
	public:
		LevelState(u16 levelID);

		void update() override;

		static sf::View view;

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		u16 m_levelID = 0;

		gk::SceneObject m_player;

		gk::Scene *m_scene = nullptr;
};

#endif // LEVELSTATE_HPP_
