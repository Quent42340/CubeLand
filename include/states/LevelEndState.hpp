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

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "ApplicationState.hpp"
#include "Button.hpp"

class LevelEndState : public ApplicationState {
	public:
		LevelEndState(ApplicationState *parent, bool isLevelPassed);
		
		void update();
		
	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		
		Button m_okButton{"Back to level list", 40};
		
		bool m_isLevelPassed;
		
		sf::RectangleShape m_rect;
		
		sf::Text m_text;
};

#endif // LEVELENDSTATE_HPP_
