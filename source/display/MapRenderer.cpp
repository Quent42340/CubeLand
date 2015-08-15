/*
 * =====================================================================================
 *
 *       Filename:  MapRenderer.cpp
 *
 *    Description:  
 *
 *        Created:  14/08/2015 15:48:30
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "MapRenderer.hpp"

void MapRenderer::init(u16 mapWidth, u16 mapHeight, Tileset &tileset) {
	m_mapWidth = mapWidth;
	m_mapHeight = mapHeight;
	
	m_tileset = &tileset;
	
	m_vertices.setPrimitiveType(sf::Triangles);
	m_vertices.resize(m_mapWidth * m_mapHeight * 6);
}

void MapRenderer::updateTile(u16 tileX, u16 tileY, u16 id) {
	u16 tilesetX = id % (m_tileset->getSize().x / m_tileset->tileWidth());
	u16 tilesetY = id / (m_tileset->getSize().x / m_tileset->tileWidth());
	
	sf::Vertex *triangle = &m_vertices[(tileX + tileY * m_mapWidth) * 6];
	
	triangle[0].position = sf::Vector2f(tileX * m_tileset->tileWidth(), tileY * m_tileset->tileHeight());
	triangle[1].position = sf::Vector2f((tileX + 1) * m_tileset->tileWidth(), tileY * m_tileset->tileHeight());
	triangle[2].position = sf::Vector2f(tileX * m_tileset->tileWidth(), (tileY + 1) * m_tileset->tileHeight());
	triangle[3].position = triangle[1].position;
	triangle[4].position = triangle[2].position;
	triangle[5].position = sf::Vector2f((tileX + 1) * m_tileset->tileWidth(), (tileY + 1) * m_tileset->tileHeight());
	
	triangle[0].texCoords = sf::Vector2f(tilesetX * m_tileset->tileWidth(), tilesetY * m_tileset->tileHeight());
	triangle[1].texCoords = sf::Vector2f((tilesetX + 1) * m_tileset->tileWidth(), tilesetY * m_tileset->tileHeight());
	triangle[2].texCoords = sf::Vector2f(tilesetX * m_tileset->tileWidth(), (tilesetY + 1) * m_tileset->tileHeight());
	triangle[3].texCoords = triangle[1].texCoords;
	triangle[4].texCoords = triangle[2].texCoords;
	triangle[5].texCoords = sf::Vector2f((tilesetX + 1) * m_tileset->tileWidth(), (tilesetY + 1) * m_tileset->tileHeight());
}

void MapRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.texture = m_tileset;
	
	target.draw(m_vertices, states);
}

