#pragma once
#include "Settings.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>

/*
Level.h

Provides construction Methods of game Levels (Buttons, Windows, etc.)

Author:  Cristian Anastasiu 
*/

class Level{
public:
	Level();
	~Level();
	void render(); //method that draws the whole level
	void drawBackground(); //method that draws the background
	void drawLevel(); //method that draws the map with tiles
	void loadLevel(); //method that sets up the map variable from a level setup text file
	sf::Vector2f getPlayer1(); //method that retreives the player1 start point
	sf::Vector2f getPlayer2(); //method that retreives the player2 start point
	void removePlayers(); //method that removes the player start points
	bool tileSolid(sf::Vector2f pos); //method that checks if the tile under the player is solid or not
protected:
	//variables for texture locations
	std::string _levelPath = LEVEL_DIRECTORY; //resources path of each level (RES_DIRECTORY+level name)
	char map[31][18];
};
