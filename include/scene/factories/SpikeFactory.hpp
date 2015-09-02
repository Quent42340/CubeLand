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

#include "SceneObject.hpp"

class SpikeFactory {
	public:
		static SceneObject create(u16 tileX, u16 tileY);
};

#endif // SPIKEFACTORY_HPP_
