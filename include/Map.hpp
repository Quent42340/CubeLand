/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:  
 *
 *        Created:  12/08/2015 20:18:15
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>

#include "Sprite.hpp"

class Map : public sf::Drawable, public sf::Transformable {
	public:
		Map(const char *filename, Sprite &tileset);
		
		void updateTile(u16 tileX, u16 tileY);
		void updateTiles();
		
		u16 getTile(u16 tileX, u16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 tile);
		
		bool isPassable(float x, float y);
		
		static Map *currentMap;
		
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		
		Sprite &m_tileset;
		
		u16 m_width;
		u16 m_height;
		
		u8 m_tileWidth;
		u8 m_tileHeight;
		
		std::vector<u8> m_tiles;
		
		sf::VertexArray m_vertices;
};

#endif // MAP_HPP_
