/*
 * =====================================================================================
 *
 *       Filename:  LockSystem.cpp
 *
 *    Description:
 *
 *        Created:  29/08/2015 19:03:16
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <map>

#include "LockComponent.hpp"
#include "LockSystem.hpp"

void LockSystem::update(gk::SceneObjectList &objects) {
	std::map<u16, bool> lockList;

	// Find which keys have been taken
	for(auto &it : objects) {
		if(it.has<LockComponent>()) {
			auto &lockComponent = it.get<LockComponent>();

			if(lockComponent.isKey()) {
				lockList.emplace(lockComponent.lockID(), lockComponent.isLocked());
			}
		}
	}

	// Update doors
	for(auto &it : objects) {
		if(it.has<LockComponent>()) {
			auto &lockComponent = it.get<LockComponent>();

			if(!lockComponent.isKey()
			&& lockList.find(lockComponent.lockID()) != lockList.end()) {
				if(lockList[lockComponent.lockID()]) {
					lockComponent.lock();
				} else {
					lockComponent.unlock();
				}
			}
		}
	}
}

