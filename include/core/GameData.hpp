/*
 * =====================================================================================
 *
 *       Filename:  GameData.hpp
 *
 *    Description:
 *
 *        Created:  08/04/2019 20:36:40
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_

namespace gk {
	class Tilemap;
}

class GameData {
	public:
		static gk::Tilemap *currentMap;
};

#endif // GAMEDATA_HPP_
