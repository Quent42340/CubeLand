/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.hpp
 *
 *    Description:
 *
 *        Created:  12/01/2015 16:32:10
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILESETLOADER_HPP_
#define TILESETLOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class TilesetLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler);
};

#endif // TILESETLOADER_HPP_
