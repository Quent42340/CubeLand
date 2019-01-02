/*
 * =====================================================================================
 *
 *       Filename:  Tileset.cpp
 *
 *    Description:
 *
 *        Created:  15/08/2015 20:51:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Tileset.hpp"

Tileset::Tileset(const std::string &filename, u16 tileWidth, u16 tileHeight) {
	loadFromFile(filename);

	m_tileWidth = tileWidth;
	m_tileHeight = tileHeight;
}

