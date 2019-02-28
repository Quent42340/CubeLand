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

		void onEvent(const SDL_Event &event) override;

		void update() override;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		gk::Text m_title{"CubeLand", "font-default", 128};

		Button m_playButton{"Play", 48};
};

#endif // TITLESCREENSTATE_HPP_
