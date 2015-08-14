/*
 * =====================================================================================
 *
 *       Filename:  Sprite.hpp
 *
 *    Description:  
 *
 *        Created:  13/08/2015 02:16:43
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Sprite.hpp"

void Sprite::setCurrentFrame(u16 currentFrame) {
	u16 frameX = currentFrame % (width() / m_frameWidth);
	u16 frameY = currentFrame / (width() / m_frameWidth);
	
	setClipRect(frameX, frameY, m_frameWidth, m_frameHeight);
}

void Sprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(*this, states);
}

