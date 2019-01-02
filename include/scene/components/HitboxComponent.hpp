/*
 * =====================================================================================
 *
 *       Filename:  HitboxComponent.hpp
 *
 *    Description:
 *
 *        Created:  09/05/2015 01:54:00
 *
 *         Author:  Jonathan Péclat, <peclatj@bluewin.ch>
 *
 * =====================================================================================
 */
#ifndef HITBOXCOMPONENT_HPP_
#define HITBOXCOMPONENT_HPP_

#include <vector>

#include <gk/core/Rect.hpp>
#include <gk/system/Exception.hpp>

class HitboxComponent {
	public:
		HitboxComponent(s8 currentHitboxID = 0)
			: m_currentHitboxID(currentHitboxID) {}

		HitboxComponent(s16 x, s16 y, u16 width, u16 height) : HitboxComponent(0) {
			addHitbox(x, y, width, height);
		}

		void addHitbox(s16 x, s16 y, u16 width, u16 height) {
			m_hitboxes.emplace_back(x, y, width, height);
		}

		const gk::FloatRect *currentHitbox() const {
			if(m_currentHitboxID >= 0 && m_currentHitboxID < (s16)m_hitboxes.size()) {
				return &m_hitboxes[m_currentHitboxID];
			} else {
				return nullptr;
			}
		}

		void setCurrentHitbox(u8 id) {
			if(id < m_hitboxes.size()) {
				m_currentHitboxID = id;
			} else {
				throw EXCEPTION("Hitbox ID out of range:", (s16)id, "| Array size:", m_hitboxes.size());
			}
		}

		void resetCurrentHitbox() { m_currentHitboxID = -1; }

	private:
		s8 m_currentHitboxID = -1;

		std::vector<gk::FloatRect> m_hitboxes;
};

#endif // HITBOXCOMPONENT_HPP_
