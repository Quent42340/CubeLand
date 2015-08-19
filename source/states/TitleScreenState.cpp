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
#include "Mouse.hpp"
#include "TitleScreenState.hpp"

#include "LevelState.hpp"

TitleScreenState::TitleScreenState() {
	m_font.loadFromFile("fonts/terminus.ttf");
	
	m_title.setPosition(Application::screenWidth / 2 - m_title.getGlobalBounds().width / 2 - m_title.getLocalBounds().left, 40);
	
	m_playText.setPosition(Application::screenWidth / 2 - m_playText.getGlobalBounds().width / 2 - m_playText.getLocalBounds().left, 275);
	
	m_playRect.setPosition(m_playText.getGlobalBounds().left - 32, m_playText.getGlobalBounds().top - 8);
	m_playRect.setSize(sf::Vector2f(m_playText.getGlobalBounds().width + 64, m_playText.getGlobalBounds().height + 16));
	m_playRect.setFillColor(sf::Color(0, 0, 0, 0));
	m_playRect.setOutlineColor(sf::Color(255, 255, 255));
	m_playRect.setOutlineThickness(2);
}

void TitleScreenState::update() {
	sf::FloatRect playRectHitbox{m_playRect.getPosition(), m_playRect.getSize()};
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && Mouse::isInRect(playRectHitbox)) {
		ApplicationStateStack::getInstance().push<LevelState>(0);
	}
}

void TitleScreenState::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(m_title, states);
	
	target.draw(m_playText, states);
	target.draw(m_playRect, states);
}

