/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:
 *
 *        Created:  12/08/2015 20:18:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

#include <gk/graphics/Tilemap.hpp>

class Map : public gk::Tilemap {
	public:
		Map(u16 width, u16 height, gk::Tileset &tileset, const std::vector<u16> &tiles);

		bool inTile(float x, float y, u16 tile);
		bool isPassable(float x, float y);

		static Map *currentMap;
};

#endif // MAP_HPP_
