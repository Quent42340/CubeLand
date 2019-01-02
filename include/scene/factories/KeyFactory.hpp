/*
 * =====================================================================================
 *
 *       Filename:  KeyFactory.hpp
 *
 *    Description:
 *
 *        Created:  29/08/2015 18:45:49
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef KEYFACTORY_HPP_
#define KEYFACTORY_HPP_

#include <gk/scene/SceneObject.hpp>

class KeyFactory {
	public:
		static gk::SceneObject create(u16 tileX, u16 tileY, u16 lockID);
};

#endif // KEYFACTORY_HPP_
