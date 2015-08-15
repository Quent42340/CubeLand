/*
 * =====================================================================================
 *
 *       Filename:  Image.hpp
 *
 *    Description:  
 *
 *        Created:  20/09/2014 16:21:56
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <SFML/Graphics.hpp>

#include "IntTypes.hpp"

class Image : public sf::Drawable, public sf::Transformable {
	public:
		Image() = default;
		Image(const char *textureName);
		
		void setClipRect(float x, float y, u16 width, u16 height);
		void setPosRect(float x, float y, u16 width, u16 height);
		
		u16 width() const { return m_texture.getSize().x; }
		u16 height() const { return m_texture.getSize().y; }
		
		const sf::Texture &texture() const { return m_texture; }
		
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		
		sf::Texture &m_texture;
		
		sf::Sprite m_sprite;
};

#endif // IMAGE_HPP_
