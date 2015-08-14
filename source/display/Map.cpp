/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:  
 *
 *        Created:  12/08/2015 20:18:39
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "Map.hpp"
#include "XMLFile.hpp"

Map *Map::currentMap = nullptr;

Map::Map(u16 width, u16 height, Sprite &tileset, const std::vector<u16> &tiles) {
	m_width = width;
	m_height = height;
	
	m_tileWidth = tileset.frameWidth();
	m_tileHeight = tileset.frameHeight();
	
	m_tiles = tiles;
	
	m_renderer.init(m_width, m_height, tileset);
	
	for(u16 tileY = 0 ; tileY < m_height ; tileY++) {
		for(u16 tileX = 0 ; tileX < m_width ; tileX++) {
			m_renderer.updateTile(tileX, tileY, getTile(tileX, tileY));
		}
	}
}

u16 Map::getTile(u16 tileX, u16 tileY) {
	if(tileX + tileY * m_width < m_width * m_height) {
		return m_tiles[tileX + tileY * m_width];
	} else {
		return 0;
	}
}

void Map::setTile(u16 tileX, u16 tileY, u16 tile) {
	if(tileX + tileY * m_width >= m_width * m_height) {
		throw EXCEPTION("Tile coordinates out of map");
	}
	else if(tile != getTile(tileX, tileY)) {
		m_tiles[tileX + tileY * m_width] = tile;
		
		m_renderer.updateTile(tileX, tileY, tile);
	}
}

bool Map::inTile(float x, float y, u16 tile) {
	return getTile(x / m_tileWidth, y / m_tileHeight) == tile;
}

bool Map::isPassable(float x, float y) {
	return !inTile(x, y, 1);
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(m_renderer, states);
}

