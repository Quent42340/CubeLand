/*
 * =====================================================================================
 *
 *       Filename:  Sprite.hpp
 *
 *    Description:  
 *
 *        Created:  13/08/2015 02:13:18
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "Image.hpp"

class Sprite : public Image {
	public:
		Sprite(const char *filename, u16 frameWidth, u16 frameHeight)
			: Image(filename), m_frameWidth(frameWidth), m_frameHeight(frameHeight) {}
		
		void setCurrentFrame(u16 currentFrame);
		
		u16 frameWidth() const { return m_frameWidth; }
		u16 frameHeight() const { return m_frameHeight; }
		
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		
		u16 m_frameWidth;
		u16 m_frameHeight;
		
		u16 m_currentFrame = 0;
};

#endif // SPRITE_HPP_
