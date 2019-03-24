/*
 * =====================================================================================
 *
 *       Filename:  TitleScreenState.hpp
 *
 *    Description:
 *
 *        Created:  19/08/2015 19:07:58
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TITLESCREENSTATE_HPP_
#define TITLESCREENSTATE_HPP_

#include <gk/core/ApplicationState.hpp>
#include <gk/graphics/Image.hpp>

#include "Button.hpp"

class TitleScreenState : public gk::ApplicationState {
	public:
		TitleScreenState();

		void onEvent(const sf::Event &event) override;

		void update() override;

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		sf::Text m_title;

		Button m_playButton{"Play", 48};
};

#endif // TITLESCREENSTATE_HPP_
