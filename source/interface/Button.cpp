/*
 * =====================================================================================
 *
 *       Filename:  Button.cpp
 *
 *    Description:
 *
 *        Created:  25/08/2015 18:42:18
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Button.hpp"
#include "Mouse.hpp"
#include "ResourceHandler.hpp"

Button::Button(const char *text, u8 fontSize) {
	m_text.setCharacterSize(fontSize);
	m_text.setFont(ResourceHandler::getInstance().get<sf::Font>("font-default"));
	m_text.setString(text);

	m_rect.setFillColor(sf::Color::Black);
	m_rect.setOutlineColor(sf::Color::White);
	m_rect.setOutlineThickness(2);
	m_rect.setPosition(2, 2); // Outline
	m_rect.setSize(sf::Vector2f(m_text.getGlobalBounds().width + 64, m_text.getGlobalBounds().height + 16));

	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width  / 2,
	                 textRect.top  + textRect.height / 2);

	m_text.setPosition(width() / 2, height() / 2);
}

void Button::update() {
	sf::FloatRect hitbox{getPosition().x, getPosition().y, width(), height()};

	if(Mouse::isInRect(hitbox)) {
		m_rect.setFillColor(sf::Color(100, 100, 100, 75));

		if(m_isActivated && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			m_action();
		}
	} else {
		m_rect.setFillColor(sf::Color::Black);
	}
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();

	target.draw(m_rect, states);

	target.draw(m_text, states);
}

