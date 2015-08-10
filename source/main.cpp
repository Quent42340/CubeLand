/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Created:  09/08/2015 11:42:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <SFML/Graphics.hpp>

int main(int, char*[]) {
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Window", sf::Style::Close);
	
	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
			
			window.clear();
			
			window.display();
		}
	}
	
	return 0;
}

