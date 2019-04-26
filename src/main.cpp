#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Settings.h"
#include "Scene.h"
#include "Game.h"

using namespace sf;
using namespace std;

const int gameWidth = 1920;
const int gameHeight = 1080;

Scene_Arena scene_Menu;
Scene * scene = &scene_Menu;

Game sceneManager = Game::getManager();

void Load(sf::RenderWindow &window){
	sceneManager.startGame(window, scene);
}

void Update(sf::RenderWindow &window) {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {window.close(); return;}
	}
	sceneManager.UpdateScene();
}

void Render(sf::RenderWindow &window){
	window.clear();
	sceneManager.RenderScene();
}


int main(){
  //RenderWindow window(VideoMode(gameWidth / 2, gameHeight / 2), "Squabble");
	//use the one below for fullscreen once the game is done, windowed is better for testing
	sf::RenderWindow window(VideoMode(gameWidth, gameHeight), "Squabble", sf::Style::Fullscreen);

  Load(window);
  while (window.isOpen()) {
		Update(window);
		Render(window);
		window.display();
  }
  return 0;
}
