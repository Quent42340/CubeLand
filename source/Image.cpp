/*
 * =====================================================================================
 *
 *       Filename:  Image.cpp
 *
 *    Description:  
 *
 *        Created:  20/09/2014 16:22:12
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Image.hpp"

Image::Image(const char *textureName) {
	load(textureName);
}

void Image::load(const char *textureName) {
	m_texture.loadFromFile(textureName);
	
	m_sprite.setTexture(m_texture, true);
}

void Image::setClipRect(float x, float y, u16 width, u16 height) {
	m_sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void Image::setPosRect(float x, float y, u16 width, u16 height) {
	m_sprite.setPosition(x, y);
	
	m_sprite.setScale(this->width() / width, this->height() / height);
}

void Image::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(m_sprite, states);
}

