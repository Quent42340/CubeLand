/*
 * =====================================================================================
 *
 *       Filename:  GamePad.cpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 13:46:38
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "GamePad.hpp"

InputHandler *GamePad::inputHandler = nullptr;

bool GamePad::isKeyPressed(GameKey key) {
	return (inputHandler) ? inputHandler->isKeyPressed(key) : false;
}

bool GamePad::isKeyPressedOnce(GameKey key) {
	return (inputHandler) ? inputHandler->isKeyPressedOnce(key) : false;
}

bool GamePad::isKeyPressedWithDelay(GameKey key, u16 delay) {
	return (inputHandler) ? inputHandler->isKeyPressedWithDelay(key, delay) : false;
}

