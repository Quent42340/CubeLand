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
		LevelState(u16 levelID);
		
		void update();
		
		static sf::View view;
		
	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		
		u16 m_levelID = 0;
		
		Scene m_scene;
		
		SceneObject m_player;
};

#endif // LEVELSTATE_HPP_
