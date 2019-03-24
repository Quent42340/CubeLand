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

#include "Button.hpp"

class LevelEndState : public gk::ApplicationState {
	public:
		LevelEndState(gk::ApplicationState *parent, bool isLevelPassed);

		void onEvent(const sf::Event &event) override;

		void update() override;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		Button m_okButton{"Back to level list", 40};

		bool m_isLevelPassed;

		sf::RectangleShape m_rect;

		sf::Text m_text; //{"font-default", 80};
};

#endif // LEVELENDSTATE_HPP_
