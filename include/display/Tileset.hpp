/*
 * =====================================================================================
 *
 *       Filename:  Tileset.hpp
 *
 *    Description:  
 *
 *        Created:  15/08/2015 20:42:20
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILESET_HPP_
#define TILESET_HPP_

#include <SFML/Graphics/Texture.hpp>

#include "IntTypes.hpp"

class Tileset : public sf::Texture {
	public:
		Tileset(const std::string &filename, u16 tileWidth, u16 tileHeight);
		
		u16 tileWidth() const { return m_tileWidth; }
		u16 tileHeight() const { return m_tileHeight; }
		
	private:
		u16 m_tileWidth;
		u16 m_tileHeight;
};

#endif // TILESET_HPP_
