#pragma once

#ifndef Scene_H
#define Scene_H

#include <SFML/Graphics.hpp>

enum menuItems
{
	play,
	settings
};

class Scene_Menu;
//Handles the various mechanics happening on the Main Menu
class MainMenuHandler
{
public:
	
	MainMenuHandler(Scene_Menu &menu) { this->scene_menu = &menu; }
	void Update();

private:

	Scene_Menu * scene_menu;
	void handleButtonHover(sf::Vector2i mousePos);
	void handleButtonClick(sf::Vector2i mousePos);
};

#endif



