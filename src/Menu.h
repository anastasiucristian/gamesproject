#pragma once

#include "Settings.h"
#include "InteractiveSprite.h"

#include <SFML/Graphics.hpp>
#include <String.h>



const sf::Vector2f  MENU_POSITION = { 400,150 };
const float			MENU_INTERVAL = 30;

const std::string	MENU_FONT = RES_DIRECTORY + "fonts/MizoArial.ttf";
const sf::Color     MENU_FONT_COLOUR = sf::Color::Black;
const int			MENU_CHAR_SIZE = 30;

const std::string	SPRITE_CLOUDS = RES_DIRECTORY + "Clouds.png";
const std::string   SPRITE_BUTTON = RES_DIRECTORY + "MenuButton.png";

class MenuButton
{
public:
	MenuButton();
	MenuButton(sf::Texture, sf::Text);
	~MenuButton();

	sf::Sprite baseSprite;
	sf::Texture baseTexture;
	sf::Text text;

	//void onHover(sf::RenderWindow &window) override;
};


class MenuHandler
{
public:
	MenuHandler();
	void Update(sf::RenderWindow &window);

private:
	//Scene_Menu * menu;
	void handleButtonHover();
};






