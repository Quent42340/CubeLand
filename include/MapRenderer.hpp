/*
 * =====================================================================================
 *
 *       Filename:  MapRenderer.hpp
 *
 *    Description:  
 *
 *        Created:  14/08/2015 15:47:57
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPRENDERER_HPP_
#define MAPRENDERER_HPP_

#include "Sprite.hpp"

class MapRenderer : public sf::Drawable {
	public:
		MapRenderer() = default;
		virtual ~MapRenderer() = default;
		
		void init(u16 mapWidth, u16 mapHeight, Sprite &tileset);
		
		void updateTile(u16 tileX, u16 tileY, u16 id);
		
		const Sprite &tileset() const { return *m_tileset; }
		
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		
		u16 m_mapWidth;
		u16 m_mapHeight;
		
		Sprite *m_tileset = nullptr;
		
		sf::VertexArray m_vertices;
};

#endif // MAPRENDERER_HPP_
