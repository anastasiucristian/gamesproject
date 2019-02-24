#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Settings.h"
#include "ChampionSelect.h"

using namespace sf;
using namespace std;

const int gameWidth = 1920;
const int gameHeight = 1080;
//using stance to navigate through windows
//stance 1 is main menu, the variable menu is used to manipulate it
int stance = 1;
Menu menu(gameWidth, gameHeight);

void Load(){
}

void Update(RenderWindow &window){
  // check and consume events
  Event event;
  while (window.pollEvent(event)){
    //if stance is 1 the window is in main menu so the next commands only work in the main menu
    if(stance == 1){
      //move down the menu
      //select swapping is donw on key release so it won't do it multiple times while the key is pressed (only once when the key is released)
      if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){menu.moveDown();}
      //move up the menu
      if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){menu.moveUp();}
      //select a menu option
      if (Keyboard::isKeyPressed(Keyboard::Enter)){menu.menuSelect(window); stance = menu.updateStance;}
    }

    //if in stance 2/3 (settings or champion select) esc is pressed it takes you back to the main menu
    if ((stance == 2 || stance == 3) && Keyboard::isKeyPressed(Keyboard::Escape)){stance = 1;}
  }
}

void Render(RenderWindow &window){
      //stance 1 is main menu, so menu is drawn
      if(stance == 1){menu.draw(window);}
      //stance 2 is settings menu so settings menu is drawn
      if(stance == 2){Settings settings(gameWidth,gameHeight); settings.draw(window);}
      //stance 3 is champion select window
      if(stance == 3){ChampionSelect championSelect(gameWidth,gameHeight); championSelect.draw(window);}
}

int main(){
  //RenderWindow window(VideoMode(gameWidth,gameHeight), "Danger", sf::Style::Fullscreen);
  RenderWindow window(VideoMode(gameWidth/2,gameHeight/2), "Squabble");
  while (window.isOpen()) {
    Load();
    window.clear();
    Update(window);
    Render(window);
    window.display();
  }

  return 0;
}
