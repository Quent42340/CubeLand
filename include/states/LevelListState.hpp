/*
 * =====================================================================================
 *
 *       Filename:  LevelListState.hpp
 *
 *    Description:
 *
 *        Created:  19/08/2015 21:30:18
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LEVELLISTSTATE_HPP_
#define LEVELLISTSTATE_HPP_

#include <gk/core/ApplicationState.hpp>
#include <gk/core/IntTypes.hpp>
#include <gk/graphics/Font.hpp>
#include <gk/graphics/RectangleShape.hpp>
#include <gk/graphics/Text.hpp>

class LevelListState : public gk::ApplicationState {
	public:
		LevelListState();

		void onEvent(const SDL_Event &event) override;

		void update() override;

		void drawLevel(u16 id, gk::RenderTarget &target, gk::RenderStates states) const;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		gk::Font m_font{"resources/fonts/terminus.ttf"};

		gk::Text m_title{"Choose a level", m_font, 80};

		gk::RectangleShape m_rectangle{580, 350};

		gk::RectangleShape m_cursor{125, 40};
		u16 m_cursorPosition = 0;
};

#endif // LEVELLISTSTATE_HPP_
