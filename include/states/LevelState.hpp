/*
 * =====================================================================================
 *
 *       Filename:  LevelState.hpp
 *
 *    Description:  
 *
 *        Created:  14/08/2015 18:03:09
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LEVELSTATE_HPP_
#define LEVELSTATE_HPP_

#include <SFML/Graphics/View.hpp>

#include "ApplicationState.hpp"
#include "Scene.hpp"

class LevelState : public ApplicationState {
	public:
		LevelState();
		
		void update();
		
		static sf::View view;
		
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		
		Scene m_scene;
};

#endif // LEVELSTATE_HPP_
