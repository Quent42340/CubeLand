/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:
 *
 *        Created:  12/08/2015 19:44:00
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/input/GamePad.hpp>
#include <gk/resource/TextureLoader.hpp>
#include <gk/resource/TilesetLoader.hpp>

#include "Application.hpp"
#include "TitleScreenState.hpp"

#include "LevelLoader.hpp"

#include "LevelEndState.hpp"
#include "LevelState.hpp"
#include "LevelListState.hpp"

void Application::init() {
	gk::CoreApplication::init();

	createWindow(screenWidth, screenHeight, "CubeLand");

	m_shader.loadFromFile("resources/shaders/game.v.glsl", "resources/shaders/game.f.glsl");
	m_renderStates.shader = &m_shader;
	m_renderStates.vertexAttributes = gk::VertexAttribute::Only2d;

	m_resourceHandler.loadConfigFile<gk::TextureLoader>("resources/config/textures.xml");
	m_resourceHandler.loadConfigFile<gk::TilesetLoader>("resources/config/tilesets.xml");
	m_resourceHandler.loadConfigFile<LevelLoader>("resources/config/levels.xml");
	m_resourceHandler.add<gk::Font>("font-default", "resources/fonts/terminus.ttf");

	m_keyboardHandler.loadKeysFromFile("resources/config/keys.xml");
	gk::GamePad::init(m_keyboardHandler);

	m_stateStack.push<TitleScreenState>();
	// m_stateStack.push<LevelListState>();
	// m_stateStack.push<LevelState>(0);
}

void Application::onEvent(const SDL_Event &event) {
	gk::CoreApplication::onEvent(event);

	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
		m_window.close();
	}
}

