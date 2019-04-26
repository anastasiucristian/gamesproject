#pragma once
#include <SFML/Graphics.hpp>

const std::string LEVEL_DIRECTORY = "C:\\Uni\\Games\\gamesprojecta\\levels\\";
const std::string RES_DIRECTORY = "C:\\Uni\\Games\\gamesprojecta\\res\\"; //resource directory
const std::string	SPRITE_DEFAULT = RES_DIRECTORY + "Clouds.png";
const std::string	SPRITE_CLOUDS = RES_DIRECTORY + "BlueSky.png";
const std::string SPRITE_BUTTON = RES_DIRECTORY + "MenuButton.png";
const std::string SPRITE_WINDOW = RES_DIRECTORY + "Window.png";
const std::string SPRITE_DIRT = RES_DIRECTORY + "Dirt.png";
const std::string SPRITE_GRASSTOP = RES_DIRECTORY + "GrassTop.png";
const std::string SPRITE_EDGELEFT = RES_DIRECTORY + "EdgeLeft.png";
const std::string SPRITE_EDGERIGHT = RES_DIRECTORY + "EdgeRight.png";
//Incomplete

class Settings{
  public:
	Settings();
	~Settings();
	static Settings& getInstance() { static Settings instance; return instance; }

	void initializeFont();
	void initializeText();
	sf::Text getText(std::string);

  private:

	sf::Font font;
	sf::Text text;

};
