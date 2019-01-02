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

#include <gk/core/ApplicationState.hpp>
#include <gk/gl/View.hpp>

#include "SceneObject.hpp"

class LevelState : public gk::ApplicationState {
	public:
		LevelState(u16 levelID);

		void update() override;

		static gk::View view;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		u16 m_levelID = 0;

		SceneObject m_player;
};

#endif // LEVELSTATE_HPP_
