/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:
 *
 *        Created:  12/08/2015 20:18:39
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Map.hpp"

Map *Map::currentMap = nullptr;

Map::Map(u16 width, u16 height, gk::Tileset &tileset, const std::vector<u16> &tiles)
	: gk::Tilemap(width, height, tileset, {tiles})
{
}

bool Map::inTile(float x, float y, u16 tile) {
	return getTile(x / m_tileset.tileWidth(),
	               y / m_tileset.tileHeight()) == tile;
}

bool Map::isPassable(float x, float y) {
	return !inTile(x, y, 1);
}

