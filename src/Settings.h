#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const std::string   LEVEL_DIRECTORY = "C:\\Users\\Mark Pereira\\Desktop\\GamesDevelopment\\Coursework\\gamesproject\\levels\\";
const std::string   RES_DIRECTORY = "C:\\Users\\Mark Pereira\\Desktop\\GamesDevelopment\\Coursework\\gamesproject\\res\\";
const std::string	SPRITE_DEFAULT = RES_DIRECTORY + "cld.png";
const std::string	SPRITE_CLOUDS = RES_DIRECTORY + "cld.png";
const std::string   SPRITE_BUTTON = RES_DIRECTORY + "MenuButton2.png";
const std::string   SPRITE_WINDOW = RES_DIRECTORY + "Window.png";//Incomplete
const std::string   SPRITE_LOADING = RES_DIRECTORY + "loading.jpg";


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

