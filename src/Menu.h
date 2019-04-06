#pragma once
#include "Settings.h"
#include "InteractiveSprite.h"
#include <SFML/Graphics.hpp>
#include <String.h>

// Set the Menu Options here
const sf::Vector2f  MENU_POSITION = { 400,150 };
const float			MENU_INTERVAL = 30;

const std::string	MENU_FONT = RES_DIRECTORY + "fonts/MizoArial.ttf";
const sf::Color     MENU_FONT_COLOUR = sf::Color::Black;
const int			MENU_CHAR_SIZE = 30;



class MenuButton : public InteractHandler
{
public:
	MenuButton();
	MenuButton(sf::Texture, sf::Text);
	~MenuButton();

	sf::Sprite baseSprite;
	sf::Texture baseTexture;
	sf::Text text;

private:
	void onHover() override;
	void offHover() override;
	void onClick() override;

};

class MenuWindow
{
public:
	MenuWindow();
	MenuWindow(int x, int y, int width, int height);
	~MenuWindow();
	
	
private:
	sf::Text text;
	sf::Sprite baseSprite;
	sf::Texture baseTexture;
	void drawWindow();

};









