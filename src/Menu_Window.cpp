#include "Menu.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

MenuWindow::~MenuWindow() {}

MenuWindow::MenuWindow()
{
	menu_texture->loadFromFile(SPRITE_WINDOW);
	this->baseSprite.setTexture(*menu_texture);
	

}


