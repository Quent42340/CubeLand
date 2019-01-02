/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.cpp
 *
 *    Description:
 *
 *        Created:  12/01/2015 16:32:29
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/XMLFile.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "Tileset.hpp"
#include "TilesetLoader.hpp"

void TilesetLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *tilesetElement = doc.FirstChildElement("tilesets").FirstChildElement("tileset").ToElement();
	while(tilesetElement) {
		std::string name = tilesetElement->Attribute("name");
		std::string filename = "resources/graphics/tilesets/" + name + ".png";

		u16 tileWidth = tilesetElement->IntAttribute("tileWidth");
		u16 tileHeight = tilesetElement->IntAttribute("tileHeight");

		handler.add<Tileset>(name, filename, tileWidth, tileHeight);

		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}

