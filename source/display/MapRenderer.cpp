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

void MapRenderer::init(u16 mapWidth, u16 mapHeight, Sprite &tileset) {
	m_mapWidth = mapWidth;
	m_mapHeight = mapHeight;
	
	m_tileset = &tileset;
	
	m_vertices.setPrimitiveType(sf::Triangles);
	m_vertices.resize(m_mapWidth * m_mapHeight * 6);
}

void MapRenderer::updateTile(u16 tileX, u16 tileY, u16 id) {
	u16 tilesetX = id % (m_tileset->width() / m_tileset->frameWidth());
	u16 tilesetY = id / (m_tileset->width() / m_tileset->frameWidth());
	
	sf::Vertex *triangle = &m_vertices[(tileX + tileY * m_mapWidth) * 6];
	
	triangle[0].position = sf::Vector2f(tileX * m_tileset->frameWidth(), tileY * m_tileset->frameHeight());
	triangle[1].position = sf::Vector2f((tileX + 1) * m_tileset->frameWidth(), tileY * m_tileset->frameHeight());
	triangle[2].position = sf::Vector2f(tileX * m_tileset->frameWidth(), (tileY + 1) * m_tileset->frameHeight());
	triangle[3].position = triangle[1].position;
	triangle[4].position = triangle[2].position;
	triangle[5].position = sf::Vector2f((tileX + 1) * m_tileset->frameWidth(), (tileY + 1) * m_tileset->frameHeight());
	
	triangle[0].texCoords = sf::Vector2f(tilesetX * m_tileset->frameWidth(), tilesetY * m_tileset->frameHeight());
	triangle[1].texCoords = sf::Vector2f((tilesetX + 1) * m_tileset->frameWidth(), tilesetY * m_tileset->frameHeight());
	triangle[2].texCoords = sf::Vector2f(tilesetX * m_tileset->frameWidth(), (tilesetY + 1) * m_tileset->frameHeight());
	triangle[3].texCoords = triangle[1].texCoords;
	triangle[4].texCoords = triangle[2].texCoords;
	triangle[5].texCoords = sf::Vector2f((tilesetX + 1) * m_tileset->frameWidth(), (tilesetY + 1) * m_tileset->frameHeight());
}

void MapRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.texture = &m_tileset->texture();
	
	target.draw(m_vertices, states);
}

