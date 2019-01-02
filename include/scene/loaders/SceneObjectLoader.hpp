/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectLoader.hpp
 *
 *    Description:
 *
 *        Created:  06/09/2015 18:42:59
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECTLOADER_HPP_
#define SCENEOBJECTLOADER_HPP_

#include <gk/scene/Scene.hpp>

class SceneObjectLoader {
	public:
		static void loadObjectsFromLevelID(gk::Scene &scene, u16 levelID);

		static void loadObjectFromTile(gk::Scene &scene, u16 tileX, u16 tileY, u16 tileID);
};

#endif // SCENEOBJECTLOADER_HPP_
