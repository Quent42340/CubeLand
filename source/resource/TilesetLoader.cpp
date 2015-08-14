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
#include "Sprite.hpp"
#include "TilesetLoader.hpp"
#include "XMLFile.hpp"

void TilesetLoader::load(const char *xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);
	
	XMLElement *tilesetElement = doc.FirstChildElement("tilesets").FirstChildElement("tileset").ToElement();
	while(tilesetElement) {
		std::string name = tilesetElement->Attribute("name");
		std::string filename = "graphics/tilesets/" + name + ".png";
		
		//std::string configFile = "data/tilesets/" + name + ".xml";
		
		u16 tileWidth = tilesetElement->IntAttribute("tileWidth");
		u16 tileHeight = tilesetElement->IntAttribute("tileHeight");
		
		handler.add<Sprite>(name, filename, tileWidth, tileHeight);
		
		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}
