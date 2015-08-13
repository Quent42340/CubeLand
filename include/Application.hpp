/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:  
 *
 *        Created:  12/08/2015 19:43:33
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <SFML/Graphics.hpp>

#include "GameClock.hpp"
#include "Player.hpp"

class Application {
	public:
		Application();
		
		void run();
		
		static bool quit;
		
		const static u16 screenWidth = 640;
		const static u16 screenHeight = 480;
		
	private:
		sf::RenderWindow m_window;
		
		GameClock m_clock;
		
		Player m_player;
};

#endif // APPLICATION_HPP_
