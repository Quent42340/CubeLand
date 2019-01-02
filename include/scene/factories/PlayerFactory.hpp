/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.hpp
 *
 *    Description:
 *
 *        Created:  19/08/2015 15:35:58
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERFACTORY_HPP_
#define PLAYERFACTORY_HPP_

#include <gk/scene/SceneObject.hpp>

class PlayerFactory {
	public:
		static gk::SceneObject create(u16 x, u16 y);

	private:
		static void checkCollisions(gk::SceneObject &player);
		static void scrollLevel(gk::SceneObject &player);
};

#endif // PLAYERFACTORY_HPP_
