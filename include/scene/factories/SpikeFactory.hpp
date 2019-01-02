/*
 * =====================================================================================
 *
 *       Filename:  SpikeFactory.hpp
 *
 *    Description:
 *
 *        Created:  02/09/2015 21:33:37
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPIKEFACTORY_HPP_
#define SPIKEFACTORY_HPP_

#include <gk/scene/SceneObject.hpp>

class SpikeFactory {
	public:
		static gk::SceneObject create(u16 tileX, u16 tileY);

	private:
		static void action(gk::SceneObject &spike, gk::SceneObject &object, bool isInCollision);
};

#endif // SPIKEFACTORY_HPP_
