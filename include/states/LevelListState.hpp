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

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "ApplicationState.hpp"
#include "IntTypes.hpp"

class LevelListState : public ApplicationState {
	public:
		LevelListState();
		
		void update();
		
		void drawLevel(u16 id, sf::RenderTarget &target, sf::RenderStates states) const;
		
	private:
		sf::Font m_font;
		
		sf::Text m_title{"Choose a level", m_font, 80};
		
		sf::RectangleShape m_rectangle{sf::Vector2f(580, 350)};
		
		sf::RectangleShape m_cursor{sf::Vector2f(125, 40)};
		u16 m_cursorPosition = 0;
		
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // LEVELLISTSTATE_HPP_
