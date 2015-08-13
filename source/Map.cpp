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

Map::Map(const char *filename, Sprite &tileset) : m_tileset(tileset) {
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
	
	m_vertices.setPrimitiveType(sf::Triangles);
	m_vertices.resize(m_width * m_height * 6);
	
	for(u16 tileY = 0 ; tileY < m_height ; tileY++) {
		for(u16 tileX = 0 ; tileX < m_width ; tileX++) {
			updateTile(tileX, tileY);
		}
	}
}

void Map::updateTile(u16 tileX, u16 tileY) {
	s16 tileNb = getTile(tileX, tileY);
	
	if(tileNb == -1) return;
	
	u16 tilesetX = tileNb % (m_tileset.width() / m_tileWidth);
	u16 tilesetY = tileNb / (m_tileset.width() / m_tileWidth);
	
	sf::Vertex *triangle = &m_vertices[(tileX + tileY * m_width) * 6];
	
	triangle[0].position = sf::Vector2f(tileX * m_tileWidth, tileY * m_tileHeight);
	triangle[1].position = sf::Vector2f((tileX + 1) * m_tileWidth, tileY * m_tileHeight);
	triangle[2].position = sf::Vector2f(tileX * m_tileWidth, (tileY + 1) * m_tileHeight);
	triangle[3].position = triangle[1].position;
	triangle[4].position = triangle[2].position;
	triangle[5].position = sf::Vector2f((tileX + 1) * m_tileWidth, (tileY + 1) * m_tileHeight);
	
	triangle[0].texCoords = sf::Vector2f(tilesetX * m_tileWidth, tilesetY * m_tileHeight);
	triangle[1].texCoords = sf::Vector2f((tilesetX + 1) * m_tileWidth, tilesetY * m_tileHeight);
	triangle[2].texCoords = sf::Vector2f(tilesetX * m_tileWidth, (tilesetY + 1) * m_tileHeight);
	triangle[3].texCoords = triangle[1].texCoords;
	triangle[4].texCoords = triangle[2].texCoords;
	triangle[5].texCoords = sf::Vector2f((tilesetX + 1) * m_tileWidth, (tilesetY + 1) * m_tileHeight);
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
		
		updateTile(tileX, tileY);
	}
}

bool Map::isPassable(float x, float y) {
	return getTile(x / m_tileWidth, y / m_tileHeight) != 1;
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	states.texture = &m_tileset.texture();
	
	target.draw(m_vertices, states);
}

