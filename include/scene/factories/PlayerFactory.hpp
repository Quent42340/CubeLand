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

#include "SceneObject.hpp"

class PlayerFactory {
	public:
		static SceneObject create(u16 x, u16 y);
};

#endif // PLAYERFACTORY_HPP_
