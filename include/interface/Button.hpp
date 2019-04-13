/*
 * =====================================================================================
 *
 *       Filename:  Button.hpp
 *
 *    Description:
 *
 *        Created:  25/08/2015 18:42:09
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <functional>

#include <gk/core/IntTypes.hpp>
#include <gk/graphics/RectangleShape.hpp>
#include <gk/graphics/Text.hpp>

class Button : public gk::Drawable, public gk::Transformable {
	using Action = std::function<void(void)>;

	public:
		Button(const char *text, u8 fontSize);

		void onEvent(const SDL_Event &event);

		void update();

		void action() { m_action(); }

		void enable() { m_isActivated = true; }
		void disable() { m_isActivated = false; }

		float width() const { return m_rect.getSize().x + 4; }
		float height() const { return m_rect.getSize().y + 4; }

		void setAction(const Action &action) { m_action = action; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		Action m_action;

		bool m_isActivated = true;

		gk::RectangleShape m_rect;

		gk::Text m_text;
};

#endif // BUTTON_HPP_
