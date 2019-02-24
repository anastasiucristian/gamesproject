#include "Menu.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Menu::Menu(float width, float height){

  sf::Texture texture;
  if(!texture.loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\play_button.png")){
    //handle error
  }else{
  menu[0].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\play_button_selected.png");
  menu[1].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\settings_button.png");
  menu[2].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\exit_button.png");

  selectedItemIndex = 0;
  updateStance = 1;
}
};

Menu::~Menu(){

}

void Menu::draw(RenderWindow &window){
  sf::Sprite sprite;
  for(int i = 0 ; i < MAX_NUMBER_OF_ENTITIES ; i++){
    sprite.setTexture(menu[i]);
    sprite.setPosition(1920/4, 1080/(6-i));
    window.draw(sprite);
  }
}

void Menu::moveUp(){
  if(selectedItemIndex != 0){
    if(selectedItemIndex == 1){
      menu[selectedItemIndex].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\settings_button.png");
      menu[selectedItemIndex - 1].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\play_button_selected.png");
    }
    if(selectedItemIndex == 2){
      menu[selectedItemIndex].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\exit_button.png");
      menu[selectedItemIndex - 1].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\settings_button_selected.png");
    }
    selectedItemIndex--;
  }
}

void Menu::moveDown(){
  if(selectedItemIndex != 2){
    if(selectedItemIndex == 0){
      menu[selectedItemIndex].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\play_button.png");
      menu[selectedItemIndex + 1].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\settings_button_selected.png");
    }
    if(selectedItemIndex == 1){
      menu[selectedItemIndex].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\settings_button.png");
      menu[selectedItemIndex + 1].loadFromFile("C:\\Uni\\Games\\gamesproject\\res\\exit_button_selected.png");
    }
    selectedItemIndex++;
  }
}

void Menu::menuSelect(RenderWindow &window){
  if(selectedItemIndex == 0){
    updateStance = 3;
  } else if (selectedItemIndex == 1){
    updateStance = 2;
  } else {
    window.close();
  }
}
