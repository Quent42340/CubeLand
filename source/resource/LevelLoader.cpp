/*
 * =====================================================================================
 *
 *       Filename:  LevelLoader.cpp
 *
 *    Description:  
 *
 *        Created:  12/01/2015 15:05:28
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Level.hpp"
#include "LevelLoader.hpp"
#include "SceneObjectLoader.hpp"

void LevelLoader::load(const char *xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);
	
	XMLElement *levelElement = doc.FirstChildElement("levels").FirstChildElement("level").ToElement();
	while(levelElement) {
		u16 id = levelElement->IntAttribute("id");
		
		std::string tilesetName = levelElement->Attribute("tileset");
		
		Sprite &tileset = handler.get<Sprite>(tilesetName);
		
		loadLevel(name, tileset, handler);
		
		levelElement = levelElement->NextSiblingElement("level");
	}
}

void LevelLoader::loadLevel(u16 id, Sprite &tileset, ResourceHandler &handler) {
	XMLFile doc("data/maps/level" + std::to_string(id) + ".tmx");
	
	XMLElement *mapElement = doc.FirstChildElement("map").ToElement();
	
	u16 width = mapElement->IntAttribute("width");
	u16 height = mapElement->IntAttribute("height");
	
	std::vector<u16> tiles;
	XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		s16 tileID = tileElement->IntAttribute("gid") - 1;
		
		tiles.push_back((tileID >= 0) ? tileID : 0);
		
		tileElement = tileElement->NextSiblingElement("tile");
	}
	
	Map &level = handler.add<Map>("level" + std::to_string(id), width, height, tileset, tiles);
}

