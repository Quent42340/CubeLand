/*
 * =====================================================================================
 *
 *       Filename:  LevelState.cpp
 *
 *    Description:  
 *
 *        Created:  14/08/2015 18:03:42
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "LevelState.hpp"
#include "ResourceHandler.hpp"

LevelState::LevelState() {
	Map::currentMap = &ResourceHandler::getInstance().get<Map>("level0");
}

void LevelState::update() {
	m_player.update();
	
	// FIXME: À ne faire que si le player dépasse la moitié de l'écran, et à ne pas faire en bord de map
	sf::Vector2f playerCenter = m_player.getPosition() + sf::Vector2f(m_player.width(), m_player.height()) / 2.0f;
	m_view.setCenter(floor(playerCenter.x), floor(playerCenter.y));
}

void LevelState::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.setView(m_view);
	
	target.draw(*Map::currentMap, states);
	
	target.draw(m_player, states);
	
	target.setView(target.getDefaultView());
}

