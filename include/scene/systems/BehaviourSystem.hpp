/*
 * =====================================================================================
 *
 *       Filename:  BehaviourSystem.hpp
 *
 *    Description:  
 *
 *        Created:  19/08/2015 17:54:47
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BEHAVIOURSYSTEM_HPP_
#define BEHAVIOURSYSTEM_HPP_

#include "SceneObject.hpp"

class BehaviourSystem {
	public:
		static void process(SceneObject &object);
};

#endif // BEHAVIOURSYSTEM_HPP_
