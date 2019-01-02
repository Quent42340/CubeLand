/*
 * =====================================================================================
 *
 *       Filename:  TitleScreenState.cpp
 *
 *    Description:
 *
 *        Created:  19/08/2015 19:09:42
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/core/Mouse.hpp>
#include <gk/core/input/GamePad.hpp>

#include "Application.hpp"
#include "GameKey.hpp"
#include "TitleScreenState.hpp"

#include "LevelState.hpp"
#include "LevelListState.hpp"

TitleScreenState::TitleScreenState() {
	m_title.setText("CubeLand");
	m_title.setFont(m_font);
	m_title.setCharacterSize(128);
	m_title.setPosition(Application::screenWidth / 2 - m_title.getLocalBounds().width / 2 - m_title.getLocalBounds().x, 40);

	m_playButton.setAction([]{
		gk::ApplicationStateStack::getInstance().push<LevelListState>();
	});

	m_playButton.setPosition(Application::screenWidth / 2 - m_playButton.width() / 2, 275);
}

void TitleScreenState::onEvent(const SDL_Event &event) {
	m_playButton.onEvent(event);

	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
		m_playButton.action();
	}
}

void TitleScreenState::update() {
	m_playButton.update();
}

void TitleScreenState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.draw(m_title, states);

	target.draw(m_playButton, states);
}

