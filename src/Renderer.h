#pragma once
#include <SFML/Graphics.hpp>

//Renderer: Provides access to the game Renderer
namespace Renderer {
	//void initialise(sf::RenderWindow&);
	
	void initialise(sf::RenderWindow& r);
	sf::RenderWindow* instance();

	bool isPaused();
	void pause();
	void resume();
	
}; // namespace Renderer
