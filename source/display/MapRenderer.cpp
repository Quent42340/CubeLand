/*
 * =====================================================================================
 *
 *       Filename:  MapRenderer.cpp
 *
 *    Description:
 *
 *        Created:  14/08/2015 15:48:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/gl/Vertex.hpp>

#include "MapRenderer.hpp"

void MapRenderer::init(u16 mapWidth, u16 mapHeight, Tileset &tileset) {
	m_mapWidth = mapWidth;
	m_mapHeight = mapHeight;

	m_tileset = &tileset;

	gk::VertexBuffer::bind(&m_vbo);
	m_vbo.setData(sizeof(gk::Vertex) * mapWidth * mapHeight * 6, nullptr, GL_DYNAMIC_DRAW);
	gk::VertexBuffer::bind(nullptr);
}

void MapRenderer::updateTile(u16 tileX, u16 tileY, u16 id) {
	if (!m_tileset) return;

	gk::VertexBuffer::bind(&m_vbo);

	float tileWidth  = m_tileset->tileWidth();
	float tileHeight = m_tileset->tileHeight();

	float x = tileX * tileWidth;
	float y = tileY * tileHeight;

	float texTileX = id % u16(m_tileset->width() / tileWidth) * tileWidth  / m_tileset->width();
	float texTileY = id / u16(m_tileset->width() / tileWidth) * tileHeight / m_tileset->height();

	float texTileWidth  = tileWidth  / m_tileset->width();
	float texTileHeight = tileHeight / m_tileset->height();

	gk::Vertex vertices[] = {
		{{x            , y             , 0, 1}, {texTileX               , texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y             , 0, 1}, {texTileX + texTileWidth, texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight, 0, 1}, {texTileX + texTileWidth, texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y             , 0, 1}, {texTileX               , texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight, 0, 1}, {texTileX + texTileWidth, texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y + tileHeight, 0, 1}, {texTileX               , texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}}
	};

	m_vbo.updateData(sizeof(vertices) * (tileX + tileY * m_mapWidth), sizeof(vertices), vertices);

	gk::VertexBuffer::bind(nullptr);
}

void MapRenderer::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	states.texture = m_tileset;

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);

	target.draw(m_vbo, GL_TRIANGLES, 0, 6 * m_mapWidth * m_mapHeight, states);
}


