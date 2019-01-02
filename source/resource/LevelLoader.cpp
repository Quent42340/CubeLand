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
#include <gk/core/XMLFile.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "LevelLoader.hpp"
#include "Map.hpp"
#include "Scene.hpp"
#include "SceneObjectLoader.hpp"

u16 LevelLoader::levelsLoaded = 0;

void LevelLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *levelElement = doc.FirstChildElement("levels").FirstChildElement("level").ToElement();
	while(levelElement) {
		u16 id = levelElement->IntAttribute("id");

		Tileset &tileset = handler.get<Tileset>(levelElement->Attribute("tileset"));

		loadLevel(id, tileset, handler);

		levelsLoaded++;

		levelElement = levelElement->NextSiblingElement("level");
	}
}

void LevelLoader::loadLevel(u16 id, Tileset &tileset, gk::ResourceHandler &handler) {
	gk::XMLFile doc("resources/maps/level" + std::to_string(id) + ".tmx");

	tinyxml2::XMLElement *mapElement = doc.FirstChildElement("map").ToElement();

	u16 width = mapElement->IntAttribute("width");
	u16 height = mapElement->IntAttribute("height");

	Scene &scene = handler.add<Scene>("level" + std::to_string(id) + "-scene");

	SceneObjectLoader::loadObjectsFromLevelID(scene, id);

	std::vector<u16> tiles;
	tinyxml2::XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		u16 tileX = tiles.size() % width;
		u16 tileY = tiles.size() / width;

		s16 tileID = tileElement->IntAttribute("gid") - 1;

		tileID = (tileID >= 0) ? tileID : 0;

		tiles.push_back(tileID);

		SceneObjectLoader::loadObjectFromTile(scene, tileX, tileY, tileID);

		tileElement = tileElement->NextSiblingElement("tile");
	}

	handler.add<Map>("level" + std::to_string(id), width, height, tileset, tiles);
}

