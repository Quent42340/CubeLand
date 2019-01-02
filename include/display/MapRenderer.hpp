/*
 * =====================================================================================
 *
 *       Filename:  MapRenderer.hpp
 *
 *    Description:
 *
 *        Created:  14/08/2015 15:47:57
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPRENDERER_HPP_
#define MAPRENDERER_HPP_

#include <gk/gl/IDrawable.hpp>
#include <gk/gl/VertexBuffer.hpp>

#include "Tileset.hpp"

class MapRenderer : public gk::IDrawable {
	public:
		MapRenderer() = default;

		void init(u16 mapWidth, u16 mapHeight, Tileset &tileset);

		void updateTile(u16 tileX, u16 tileY, u16 id);

		const Tileset &tileset() const { return *m_tileset; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		u16 m_mapWidth;
		u16 m_mapHeight;

		Tileset *m_tileset = nullptr;

		gk::VertexBuffer m_vbo;
};

#endif // MAPRENDERER_HPP_
