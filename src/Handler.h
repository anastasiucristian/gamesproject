#pragma once

#ifndef Scene_H
#define Scene_H

#include <SFML/Graphics.hpp>

class Scene_Menu;
//Handles the various mechanics happening on the Main Menu
class MainMenuHandler
{
public:
	MainMenuHandler(Scene_Menu &menu);
	void Update(sf::RenderWindow &window);

private:

	Scene_Menu * scene_menu;
	void handleButtonHover(sf::Vector2f mousePos , sf::RenderWindow &window);
	void handleButtonClick(sf::Vector2f mousePos , sf::RenderWindow &window);
};

#endif



