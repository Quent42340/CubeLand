/*
 * =====================================================================================
 *
 *       Filename:  LevelEndState.cpp
 *
 *    Description:
 *
 *        Created:  29/08/2015 18:18:29
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/core/input/GamePad.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "Application.hpp"
#include "GameKey.hpp"
#include "LevelEndState.hpp"
#include "LevelListState.hpp"

LevelEndState::LevelEndState(gk::ApplicationState *parent, bool isLevelPassed) : gk::ApplicationState(parent) {
	m_isLevelPassed = isLevelPassed;

	m_okButton.setAction([]{
		gk::ApplicationStateStack::getInstance().push<LevelListState>();
	});

	m_okButton.setPosition(Application::screenWidth / 2 - m_okButton.width() / 2, 275);

	if(isLevelPassed) {
		m_rect.setFillColor(gk::Color(0, 0, 0, 127));
	} else {
		m_rect.setFillColor(gk::Color(63, 0, 0, 127));
	}

	m_rect.setSize(Application::screenWidth, Application::screenHeight);

	m_text.setString((m_isLevelPassed) ? "Level passed!" : "Failed!");

	gk::FloatRect textRect = gk::FloatRect(m_text.getLocalBounds());
	m_text.setOrigin(textRect.x + textRect.width  / 2,
	                 textRect.y + textRect.height / 2);

	m_text.setPosition(Application::screenWidth / 2, textRect.y + textRect.height / 2 + 50);
}

void LevelEndState::onEvent(const SDL_Event &event) {
	m_okButton.onEvent(event);
}

void LevelEndState::update() {
	m_okButton.update();

	if(gk::GamePad::isKeyPressedOnce(GameKey::Start)) {
		m_okButton.action();
	}
}

void LevelEndState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.draw(*m_parent, states);

	target.draw(m_rect, states);

	target.draw(m_text, states);

	target.draw(m_okButton, states);
}

