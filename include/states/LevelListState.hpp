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

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include <gk/core/ApplicationState.hpp>
#include <gk/core/IntTypes.hpp>

class LevelListState : public gk::ApplicationState {
	public:
		LevelListState();

		void onEvent(const sf::Event &event) override;

		void update() override;

		void drawLevel(u16 id, gk::RenderTarget &target, gk::RenderStates states) const;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		sf::Text m_title;

		sf::RectangleShape m_rectangle{{580, 350}};

		sf::RectangleShape m_cursor{{125, 40}};
		u16 m_cursorPosition = 0;
};

#endif // LEVELLISTSTATE_HPP_
