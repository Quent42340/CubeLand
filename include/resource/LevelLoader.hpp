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

#include <gk/core/IntTypes.hpp>
#include <gk/resource/IResourceLoader.hpp>

class Tileset;

class LevelLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler);

		void loadLevel(u16 id, Tileset &tileset, gk::ResourceHandler &handler);

		static u16 levelsLoaded;
};

#endif // LEVELLOADER_HPP_
