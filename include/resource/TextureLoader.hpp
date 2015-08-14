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

#include "ResourceLoader.hpp"

class TextureLoader : public ResourceLoader {
	public:
		void load(const char *xmlFilename, ResourceHandler &handler);
};

#endif // TEXTURELOADER_HPP_
