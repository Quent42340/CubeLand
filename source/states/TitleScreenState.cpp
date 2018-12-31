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
#include "Application.hpp"
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "Mouse.hpp"
#include "TitleScreenState.hpp"

#include "LevelState.hpp"
#include "LevelListState.hpp"

TitleScreenState::TitleScreenState() {
	m_font.loadFromFile("fonts/terminus.ttf");

	m_title.setPosition(Application::screenWidth / 2 - m_title.getGlobalBounds().width / 2 - m_title.getLocalBounds().left, 40);

	m_playButton.setAction([]{
		ApplicationStateStack::getInstance().push<LevelListState>();
	});

	m_playButton.setPosition(Application::screenWidth / 2 - m_playButton.width() / 2, 275);
}

void TitleScreenState::update() {
	m_playButton.update();

	if(GamePad::isKeyPressedOnce(GameKey::Start)) {
		m_playButton.action();
	}
}

void TitleScreenState::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(m_title, states);

	target.draw(m_playButton, states);
}

