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

#include "ApplicationState.hpp"
#include "Image.hpp"

class TitleScreenState : public ApplicationState {
	public:
		TitleScreenState();
		
		void update();
		
	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		
		sf::Font m_font;
		
		sf::Text m_title{"CubeLand", m_font, 128};
		
		sf::Text m_playText{"Play", m_font, 48};
		sf::RectangleShape m_playRect;
};

#endif // TITLESCREENSTATE_HPP_
