#include "Menu.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Settings::Settings(float width, float height){

  sf::Texture texture;
  if(!texture.loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\settings_one.png")){
    //handle error
  }else{
  menu[0].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\settings_one.png");
  menu[1].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\settings_one.png");
  menu[2].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\settings_one.png");

  selectedItemIndex = 0;
}
};

Settings::~Settings(){

}

void Settings::draw(RenderWindow &window){
  sf::Sprite sprite;
  for(int i = 0 ; i < 3 ; i++){
    sprite.setTexture(menu[i]);
    sprite.setPosition(1920/4, 1080/(6-i));
    window.draw(sprite);
  }
}

void Settings::moveUp(){

}

void Settings::moveDown(){

}

void Settings::settingsSelect(RenderWindow &window){

}
