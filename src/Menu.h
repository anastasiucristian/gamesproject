#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "ChampionSelect.h"

#define MAX_NUMBER_OF_ENTITIES 3

class Menu{
  public:
    Menu(float width, float height);
    ~Menu();

    int selectedItemIndex;
    void draw (sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    void menuSelect(sf::RenderWindow &window);
    int updateStance;

  private:
    sf::Texture menu[MAX_NUMBER_OF_ENTITIES];

};
