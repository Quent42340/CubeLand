/*
 * =====================================================================================
 *
 *       Filename:  DoorFactory.hpp
 *
 *    Description:  
 *
 *        Created:  01/09/2015 19:56:05
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DOORFACTORY_HPP_
#define DOORFACTORY_HPP_

#include "SceneObject.hpp"

class DoorFactory {
	public:
		static SceneObject create(u16 tileX, u16 tileY, u16 lockID);
};

#endif // DOORFACTORY_HPP_
