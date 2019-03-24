/*
 * =====================================================================================
 *
 *       Filename:  LevelListState.cpp
 *
 *    Description:
 *
 *        Created:  19/08/2015 21:31:19
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/core/input/GamePad.hpp>

#include "Application.hpp"
#include "GameKey.hpp"
#include "LevelListState.hpp"
#include "LevelLoader.hpp"
#include "LevelState.hpp"

LevelListState::LevelListState() {
	m_title.setFont(gk::ResourceHandler::getInstance().get<sf::Font>("font-default"));
	m_title.setCharacterSize(80);
	m_title.setString("Choose a level");
	m_title.setPosition(Application::screenWidth / 2 - m_title.getLocalBounds().width / 2 - m_title.getLocalBounds().left, 0);

	m_rectangle.setPosition(30, 100);
	m_rectangle.setFillColor(sf::Color::Transparent);
	m_rectangle.setOutlineColor(sf::Color::White);
	m_rectangle.setOutlineThickness(2);

	m_cursor.setPosition(45, 110);
	m_cursor.setFillColor(sf::Color::Transparent);
	m_cursor.setOutlineColor(sf::Color::White);
	m_cursor.setOutlineThickness(2);
}

void LevelListState::onEvent(const sf::Event &event) {
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return
	&& gk::ResourceHandler::getInstance().has("level" + std::to_string(m_cursorPosition))) {
		gk::ApplicationStateStack::getInstance().push<LevelState>(m_cursorPosition);
	}
}

void LevelListState::update() {
	if(gk::GamePad::isKeyPressedOnce(GameKey::Up) && m_cursorPosition > 0) {
		m_cursorPosition--;
		m_cursor.move(0, -37);
	}

	if(gk::GamePad::isKeyPressedOnce(GameKey::Down) && m_cursorPosition < LevelLoader::levelsLoaded - 1) {
		m_cursorPosition++;
		m_cursor.move(0, 37);
	}
}

void LevelListState::drawLevel(u16 id, sf::RenderTarget &target, sf::RenderStates states) const {
	sf::Text label("Level " + std::to_string(id), gk::ResourceHandler::getInstance().get<sf::Font>("font-default"), 32);
	label.setPosition(50, 110 + id * (label.getLocalBounds().height + 5));

	target.draw(label, states);
}

void LevelListState::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	for(u16 i = 0 ; i < LevelLoader::levelsLoaded ; i++) {
		drawLevel(i, target, states);
	}

	target.draw(m_title, states);
	target.draw(m_rectangle, states);
	target.draw(m_cursor, states);
}

