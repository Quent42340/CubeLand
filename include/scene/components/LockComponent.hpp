/*
 * =====================================================================================
 *
 *       Filename:  LockComponent.hpp
 *
 *    Description:
 *
 *        Created:  29/08/2015 18:56:03
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LOCKCOMPONENT_HPP_
#define LOCKCOMPONENT_HPP_

#include "IntTypes.hpp"

class LockComponent {
	public:
		LockComponent(u16 lockID, bool isKey)
			: m_isKey(isKey), m_lockID(lockID) {}

		void lock()   { m_isLocked = true;  }
		void unlock() { m_isLocked = false; }

		bool isKey() const { return m_isKey; }

		bool isLocked() const { return m_isLocked; }

		u16 lockID() const { return m_lockID; }

	private:
		bool m_isKey;

		bool m_isLocked = true;

		u16 m_lockID;
};

#endif // LOCKCOMPONENT_HPP_
