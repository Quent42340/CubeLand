/*
 * =====================================================================================
 *
 *       Filename:  Tileset.hpp
 *
 *    Description:
 *
 *        Created:  15/08/2015 20:42:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILESET_HPP_
#define TILESET_HPP_

#include <SFML/Graphics/Texture.hpp>

#include <gk/core/IntTypes.hpp>

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
