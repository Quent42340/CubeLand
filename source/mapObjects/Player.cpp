/*
 * =====================================================================================
 *
 *       Filename:  Player.cpp
 *
 *    Description:  
 *
 *        Created:  10/08/2015 20:24:13
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <SFML/Window/Keyboard.hpp>

#include "Map.hpp"
#include "Player.hpp"

#include "Debug.hpp"

Player::Player() : Image("characters-player") {
	setPosition(16, 16);
}

void Player::checkCollisions() {
	// {12, 8,12,13},
	// { 4, 8, 4,13},
	// { 5, 5,10, 5},
	// { 5,15,10,15}
	// => (5, 5, 5, 10)
	// => (4, 8, 8, 5)
	// ................
	// ................
	// ................
	// ................
	// ................
	// ................
	// .....******.....
	// .....*....*.....
	// ....++++++++....
	// ....+*....*+....
	// ....+*....*+....
	// ....+*....*+....
	// ....++++++++....
	// .....*....*.....
	// .....******.....
	// ................
	// => (5, 8, 5, 6)
	// {10, 8,10,14},
	// { 5, 8, 5,14},
	// { 5, 8,10, 8},
	// { 5,14,10,14}
	float collisionMatrix[4][4] = {
		{m_vx + (float)width() - 1,                          0, m_vx + (float)width() - 1,        (float)height() - 1},
		{                     m_vx,                          0,                      m_vx,        (float)height() - 1},
		{                        0,                       m_vy,        (float)width() - 1,                       m_vy},
		{                        0, m_vy + (float)height() - 1,        (float)width() - 1, m_vy + (float)height() - 1}
	};
	
	for(u8 i = 0 ; i < 4 ; i++) {
		bool test;
		
		if(i == 0) {
			test = (m_vx > 0);
		}
		else if(i == 1) {
			test = (m_vx < 0);
		}
		else if(i == 2) {
			test = (m_vy < 0);
		}
		else if(i == 3) {
			test = (m_vy > 0);
		}
		
		if(test
		&& (!Map::currentMap->isPassable(x() + collisionMatrix[i][0], ceil(y() + collisionMatrix[i][1]))
		 || !Map::currentMap->isPassable(x() + collisionMatrix[i][2], ceil(y() + collisionMatrix[i][3])))) {
			if(i < 2) {
				m_vx = 0;
			}
			else if(i == 2) {
				m_vy = 0;
				
				m_jumpState = JumpState::Falling;
			}
			else if(i == 3) {
				m_vy = 0;
				
				m_jumpState = JumpState::Landed;
			}
		}
	}
}

void Player::update() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_vx = -m_speed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_vx = m_speed;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_vy == 0 && m_jumpState == JumpState::Landed) {
		m_vy = -m_jumpSpeed;
		
		m_jumpState = JumpState::Jumping;
	}
	
	m_vy += 0.075f; // Gravity
	
	if(m_vy > 0) m_jumpState = JumpState::Falling;
	
	if(m_vy > m_jumpSpeed) m_vy = m_jumpSpeed; // Max jump accel
	
	checkCollisions();
	
	move(m_vx, m_vy);
	
	m_vx = 0;
}

