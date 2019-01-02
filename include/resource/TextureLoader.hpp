/*
 * =====================================================================================
 *
 *       Filename:  TextureLoader.hpp
 *
 *    Description:
 *
 *        Created:  14/01/2015 20:27:14
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TEXTURELOADER_HPP_
#define TEXTURELOADER_HPP_

#include <gk/resource/IResourceLoader.hpp>

class TextureLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler);
};

#endif // TEXTURELOADER_HPP_
