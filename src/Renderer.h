#pragma once
#include <SFML/Graphics.hpp>


namespace Renderer {
	//void initialise(sf::RenderWindow&);
	
	void initialise(sf::RenderWindow& r);
	sf::RenderWindow* instance();

	void drawText(sf::Text);

}; // namespace Renderer
