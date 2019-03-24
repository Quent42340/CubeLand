/*
 * =====================================================================================
 *
 *       Filename:  Text.cpp
 *
 *    Description:
 *
 *        Created:  08/05/2016 18:34:49
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "Text.hpp"

Text::Text(const char *fontName, unsigned int characterSize) {
	setFont(gk::ResourceHandler::getInstance().get<sf::Font>(fontName));
	setCharacterSize(characterSize);
}

Text::Text(const char *fontName, const std::string &text, unsigned int characterSize) : Text(fontName, characterSize) {
	setString(text);
}

void Text::setMaxWidth(u16 width) {
	float scaleX = width / getLocalBounds().width;
	setScale(scaleX < 1.0f ? scaleX : 1.0f, getScale().y);
}

