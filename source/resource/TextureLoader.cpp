/*
 * =====================================================================================
 *
 *       Filename:  TextureLoader.cpp
 *
 *    Description:  
 *
 *        Created:  14/01/2015 20:29:21
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <SFML/Graphics/Texture.hpp>

#include "TextureLoader.hpp"
#include "XMLFile.hpp"

void TextureLoader::load(const char *xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);
	
	XMLElement *textureElement = doc.FirstChildElement("textures").FirstChildElement("texture").ToElement();
	while(textureElement) {
		std::string folder = textureElement->Attribute("folder");
		std::string name = textureElement->Attribute("name");
		
		sf::Texture &texture = handler.add<sf::Texture>(folder + "-" + name);
		texture.loadFromFile("graphics/" + folder + "/" + name + ".png");
		
		textureElement = textureElement->NextSiblingElement("texture");
	}
}

