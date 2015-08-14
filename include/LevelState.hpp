/*
 * =====================================================================================
 *
 *       Filename:  LevelState.hpp
 *
 *    Description:  
 *
 *        Created:  14/08/2015 18:03:09
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LEVELSTATE_HPP_
#define LEVELSTATE_HPP_

#include "Application.hpp"
#include "ApplicationState.hpp"
#include "Map.hpp"
#include "Sprite.hpp"
#include "Player.hpp"

class LevelState : public ApplicationState {
	public:
		LevelState();
		
		void update();
		
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		
		Sprite m_tileset{"graphics/tileset.png", 16, 16};
		Map m_map{"data/maps/level0.tmx", m_tileset};
		
		Player m_player;
		
		sf::View m_view{sf::FloatRect(0, 0, Application::screenWidth, Application::screenHeight)};
};

#endif // LEVELSTATE_HPP_
