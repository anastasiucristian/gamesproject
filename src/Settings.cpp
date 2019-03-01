#include "Menu.h"
#include "Settings.h"

using namespace sf;
Settings& Settings::getInstance() { static Settings instance; return instance; }

Settings::~Settings() {}
Settings::Settings() 
{
	initializeFont();
	initializeText();
}

void Settings::initializeFont()
{
	sf::Font font;
	if (!font.loadFromFile(MENU_FONT))
	{
		printf("Failed to load font\n");
	}
	else
	{
		printf("Font loaded successfully\n");
	}
	this->font = font;

}

void Settings::initializeText()
{
	text.setFont(this->font);
	text.setPosition(50, 50);
	text.setFillColor(MENU_FONT_COLOUR);
	text.setCharacterSize(MENU_CHAR_SIZE);
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}


sf::Text Settings::getText(std::string stringText)
{
	text.setString(stringText);
	return text;	
}

