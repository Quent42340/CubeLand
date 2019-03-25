/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:
 *
 *        Created:  12/08/2015 19:43:33
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <gk/core/CoreApplication.hpp>
#include <gk/core/input/KeyboardHandler.hpp>

class Application : public gk::CoreApplication {
	public:
		Application(int argc, char **argv) : gk::CoreApplication(argc, argv) {}

		void init() override;

		const static u16 screenWidth = 640;
		const static u16 screenHeight = 480;

	private:
		void onEvent(const sf::Event &event) override;

		gk::KeyboardHandler m_keyboardHandler;
};

#endif // APPLICATION_HPP_
