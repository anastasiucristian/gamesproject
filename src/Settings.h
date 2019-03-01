#pragma once
#include <SFML/Graphics.hpp>

const std::string RES_DIRECTORY = "C:\\Users\\Mark Pereira\\Desktop\\GamesDevelopment\\Coursework\\gamesproject\\res\\";

class Settings{
  public:
	Settings();
	~Settings();
	static Settings& getInstance();

	void initializeFont();
	void initializeText();
	sf::Text getText(std::string);

  private:
	 
	sf::Font font;
	sf::Text text;

};
