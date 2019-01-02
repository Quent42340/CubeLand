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
#include <gk/core/Mouse.hpp>
#include <gk/gl/RenderTarget.hpp>
#include <gk/gui/Font.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "Button.hpp"

Button::Button(const char *text, u8 fontSize) {
	m_text.setCharacterSize(fontSize);
	m_text.setFont(gk::ResourceHandler::getInstance().get<gk::Font>("font-default"));
	m_text.setText(text);

	m_rect.setColor(gk::Color::Black);
	// FIXME
	// m_rect.setOutlineColor(gk::Color::White);
	// m_rect.setOutlineThickness(2);
	m_rect.setPosition(2, 2); // Outline
	m_rect.setSize(m_text.getLocalBounds().width + 64, m_text.getLocalBounds().height + 16);

	gk::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.x + textRect.width  / 2,
	                 textRect.y  + textRect.height / 2);

	m_text.setPosition(width() / 2, height() / 2);
}

void Button::onEvent(const SDL_Event &event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if(m_isActivated && event.button.button == SDL_BUTTON_LEFT) {
			m_action();
		}
	}
}

void Button::update() {
	gk::FloatRect hitbox{getPosition().x, getPosition().y, width(), height()};

	if(gk::Mouse::isInRect(hitbox)) {
		m_rect.setColor(gk::Color(100, 100, 100, 75));
	} else {
		m_rect.setColor(gk::Color::Black);
	}
}

void Button::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	states.transform *= getTransform();

	target.draw(m_rect, states);

	target.draw(m_text, states);
}

