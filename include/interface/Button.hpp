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

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

#include <gk/core/IntTypes.hpp>

class Button : public sf::Drawable, public sf::Transformable {
	using Action = std::function<void(void)>;

	public:
		Button(const char *text, u8 fontSize);

		void onEvent(const sf::Event &event);

		void update();

		void action() { m_action(); }

		void enable() { m_isActivated = true; }
		void disable() { m_isActivated = false; }

		float width() const { return m_rect.getSize().x + 4; }
		float height() const { return m_rect.getSize().y + 4; }

		void setAction(const Action &action) { m_action = action; }

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		Action m_action;

		bool m_isActivated = true;

		sf::RectangleShape m_rect;

		sf::Text m_text;
};

#endif // BUTTON_HPP_
