#include <SFML/Graphics.hpp>
#include <iostream>

#include "Menu.h"
#include "Settings.h"
#include "Scene.h"

using namespace sf;
using namespace std;

const int gameWidth = 1920;
const int gameHeight = 1080;

Scene_Menu scene_Menu;

void Load(RenderWindow &window){


	scene_Menu.Load(window);


}

void Update(RenderWindow &window) {
	
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {window.close(); return;}

	}
}
void Render(RenderWindow &window){

	scene_Menu.Render(window);


	
}

int main(){
  //RenderWindow window(VideoMode(gameWidth,gameHeight), "Danger", sf::Style::Fullscreen);
  RenderWindow window(VideoMode(gameWidth/2,gameHeight/2), "Squabble");

  Load(window);
  while (window.isOpen()) {
	window.clear();
    Update(window);
    Render(window);
    window.display();
  }

  return 0;
}
