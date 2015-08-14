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

Map::Map(const char *filename, Sprite &tileset) {
	XMLFile doc(filename);
	
	XMLElement *mapElement = doc.FirstChildElement("map").ToElement();
	
	m_width = mapElement->IntAttribute("width");
	m_height = mapElement->IntAttribute("height");
	
	XMLElement *tilesetElement = mapElement->FirstChildElement("tileset");
	
	m_tileWidth = tilesetElement->IntAttribute("tilewidth");
	m_tileHeight = tilesetElement->IntAttribute("tileheight");
	
	XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		m_tiles.push_back(tileElement->IntAttribute("gid") - 1);
		
		tileElement = tileElement->NextSiblingElement("tile");
	}
	
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

