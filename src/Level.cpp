#include "Game.h"
#include "Level.h"
#include "Settings.h"
#include "Renderer.h"
#include <fstream>
#include <string>

using namespace std;
using namespace sf;

Level::Level(){loadLevel();}
Level::~Level(){}

void Level::render(){

	drawBackground();
	drawLevel();
}

void Level::drawLevel() {
	//texture will be used to draw everything
	sf::Texture *texture = new sf::Texture();
	
	//going throught the map matrix and drawing the tiles
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 17; j++) {
			if (map[i][j] == 'B') {
				texture->loadFromFile(_levelPath + "Dirt.png");
				sf::Sprite drawablee(*texture);
				drawablee.setPosition(i * 64, j * 64);
				
				//Game::getManager().getRunningScene()->pushTexdSprite(drawablee, texture);
				Renderer::instance()->draw(drawablee);
			}
			else if (map[i][j] == 'G') {
				texture->loadFromFile(_levelPath + "GrassTop.png");
				sf::Sprite drawablee(*texture);
				drawablee.setPosition(i * 64, j * 64);
				Renderer::instance()->draw(drawablee);
			}else if (map[i][j] == 'L') {
				texture->loadFromFile(_levelPath + "EdgeLeft.png");
				sf::Sprite drawablee(*texture);
				drawablee.setPosition(i * 64, j * 64);
				Renderer::instance()->draw(drawablee);
			}else if (map[i][j] == 'R') {
				texture->loadFromFile(_levelPath + "EdgeRight.png");
				sf::Sprite drawablee(*texture);
				drawablee.setPosition(i * 64, j * 64);
				Renderer::instance()->draw(drawablee);
			}else if (map[i][j] == 'r') {
				texture->loadFromFile(_levelPath + "DirtRight.png");
				sf::Sprite drawablee(*texture);
				drawablee.setPosition(i * 64, j * 64);
				Renderer::instance()->draw(drawablee);
			}else if (map[i][j] == 'l') {
				texture->loadFromFile(_levelPath + "DirtLeft.png");
				sf::Sprite drawablee(*texture);
				drawablee.setPosition(i * 64, j * 64);
				Renderer::instance()->draw(drawablee);
			}
		}
	}
	//deleting the variables when done
	delete texture;
}

void Level::drawBackground(){
	
  sf::Texture *backgroundTex = new sf::Texture();
  backgroundTex->loadFromFile(_levelPath + "Background.png");
  sf::Sprite drawable(*backgroundTex);
  Renderer::instance()->draw(drawable);
  delete backgroundTex;
  
  /*
  sf::Texture *backgroundTex = new sf::Texture();
  backgroundTex->loadFromFile(_levelPath + "Background.png");

  
  Game::getManager().getRunningScene()->setBackground(*backgroundTex);
  delete backgroundTex;
  */
 
}

void Level::loadLevel(){
	//initializing the map matrix with a so the unused tiles are easy to find (a for air)
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 19; j++) {
			map[i][j] = 'a';
		}
	}

  std::string levelPath = LEVEL_DIRECTORY + "level1.txt";
  ifstream f(levelPath);
  //first 3 lines will be paths for the background, top and bottom texture
  string line;
  getline(f,_levelPath);
  //finalising the level path setup
  _levelPath = RES_DIRECTORY + _levelPath + "\\";
  //read the rest of the file, line by line. next lines will bee x-coord y-coord, tile type (g-grass, b-block)	
  while(!f.eof()){
    getline(f,line);	
    int x, y;
	//parsing the words of each line
	char cline[100];
	strcpy(cline, line.c_str());
	//second word is the y coordinate
    char *token = strtok(cline," ");
	x = atoi(token);
	//second word is the y coordinate
	token = strtok(NULL," ");	
	y = atoi(token);
	token = strtok(NULL, " ");
	//third word is the type of block (G for grass, B for block)
	//grass is the block that is drawn at the top, and block anything that's under
	map[x][y] = token[0];
  }

  f.close();
}

sf::Vector2f Level::getPlayer1() {
	sf::Vector2f pos;
	int x, y;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 17; j++) {
			if (Level::map[i][j] == 'F') {
				x = i; y = j;
			}
		}
	}
	pos.x = x*64;
	pos.y = y*64;
	return pos;
}

sf::Vector2f Level::getPlayer2() {
	sf::Vector2f pos;
	int x, y;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 17; j++) {
			if (Level::map[i][j] == 'S') {
				x = i; y = j;
			}
		}
	}
	pos.x = x * 64;
	pos.y = y * 64;
	return pos;
}

void Level::removePlayers() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 17; j++) {
			if (map[i][j] == 'S' || map[i][j] == 'F') {
				map[i][j] = 'a';
			}
		}
	}
}

bool Level::tileSolid(sf::Vector2f pos) {
	int x, y;
	x = pos.x / 64;
	y = pos.y / 64 +1;
	if (map[x][y] != 'a' || map[x + 1][y] != 'a')
		return true;

	return false;
}
