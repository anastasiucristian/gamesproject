#pragma once
#include "InteractiveSprite.h"
#include "Settings.h"
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

	void setLabel(int label) { this->label = label; };
	int getLabel() { return label; };

	sf::Sprite baseSprite;
	sf::Texture baseTexture;
	sf::Text text;



private:
	void onHover() override;
	void offHover() override;
	void onClick() override;
	//void press_K();

	int label;

};

class MenuWindow
{
public:
	MenuWindow();
	~MenuWindow();
	
	//Set Window Texture:
	sf::Texture * menu_texture = new sf::Texture();

	sf::Sprite baseSprite;
	sf::Texture baseTexture;


private:
	std::string text;


};









