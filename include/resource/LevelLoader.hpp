/*
 * =====================================================================================
 *
 *       Filename:  LevelLoader.hpp
 *
 *    Description:  
 *
 *        Created:  12/01/2015 15:04:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LEVELLOADER_HPP_
#define LEVELLOADER_HPP_

#include "ResourceLoader.hpp"
#include "Tileset.hpp"

class LevelLoader : public ResourceLoader {
	public:
		void load(const char *xmlFilename, ResourceHandler &handler);
		
		void loadLevel(u16 id, Tileset &tileset, ResourceHandler &handler);
};

#endif // LEVELLOADER_HPP_
