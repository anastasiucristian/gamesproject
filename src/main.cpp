#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Renderer.h"
#include "Scene.h"

using namespace sf;
using namespace std;

const int gameWidth = 1920;
const int gameHeight = 1080;

Scene_Menu scene_Menu;

//Scene * scene = &scene_CharSelect;
Scene * scene = &scene_Menu;


Game &sceneManager = Game::getManager();




void Load(){

	sceneManager.startGame(scene);
}

void Update() {

	// Reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();

	Event event;
	while (Renderer::instance()->pollEvent(event)) {
		if (event.type == Event::Closed) {Renderer::instance()->close(); return;}

	}
	sceneManager.UpdateScene();
}
void Render(){
	Renderer::instance()->clear();
	sceneManager.RenderScene();
	

}


int main(){
	
  static RenderWindow window(VideoMode(gameWidth / 2, gameHeight / 2), "Squabble");
  //sf::RenderWindow *w = new sf::RenderWindow(VideoMode(gameWidth, gameHeight), "Danger", sf::Style::Fullscreen);
  Renderer::initialise(window);
  Load();
  
  while (Renderer::instance()->isOpen()) {
	Update();
	Render();
	Renderer::instance()->display();

  }

  return 0;
}
