/*
 * =====================================================================================
 *
 *       Filename:  LevelEndState.hpp
 *
 *    Description:
 *
 *        Created:  29/08/2015 18:18:19
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LEVELENDSTATE_HPP_
#define LEVELENDSTATE_HPP_

#include <gk/core/ApplicationState.hpp>
#include <gk/gui/RectangleShape.hpp>
#include <gk/gui/Text.hpp>

#include "Button.hpp"

class LevelEndState : public gk::ApplicationState {
	public:
		LevelEndState(gk::ApplicationState *parent, bool isLevelPassed);

		void onEvent(const SDL_Event &event) override;

		void update() override;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		Button m_okButton{"Back to level list", 40};

		bool m_isLevelPassed;

		gk::RectangleShape m_rect;

		gk::Text m_text;
};

#endif // LEVELENDSTATE_HPP_
