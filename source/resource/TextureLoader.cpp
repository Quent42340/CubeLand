/*
 * =====================================================================================
 *
 *       Filename:  TextureLoader.cpp
 *
 *    Description:
 *
 *        Created:  14/01/2015 20:29:21
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/XMLFile.hpp>
#include <gk/gl/Texture.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "TextureLoader.hpp"

void TextureLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *textureElement = doc.FirstChildElement("textures").FirstChildElement("texture").ToElement();
	while(textureElement) {
		std::string folder = textureElement->Attribute("folder");
		std::string name = textureElement->Attribute("name");

		gk::Texture &texture = handler.add<gk::Texture>(folder + "-" + name);
		texture.loadFromFile("resources/graphics/" + folder + "/" + name + ".png");

		textureElement = textureElement->NextSiblingElement("texture");
	}
}

