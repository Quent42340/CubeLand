/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectLoader.cpp
 *
 *    Description:
 *
 *        Created:  06/09/2015 18:46:44
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Filesystem.hpp"
#include "SceneObjectLoader.hpp"
#include "XMLFile.hpp"

#include "SpikeFactory.hpp"

void SceneObjectLoader::loadObjectsFromLevelID(Scene &scene, u16 levelID) {
	if(Filesystem::fileExists("data/config/levels/level" + std::to_string(levelID) + ".xml")) {
		XMLFile doc("data/config/levels/level" + std::to_string(levelID) + ".xml");

		XMLElement *objectElement = doc.FirstChildElement("level").FirstChildElement().ToElement();
		while(objectElement) {
			std::string objectName = objectElement->Name();

			// Put here object loading

			objectElement = objectElement->NextSiblingElement();
		}
	}
}

void SceneObjectLoader::loadObjectFromTile(Scene &scene, u16 tileX, u16 tileY, u16 tileID) {
	switch(tileID) {
		case 2: scene.addObject(SpikeFactory::create(tileX, tileY)); break;
	}
}

